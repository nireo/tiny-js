#ifndef JS_VM_H
#define JS_VM_H

#include "opcode.h"

typedef struct {
  chunk_t *chunk;
} vm_t;

void init_vm(void);
void free_vm(void);

#endif
