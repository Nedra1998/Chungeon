#include "graphics.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

#define KING 0x265A
#define QUEEN 0x265B
#define ROOK 0x265C
#define BISHOP 0x265D
#define KNIGHT 0x265E
#define PAWN 0x265F

#define BLOCK 0x2588

std::vector<std::vector<int>> generate_board(int size)
{
  auto board = std::vector<std::vector<int>>(size, std::vector<int>(size, -1));
  for(std::size_t x = (size - 8) / 2; x < (size + 8) / 2; ++x){
    for(std::size_t y = 1; y < 9; ++y){
      board[x - size % 2][y] = 0;
      board[x][size - y - 1] = 0;
    }
  }
  for(std::size_t  x = (size - 4) / 2; x < (size + 4) / 2; ++x){
    for(std::size_t y = (size - 4) / 2; y < (size + 4) / 2; ++y){
      board[x][y] = 0;
    }
  }
  return board;
}
void display_board(const std::vector<std::vector<int>>& board, Terminal& term)
{
  term.clear();
  std::uint32_t x_offset = (term.width - 2 * board.size()) / 2;
  std::uint32_t y_offset = (term.height - board[0].size()) / 2;
  for (std::size_t x = 0; x < board.size(); ++x) {
    for (std::size_t y = 0; y < board[0].size(); ++y) {
      switch (board[x][y]) {
      case -1:
        term(x_offset + 2*x, y_offset + y) = Char(' ', BLACK | BG_BLACK);
        term(x_offset + 2*x+1, y_offset + y) = Char(' ', BLACK | BG_BLACK);
        break;
      case 0:
        if((x+y) % 2 == 0) {
          term(x_offset + 2*x, y_offset + y) = Char(' ', BG_LIGHT_GREY);
          term(x_offset + 2*x+1, y_offset + y) = Char(' ', BG_LIGHT_GREY);
        } else {
          term(x_offset + 2*x, y_offset + y) = Char(' ', BG_WHITE);
          term(x_offset + 2*x+1, y_offset + y) = Char(' ', BG_WHITE);
        }
        break;
      };
    }
  }
}

int main(int argc, char* argv[])
{
  Terminal term;
  std::uint32_t ev = 0;
  int state = 0;
  auto board = generate_board(std::min(term.width / 2, term.height));
  display_board(board, term);
  term.swap();
  while (get_key(ev) != 27) {
    ev = poll_events(-1);
    display_board(board, term);
    term.swap();
  }
  return 0;
}
