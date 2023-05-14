#include "codegen.h"
#include "lexer.h"

void codegen(const char *source) {
  init_lexer(source);
  int line = -1;

  for (;;) {
    tok_t token = scan_token();
    if (token.line != line) {
      printf("%4d ", token.line);
      line = token.line;
    } else {
      printf("   | ");
    }
    printf("%2d '%.*s'\n", token.type, token.length, token.start); 

    if (token.type == TOKEN_EOF) break;
  }
}
