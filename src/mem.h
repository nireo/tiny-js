#ifndef JS_MEM_H
#define JS_MEM_H

#define GROW_CAPACITY(capacity) \
  ((capacity) < 8 ? 8 : (capacity) * 2)

#endif
