/*
 * File: str.c
 * Desc: Implementation of functions defined in `str.h` file.
 * Author: Hossein Khosravi
 */

#include <stdlib.h>
#include <string.h>

#include "str.h"

char *strdup(const char *s) {
    size_t len = strlen(s) + 1;
    char *new = (char*) malloc(sizeof(char) * len);
    if (!new)
        return NULL;
    new[len-1] = 0;

    new = strcpy(new, s);
    return new;
}
