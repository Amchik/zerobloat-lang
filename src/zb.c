#include "../fr/loslib.h"
#include "../fr/loslib-extensions.h"

loslib_crt(start);

#define open(a1, a2)             __syscall2(2,  a1, a2)
#define lseek(a1, a2, a3)        __syscall3(8,  a1, a2, a3)
#define sendfile(a1, a2, a3, a4) __syscall4(40, a1, a2, a3, a4)

#define SEEK_SET 0
#define SEEK_END 2

const char *INVALID_FILENAME = "Invalid <filename>\nUsage: zb <filename>\n";
#define USAGE (INVALID_FILENAME + 19)

__attribute__((noreturn))
void start(long *p) {
  long fd, size;

  if (*p != 2) {
    write(2, USAGE, 21);
    exit_unsafe(1);
  }

  fd = open(p[2], 0);
  if (fd < 0) {
    write(2, INVALID_FILENAME, 40);
    exit_unsafe(2);
  }

  size = lseek(fd, 0, SEEK_END);
  lseek(fd, 0, SEEK_SET);

  sendfile(1, fd, 0, size);

  exit_unsafe(0);
}

