#include "lexer.h"

typedef struct {
  const char *start;
  const char *curr;
  int line;
} lexer_t;

lexer_t lexer;

void init_lexer(const char *src) {
  lexer.start = src;
  lexer.curr = src;
  lexer.line = 1;
}

