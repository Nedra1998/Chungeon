#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

#include <cstdint>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <vector>
static std::queue<std::uint32_t> event_queue_;

enum Attrs {
  BOLD = 1 << 0,
  FAINT = 1 << 1,
  ITALIC = 1 << 2,
  UNDERLINE = 1 << 3,
  BLINK = 1 << 4,
  FG_OFFSET = 5,
  FOREGROUND = 1 << 13,
  BG_OFFSET = 14,
  BACKGROUND = 1 << 22,
};
enum Colors {
  BLACK = (0 << FG_OFFSET) | FOREGROUND,
  RED = (1 << FG_OFFSET) | FOREGROUND,
  GREEN = (2 << FG_OFFSET) | FOREGROUND,
  YELLOW = (3 << FG_OFFSET) | FOREGROUND,
  BLUE = (4 << FG_OFFSET) | FOREGROUND,
  MAGENTA = (5 << FG_OFFSET) | FOREGROUND,
  CYAN = (6 << FG_OFFSET) | FOREGROUND,
  LIGHT_GREY = (7 << FG_OFFSET) | FOREGROUND,
  GREY = (8 << FG_OFFSET) | FOREGROUND,
  LIGHT_RED = (9 << FG_OFFSET) | FOREGROUND,
  LIGHT_GREEN = (10 << FG_OFFSET) | FOREGROUND,
  LIGHT_YELLOW = (11 << FG_OFFSET) | FOREGROUND,
  LIGHT_BLUE = (12 << FG_OFFSET) | FOREGROUND,
  LIGHT_MAGENTA = (13 << FG_OFFSET) | FOREGROUND,
  LIGHT_CYAN = (14 << FG_OFFSET) | FOREGROUND,
  WHITE = (15 << FG_OFFSET) | FOREGROUND,
  BG_BLACK = (0 << BG_OFFSET) | BACKGROUND,
  BG_RED = (1 << BG_OFFSET) | BACKGROUND,
  BG_GREEN = (2 << BG_OFFSET) | BACKGROUND,
  BG_YELLOW = (3 << BG_OFFSET) | BACKGROUND,
  BG_BLUE = (4 << BG_OFFSET) | BACKGROUND,
  BG_MAGENTA = (5 << BG_OFFSET) | BACKGROUND,
  BG_CYAN = (6 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_GREY = (7 << BG_OFFSET) | BACKGROUND,
  BG_GREY = (8 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_RED = (9 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_GREEN = (10 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_YELLOW = (11 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_BLUE = (12 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_MAGENTA = (13 << BG_OFFSET) | BACKGROUND,
  BG_LIGHT_CYAN = (BG_OFFSET << BG_OFFSET) | BACKGROUND,
  BG_WHITE = (15 << BG_OFFSET) | BACKGROUND,
};
enum Event {
  KEYBOARD = (1 << 0),
  MOUSE = (1 << 1),
  KEY_OFFSET = 2,
  MB = (1 << 2),
  MB_STATE = (1 << 3),
  MX_OFFSET = 4,
  MY_OFFSET = 13,
};
enum KeyCodes {
  KEY_ERR = 0, //!< Invalid Key/No Key
  KEY_ENTER = 10,
  KEY_ESCAPE = 27,
  KEY_SPACE = 32,
  KEY_EXCLAMATION_MARK = 33,
  KEY_QUOTATION_MARK = 34,
  KEY_NUMBER_SIGN = 35,
  KEY_DOLLAR_SIGN = 36,
  KEY_PERCENT_SIGN = 37,
  KEY_AMPERSAND = 38,
  KEY_APOSTROPHE = 39,
  KEY_LEFT_PARENTHESIS = 40,
  KEY_RIGHT_PARENTHESIS = 41,
  KEY_ASTERISK = 42,
  KEY_PLUS = 43,
  KEY_COMMA = 44,
  KEY_MINUS = 45,
  KEY_FULL_STOP = 46,
  KEY_SOLIDUS = 47,
  KEY_ZERO = 48,
  KEY_ONE = 49,
  KEY_TWO = 50,
  KEY_THREE = 51,
  KEY_FOUR = 52,
  KEY_FIVE = 53,
  KEY_SIX = 54,
  KEY_SEVEN = 55,
  KEY_EIGHT = 56,
  KEY_NINE = 57,
  KEY_COLON = 58,
  KEY_SEMICOLON = 59,
  KEY_LESS_THAN_SIGN = 60,
  KEY_EQUALS_SIGN = 61,
  KEY_GREATER_THAN_SIGN = 62,
  KEY_QUESTION_MARK = 63,
  KEY_AT = 64,
  KEY_CAPITAL_A = 65,
  KEY_CAPITAL_B = 66,
  KEY_CAPITAL_C = 67,
  KEY_CAPITAL_D = 68,
  KEY_CAPITAL_E = 69,
  KEY_CAPITAL_F = 70,
  KEY_CAPITAL_G = 71,
  KEY_CAPITAL_H = 72,
  KEY_CAPITAL_I = 73,
  KEY_CAPITAL_J = 74,
  KEY_CAPITAL_K = 75,
  KEY_CAPITAL_L = 76,
  KEY_CAPITAL_M = 77,
  KEY_CAPITAL_N = 78,
  KEY_CAPITAL_O = 79,
  KEY_CAPITAL_P = 80,
  KEY_CAPITAL_Q = 81,
  KEY_CAPITAL_R = 82,
  KEY_CAPITAL_S = 83,
  KEY_CAPITAL_T = 84,
  KEY_CAPITAL_U = 85,
  KEY_CAPITAL_V = 86,
  KEY_CAPITAL_W = 87,
  KEY_CAPITAL_X = 88,
  KEY_CAPITAL_Y = 89,
  KEY_CAPITAL_Z = 90,
  KEY_LEFT_SQUARE_BRACKET = 91,
  KEY_REVERSE_SOLIDUS = 92,
  KEY_RIGHT_SQUARE_BRACKET = 93,
  KEY_CIRCUMFLEX_ACCENT = 94,
  KEY_LOW_LINE = 95,
  KEY_GRAVE_ACCENT = 96,
  KEY_A = 97,
  KEY_B = 98,
  KEY_C = 99,
  KEY_D = 100,
  KEY_E = 101,
  KEY_F = 102,
  KEY_G = 103,
  KEY_H = 104,
  KEY_I = 105,
  KEY_J = 106,
  KEY_K = 107,
  KEY_L = 108,
  KEY_M = 109,
  KEY_N = 110,
  KEY_O = 111,
  KEY_P = 112,
  KEY_Q = 113,
  KEY_R = 114,
  KEY_S = 115,
  KEY_T = 116,
  KEY_U = 117,
  KEY_V = 118,
  KEY_W = 119,
  KEY_X = 120,
  KEY_Y = 121,
  KEY_Z = 122,
  KEY_LEFT_CURLY_BRACKET = 123,
  KEY_VERTICAL_LINE = 124,
  KEY_RIGHT_CURLY_BRACKET = 125,
  KEY_TILDE = 126,
  KEY_BACKSPACE = 127,

  KEY_UP = 128,
  KEY_DOWN = 129,
  KEY_RIGHT = 130,
  KEY_LEFT = 131,
  KEY_DELETE = 132,
};

struct Char {
  Char()
      : attrs(0)
      , ch(32)
  {
  }
  Char(const std::uint16_t& ch, std::uint32_t flags = 0)
      : attrs(flags)
      , ch(ch)
  {
  }
  inline std::string to_string()
  {
    std::string out = "\033[";
    if ((attrs & Attrs::BOLD) == Attrs::BOLD)
      out += "1;";
    if ((attrs & Attrs::FAINT) == Attrs::FAINT)
      out += "2;";
    if ((attrs & Attrs::ITALIC) == Attrs::ITALIC)
      out += "3;";
    if ((attrs & Attrs::UNDERLINE) == Attrs::UNDERLINE)
      out += "4;";
    if ((attrs & Attrs::BLINK) == Attrs::BLINK)
      out += "5;";
    if ((attrs & Attrs::FOREGROUND) == Attrs::FOREGROUND)
      out += "38;5;" + std::to_string((attrs >> 5) & 0xff) + ";";
    else
      out += "39;";
    if ((attrs & Attrs::BACKGROUND) == Attrs::BACKGROUND)
      out += "48;5;" + std::to_string((attrs >> 14) & 0xff) + "m";
    else
      out += "49m";
    if (ch <= 0x7f) {
      out.append(1, static_cast<char>(ch));
    } else if (ch <= 0x7ff) {
      out.append(1, static_cast<char>(0xc0 | ((ch >> 6) & 0x1f)));
      out.append(1, static_cast<char>(0x80 | (ch & 0x3f)));
    } else if (ch <= 0xffff) {
      out.append(1, static_cast<char>(0xe0 | ((ch >> 12) & 0x0f)));
      out.append(1, static_cast<char>(0x80 | ((ch >> 6) & 0x3f)));
      out.append(1, static_cast<char>(0x80 | (ch & 0x3f)));
    } else {
      out.append(1, static_cast<char>(0xf0 | ((ch >> 18) & 0x07)));
      out.append(1, static_cast<char>(0x80 | ((ch >> 12) & 0x3f)));
      out.append(1, static_cast<char>(0x80 | ((ch >> 6) & 0x3f)));
      out.append(1, static_cast<char>(0x80 | (ch & 0x3f)));
    }
    return out + "\033[0m";
  }
  std::uint32_t attrs;
  std::uint16_t ch;
};
class Terminal {
  public:
  inline Terminal()
  {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    cols = w.ws_col;
    rows = w.ws_row - 1;
    buffer = std::vector<Char>(cols * rows, Char());
    display_buffer = std::vector<Char>(cols * rows, Char());
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~ECHO;
    term.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term);
    printf("\033[?25l\033[?1000h\033[?1006h\n");
  }
  inline ~Terminal()
  {
    printf("\033[?1006l\033[?1000l\033[?25h\n");
    struct termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ECHO;
    term.c_lflag |= ICANON;
    tcsetattr(0, TCSANOW, &term);
  }

  void fill(std::uint16_t c)
  {
    for (auto& ch : buffer) {
      ch = c;
    }
  }
  void fill(char c)
  {
    for (auto& ch : buffer) {
      ch = c;
    }
  }
  void fill(Char c)
  {
    for (auto& ch : buffer) {
      ch = c;
    }
  }

  void clear()
  {
    for (auto& ch : buffer) {
      ch = 32;
    }
  }

  void swap()
  {
    printf("\033[1;1H");
    for (std::uint32_t y = 0; y < rows; ++y) {
      std::string row;
      for (std::uint32_t x = 0; x < cols; ++x) {
        if (buffer[y * cols + x].ch >= 32)
          display_buffer[y * cols + x] = buffer[y * cols + x];
        row += display_buffer[y * cols + x].to_string();
      }
      printf("%s\n", row.c_str());
    }
  }

  Char& operator()(const std::uint32_t& x, const std::uint32_t& y)
  {
    return buffer[y * cols + x];
  }

  union {
    std::uint32_t width, cols;
  };
  union {
    std::uint32_t height, rows;
  };

  private:
  std::vector<Char> buffer, display_buffer;
};
void parse_events(std::queue<std::uint16_t> char_queue_)
{
  while (char_queue_.size() != 0) {
    std::uint16_t ch = char_queue_.front();
    char_queue_.pop();
    std::uint32_t event = 0;
    if (ch != 27 || char_queue_.size() == 0) {
      event |= KEYBOARD | (static_cast<std::uint32_t>(ch) << 2);
    } else {
      ch = char_queue_.front();
      char_queue_.pop();
      if (ch == 91 && char_queue_.empty() == false && char_queue_.front() == 60) {
        char_queue_.pop();
        ch = char_queue_.front();
        event |= MOUSE;
        char_queue_.pop();
        std::uint8_t mb = 0;
        while (ch != 59) {
          mb = (mb * 10) + (ch - 48);
          ch = char_queue_.front();
          char_queue_.pop();
        }
        ch = char_queue_.front();
        char_queue_.pop();
        event |= (mb == 0) ? MB : 0;
        std::uint8_t col = 0;
        while (ch != 59) {
          col = (col * 10) + (ch - 48);
          ch = char_queue_.front();
          char_queue_.pop();
        }
        ch = char_queue_.front();
        char_queue_.pop();
        event |= (static_cast<std::uint32_t>(col-1) << MX_OFFSET);
        std::uint8_t row = 0;
        while (ch != 77 && ch != 109) {
          row = (row * 10) + (ch - 48);
          ch = char_queue_.front();
          char_queue_.pop();
        }
        event |= (static_cast<std::uint32_t>(row-1) << MY_OFFSET);
        event |= (ch == 77) ? MB_STATE : 0;
      } else if (ch == 91 && char_queue_.empty() == false) {
        ch = char_queue_.front();
        char_queue_.pop();
        event |= KEYBOARD;
        switch (ch) {
        case 51:
          event |= KEY_DELETE << KEY_OFFSET;
          break;
        case 65:
          event |= KEY_UP << KEY_OFFSET;
          break;
        case 66:
          event |= KEY_DOWN << KEY_OFFSET;
          break;
        case 67:
          event |= KEY_RIGHT << KEY_OFFSET;
          break;
        case 68:
          event |= KEY_LEFT << KEY_OFFSET;
          break;
        default:
          event = 0;
          break;
        }
      } else {
        event = 0;
      }
    }
    if (event != 0)
      event_queue_.push(event);
  }
}

std::uint16_t pending_chars(int timeout_ms)
{
  int bytes = 0, result = 0;
  if (timeout_ms < 0) {
    bool wait = true;
    while (wait == true) {
      usleep(100);
      result = ioctl(0, FIONREAD, &bytes);
      wait = !bytes;
    }
  } else if (timeout_ms == 0) {
    result = ioctl(0, FIONREAD, &bytes);
  } else if (timeout_ms <= 1000) {
    clock_t start = clock(),
            end = start + (timeout_ms * CLOCKS_PER_SEC / 10000);
    bool wait = true;
    while (start < end && wait == true) {
      start = clock();
      usleep(100);
      result = ioctl(0, FIONREAD, &bytes);
      wait = !bytes;
    }
  } else {
    clock_t start = clock(),
            end = start + (timeout_ms * CLOCKS_PER_SEC / 10000);
    bool wait = true;
    while (start < end && wait == true) {
      start = clock();
      usleep(1000);
      result = ioctl(0, FIONREAD, &bytes);
      wait = !bytes;
    }
  }
  if (result != 0 || bytes <= 0) {
    return 0;
  }
  return static_cast<std::uint16_t>(bytes);
}

std::uint32_t poll_events(int timeout_ms = 0)
{
  std::uint16_t count = pending_chars(timeout_ms);
  std::queue<std::uint16_t> char_queue_;
  for (std::uint16_t i = 0; i < count; ++i) {
    char_queue_.push(std::cin.get());
  }
  parse_events(char_queue_);
  std::uint32_t ev = 0;
  if (event_queue_.empty() == false) {
    ev = event_queue_.front();
    event_queue_.pop();
  }
  return ev;
}

inline bool is_key(const std::uint32_t& ev)
{
  return (ev & KEYBOARD) == KEYBOARD;
}
inline bool is_mouse(const std::uint32_t& ev)
{
  return (ev & MOUSE) == MOUSE;
}
inline std::uint16_t get_key(const std::uint32_t& ev)
{
  return (ev & KEYBOARD) == KEYBOARD ? (ev >> KEY_OFFSET) & 0xffff : 0;
}
inline std::uint16_t get_x(const std::uint32_t& ev)
{
  return (ev & MOUSE) == MOUSE ? (ev >> MX_OFFSET) & 0xff : 0;
}
inline std::uint16_t get_y(const std::uint32_t& ev)
{
  return (ev & MOUSE) == MOUSE ? (ev >> MY_OFFSET) & 0xff : 0;
}
inline std::uint8_t get_button(const std::uint32_t& ev)
{
  return (ev & (MOUSE | MB)) == (MOUSE | MB) ? 1 : 0;
}
inline std::uint8_t get_state(const std::uint32_t& ev)
{
  return (ev & (MOUSE | MB_STATE)) == (MOUSE | MB_STATE) ? 1 : 0;
}

#endif // GRAPHICS_HPP_
