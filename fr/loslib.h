#ifndef LOSLIB_H
#define LOSLIB_H
#include "in/defines.h"

/* Syscalls */
#include "in/syscall.h"

/* --- C Standart --- */
int main(int argc, char **argv);

/* --- Base Functions ---  */

/**
 * Exit from threads and app. This function
 * is never return.
 */
loslib("system")
loslib_inline()
loslib_noreturn()
static void exit(long ec) {
  __syscall1(231, ec); /* exit from threads */
  while (1) /* noreturn */
    __syscall1(60, ec); /* exit from main */
}

/**
 * Exit from app. This function is never
 * return.
 * SAFETY: all threads must be finished.
 */
loslib("system")
loslib_inline()
loslib_noreturn()
static void exit_unsafe(long ec) {
  while (1) /* noreturn */
    __syscall1(60, ec); /* exit from main */
}

/**
 * Call read() for fd into buffer to read count bytes.
 */
loslib("system")
loslib_inline()
static long read(long fd, void *buff, unsigned long count) {
  return __syscall3(0, fd, (long)buff, count);
}
/**
 * Call write() for fd into buffer to write count bytes.
 */
loslib("system")
loslib_inline()
static long write(long fd, const void *buff, unsigned long count) {
  return __syscall3(1, fd, (long)buff, count);
}

/* --- C Runtime --- */

/**
 * Define CRT to use. Example usage:
 * void mycrt(long *p) { main((int)p[0], (char**)p[1]); exit(0); }
 * loslib_crt(mycrt);
 */
#define loslib_crt(crt) \
  __asm__(                         \
    ".text                     \n" \
    ".global _start            \n" \
    "_start:                   \n" \
    "  xor %rbp,%rbp           \n" \
    "  mov %rsp,%rdi           \n" \
    ".weak _DYNAMIC            \n" \
    ".hidden _DYNAMIC          \n" \
    "  lea _DYNAMIC(%rip),%rsi \n" \
    "  andq $-16,%rsp          \n" \
    "  call " #crt "           \n" \
  )

/**
 * Generic CRT with auto-return.
 * Main defination: int main(int argc, char **argv);
 */
loslib("crt")
loslib_inline()
loslib_noreturn()
static void loslib_crt_generic(long *v) {
  int result;

  result = main((int)v[0], (char**)(v + 1));

  exit(result);
}

/**
 * Generic CRT without auto-return (assuming main() is noreturn).
 * Main defination: (noreturn) int main(int argc, char **argv);
 */
loslib("crt")
loslib_inline()
loslib_noreturn()
static void loslib_crt_noreturn(long *v) {
  main((int)v[0], (char**)(v + 1));

  while (1) { } /* noreturn */
}

#include "in/undefines.h"
#endif /* LOSLIB_H */
