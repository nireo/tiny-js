#include "opcode.h"
#include "mem.h"
#include "value.h"

void init_chunk(chunk_t *chunk) {
  chunk->count = 0;
  chunk->capacity = 0;
  chunk->code = NULL;
  init_val_arr(&chunk->constants);
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

void free_chunk(chunk_t *chunk) {
  FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
  free_val_arr(&chunk->constants);
  init_chunk(chunk);
}

int add_const(chunk_t *chunk, val_t val) {
  write_val_arr(&chunk->constants, val);
  return chunk->constants.count - 1;
}
