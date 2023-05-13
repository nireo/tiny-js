#include "debug.h"
#include "opcode.h"
#include "lib.h"

int main(int argc, const char **argv) {
  chunk_t chunk;
  init_chunk(&chunk);
  int c = add_const(&chunk, 1.2);
  write_chunk(&chunk, OP_CONST);
  write_chunk(&chunk, c);

  write_chunk(&chunk, OP_RET);
  disassemble_chunk(&chunk, "test chunk");
  free_chunk(&chunk);

  return 0;
}
