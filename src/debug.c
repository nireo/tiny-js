#include <stdio.h>

#include "debug.h"

void disassemble_chunk(chunk_t *chunk, const char *name) {
  printf("== %s ==\n", name);

  for (int offset = 0; offset < chunk->count;) {
    offset = disassemble_inst(chunk, offset);
  }
}

static int simple_inst(const char* name, int offset) {
  printf("%s\n", name);
  return offset + 1;
}

static int const_inst(const char *name, chunk_t *chunk, int offset) {
  uint8_t constant = chunk->code[offset + 1];
  printf("%-16s %4d '", name, constant);
  print_val(chunk->constants.values[constant]);
  printf("'\n");

  return offset + 2;
}

int disassemble_inst(chunk_t* chunk, int offset) {
  printf("%04d ", offset);

  uint8_t instruction = chunk->code[offset];
  switch (instruction) {
    case OP_RET:
      return simple_inst("OP_RET", offset);
    case OP_CONST:
      return const_inst("OP_CONST", chunk, offset);
    case OP_NEG:
      return simple_inst("OP_NEG", offset);
    default:
      printf("unknown opcode %d\n", instruction);
      return offset + 1;
  }
}
