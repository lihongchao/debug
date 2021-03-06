
/**
 * `debug.h' - debug.c
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#ifndef DEBUG_H
#define DEBUG_H 1

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * Debug function type
 */

typedef void (* debug_t) (const char *, ...);

/**
 * Initialize a debug function
 */

#define debug_init(name)                                                      \
  void _debug_ ## name (const char *fmt, ...) {                               \
    if (!debug_enabled(#name)) { return; }                                    \
    char *buf = NULL;                                                         \
    va_list args;                                                             \
    va_start(args, fmt);                                                      \
    if (-1 != vasprintf(&buf, fmt, args)) {                                   \
      printf(#name " - %s\n", buf);                                           \
    }                                                                         \
    va_end(args);                                                             \
    free(buf);                                                                \
  }                                                                           \

/**
 * Return a named debug function
 */

#define debug_get(name) (debug_t) ( _debug_ ## name)

/**
 * Returns `1' if a function is enabled
 * else `0'
 */

int
debug_enabled (const char *);

#endif
