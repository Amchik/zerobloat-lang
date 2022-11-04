#include "../fr/loslib.h"

loslib_crt(start);

__attribute__((noreturn))
void start(long *p) {
  if (p[0] != 2) {
    write(2, "Usage: zb <filename>\n", 22);
    exit_unsafe(1);
  }
  write(1, "Hello, world!\n", 14);

  exit_unsafe(0);
}

