#pragma once

#include <cstdint>
struct lexer_t {
  lexer_t(const char *source) : start(source), curr(source) {}

  const char *start;
  const char *curr;
  int line{1};
};

enum class tok_type_t : std::uint8_t {
  LeftParen,
  RightParen,
  LeftBrace,
  RightBrace,
}

struct token_t {
  tok_type_t type;
  const char *start;
  int length;
  int line;
};
