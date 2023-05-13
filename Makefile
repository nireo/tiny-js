tinyjs-release:
	gcc -O3 -Wall -Wshadow -Wundef src/main.c src/opcode.c src/mem.c src/debug.c src/value.c src/vm.c -o tinyjs
