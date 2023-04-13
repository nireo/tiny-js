#include "vm.hh"
#include "opcode.hh"
#include "value.h"
#include <cstdio>

#define o(x) static_cast<uint8_t>((x))

run_result_t vm_t::run() noexcept {
#define NEXT() (*ip++)
#define GET_CONST() (chunk.constants[NEXT()])

  for (;;) {
    uint8_t inst;

    switch (inst = NEXT()) {
    case o(OP::Return): {
      return run_result_t::Ok;
    }
    case o(OP::Constant): {
      val_t constant = GET_CONST();
      print_value(constant);
      std::puts("");
      break;
    }
    }
  }
#undef GET_CONST
#undef NEXT
}
