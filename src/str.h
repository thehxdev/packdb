#ifndef STR_H
#define STR_H


#if !defined (_DEFAULT_SOURCE) \
    || !defined (__USE_XOPEN_EXTENDED) \
    || _XOPEN_SOURCE < 500 \
    || _POSIX_C_SOURCE < 200809L
char *strdup(const char *s);
#endif // strdup


#endif // STR_H
