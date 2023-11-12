/*
 * File: str.h
 * Desc: Functoinalities that make working with strings easier.
 * Author: Hossein Khosravi
 */

#ifndef STR_H
#define STR_H


/**
 * `strdup` is not a standard C functoin, so if the program
 * compiles with ANSI C compiler (Not GNU) this functoin must
 * be manually written.
 */
#if !defined (_DEFAULT_SOURCE) \
    || !defined (__USE_XOPEN_EXTENDED) \
    || _XOPEN_SOURCE < 500 \
    || _POSIX_C_SOURCE < 200809L
/**
 * @WARN!
 * Duplicate and return exact same malloc'd string.
 *
 * @s: source string.
 * ---
 * @ret: duplicated malloc'd `s` | NULL
 */
char *strdup(const char *s);
#endif // strdup


#endif // STR_H
