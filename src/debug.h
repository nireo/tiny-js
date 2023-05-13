#ifndef JS_DEBUG_H
#define JS_DEBUG_H

#include "opcode.h"

void disassemble_chunk(chunk_t *chunk, const char *name);
int disassemble_inst(chunk_t *chunk, int offset);

#endif
