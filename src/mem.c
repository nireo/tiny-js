#include <stdlib.h>

#include "mem.h"

void *reallocate(void *pointer, size_t old_size, size_t new_size) {
  if (new_size == 0) {
    free(pointer);
    return NULL;
  }

  void *res = realloc(pointer, new_size);
  if (res == NULL) exit(1);

  return res;
}
