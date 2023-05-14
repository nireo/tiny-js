#include "vm.h"
#include "opcode.h"
#include "value.h"
#include "lib.h"
#include <stdio.h>
#include "debug.h"
#include "codegen.h"

vm_t vm;

static void reset_stack() {
  vm.stack_top = vm.stack;
}

void init_vm(void) {
  reset_stack();
}

void free_vm(void) {
}

void push(val_t val) {
  *vm.stack_top = val;
  ++vm.stack_top;
}

val_t pop(void) {
  --vm.stack_top;
  return *vm.stack_top;
}

static run_res_t run(void) {
  #define READ_BYTE() (*vm.ip++)
  #define READ_CONST() (vm.chunk->constants.values[READ_BYTE()])
  #define BINARY_OP(op) \
    do { \
      double b = pop(); \
      double a = pop(); \
      push(a op b); \
    } while (false)

  for (;;) {
    #ifdef DEBUG_TRACE_EXECUTION
    printf("               ");
    for (val_t *slot = vm.stack; slot < vm.stack_top; ++slot) {
      printf("[ ");
      print_val(*slot);
      printf(" ]");
    }
    printf("\n");

    disassemble_inst(vm.chunk, (int)(vm.ip - vm.chunk->code));
    #endif

    uint8_t inst;
    switch (inst = READ_BYTE()) {
      case OP_CONST: {
        val_t c = READ_CONST();
        push(c);
        break;
      }
      case OP_RET: {
        print_val(pop());
        printf("\n");
        return RUN_RES_OK;
      }
      case OP_NEG: {
        push(-pop());
        break;
      }
      case OP_ADD:      BINARY_OP(+); break;
      case OP_SUBTRACT: BINARY_OP(-); break;
      case OP_MULTIPLY: BINARY_OP(*); break;
      case OP_DIVIDE:   BINARY_OP(/); break;
    }
  }

  #undef BINARY_OP
  #undef READ_BYTE
  #undef READ_CONST
}

run_res_t interpret(const char *source) {
  codegen(source);
  return run();
}
