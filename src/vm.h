#ifndef JS_VM_H
#define JS_VM_H

#include "opcode.h"

#define STACK_MAX 256

typedef enum {
  RUN_RES_OK,
  RUN_RES_COMPILE_ERR,
  RUN_RES_RUNTIME_ERR,
} run_res_t;

typedef struct {
  chunk_t *chunk;
  uint8_t *ip;
  val_t stack[STACK_MAX];
  val_t *stack_top;
} vm_t;

void init_vm(void);
void free_vm(void);
run_res_t interpret(chunk_t *chunk);
void push(val_t val);
val_t pop(void);

#endif
