#ifndef LOSLIB_EX_H
#define LOSLIB_EX_H

/* DEBBUGING & I/O */

/**
 * Assert expr and crash if fail.
 */
#define assert(expr) \
  if (!(expr)) { \
    loslib_eprintln("Assertion `" #expr "` failed."); \
    __syscall2(62 /* kill */, __syscall0(39 /* getpid */), 6 /* SIGABRT */); \
    exit(127); \
  }

/**
 * Print string to STDOUT.
 */
#define loslib_print(str) \
  write(1, str, sizeof(str) - 1 /* z-terminated */);
/**
 * Print string with \n to STDOUT.
 */
#define loslib_println(str) \
  write(1, str "\n", sizeof(str) /* + "\n" */);

/**
 * Print string to STDERR.
 */
#define loslib_eprint(str) \
  write(2, str, sizeof(str) - 1 /* z-terminated */);
/**
 * Print string with \n to STDERR.
 */
#define loslib_eprintln(str) \
  write(2, str "\n", sizeof(str) /* + "\n" */);

#endif /* LOSLIB_EX_H */
