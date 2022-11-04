#include "../fr/loslib.h"
#include "../fr/loslib-extensions.h"

loslib_crt(start);

__attribute__((noreturn))
void start(long *p) {
  if (p[0] != 2) {
    loslib_eprintln("Usage: zb <filename>");

    goto exit;
  }
  loslib_println("Hello, world!");

exit:
  exit_unsafe(0);
}

