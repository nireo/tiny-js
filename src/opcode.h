#ifndef JS_OPCODE_H
#define JS_OPCODE_H

#include "lib.h"

/* Opcodes represent different instructions that need to handled */
typedef enum {
  OP_RET,
} opcode_t;

/* A chunk represents a collection of opcodes. Chunks are also dynamic arrays */
typedef struct {
  int count;
  int capacity;
  uint8_t *code;
} chunk_t;

void init_chunk(chunk_t *chunk);
void write_chunk(chunk_t *chunk, uint8_t byte);

#endif
