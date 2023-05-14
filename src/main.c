#include "debug.h"
#include "lib.h"
#include "opcode.h"
#include "vm.h"
#include <stdio.h>
#include <stdlib.h>

static void repl(void) {
  char line[1024];
  for (;;) {
    printf(">>> ");
    if (!fgets(line, sizeof(line), stdin)) {
      printf("\n");
      break;
    }

    interpret(line);
  }
}

static char *read_file(const char *path) {
  FILE *fp = fopen(path, "rb");
  if (fp == NULL) {
    fprintf(stderr, "could not open file \"%s\".\n", path);
    exit(1);
  }

  fseek(fp, 0L, SEEK_END);
  size_t fsize = ftell(fp);
  rewind(fp);

  char *buf = (char *)malloc(fsize + 1);
  if (buf == NULL) {
    fprintf(stderr, "Not enough memory to read \"%s\".\n", path);
    exit(1);
  }

  size_t bytes_read = fread(buf, sizeof(char), fsize, fp);
  buf[bytes_read] = '\0';

  fclose(fp);
  return buf;
}

static void run_file(const char *path) {
  char *source = read_file(path);
  run_res_t res = interpret(source);
  free(source);

  if (res == RUN_RES_COMPILE_ERR)
    exit(1);
  if (res == RUN_RES_RUNTIME_ERR)
    exit(1);
}

int main(int argc, const char **argv) {
  init_vm();

  if (argc == 1) {
    repl();
  } else if (argc == 2) {
    run_file(argv[1]);
  } else {
    fprintf(stderr, "usage: tinyjs [path]\n");
    exit(1);
  }

  free_vm();
  return 0;
}
