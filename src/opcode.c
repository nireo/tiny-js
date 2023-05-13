#include "opcode.h"

void init_chunk(chunk_t *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
}

void write_chunk(chunk_t *chunk, uint8_t byte) {
  if (chunk->capacity < chunk->count + 1) {
    int old_cap = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(old_cap);
    chunk->code = GROW_ARRAY(uint8_t, chunk->code, old_cap, chunk->capacity);
  }

  chunk->code[chunk->count] = byte;
  ++chunk->count;
}
