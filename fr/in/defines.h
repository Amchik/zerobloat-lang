#define loslib(sec) __attribute__((section(".loslib." sec)))
#define loslib_internals(sec) __attribute__((section(".loslib.internals." #sec)))
#define loslib_noreturn() __attribute__((noreturn))
#define loslib_inline() __attribute__((always_inline))
