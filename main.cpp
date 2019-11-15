#include "graphics.hpp"

#include <algorithm>
#include <array>
#include <cmath>
#include <vector>

int main(int argc, char* argv[])
{
  Terminal term;
  std::uint32_t x = term.width / 2, y = term.height / 2;
  std::vector<std::array<std::uint16_t, 2>> opts;
  std::uint32_t ev = 0;
  term(x, y) = Char(0x265e, BOLD);
  term.swap();
  int state = 0;
  while (get_key(ev) != 27) {
    ev = poll_events(-1);
    if (state == 0) {
      if (is_mouse(ev) && get_x(ev) == x && get_y(ev) == y && get_state(ev)) {
        state = 1;
        term(x, y) = Char(0xe25f, BOLD | BG_LIGHT_GREEN);
        for (int a = -2; a <= 2; ++a) {
          if (a == 0)
            continue;
          for (int b = -2; b <= 2; ++b) {
            if (std::fabs(b) == std::fabs(a) || b == 0)
              continue;
            opts.push_back({ (std::uint16_t)(x + a), (std::uint16_t)(y + b) });
            term(x + a, y + b) = Char(' ', BG_YELLOW);
          }
        }
        term.swap();
      }
    } else if (state == 1) {
      if (is_mouse(ev)) {
        std::array<std::uint16_t, 2> pos { get_x(ev), get_y(ev) };
        if (std::find(opts.begin(), opts.end(), pos) != opts.end()) {
          x = pos[0];
          y = pos[1];
          term.clear();
          term(x, y) = Char(0xe25f, BOLD);
          term.swap();
          state = 0;
          opts.clear();
        }
      }
    }
  }
  return 0;
}
