#include "../fr/loslib.h"

loslib_crt(start);

const char s[] = { ' ', '\n' };

void start(long *p) {
  long i;

  for (i = 2; i <= *p; i += 1) {
    long l;
    for (l = 0; *(char*)(p[i] + l) != 0; l += 1);

    write(1, (void*)p[i], l);
    if (i != *p)
      write(1, s, 1);
  }

  write(1, s + 1, 1);
  exit_unsafe(0);
}

