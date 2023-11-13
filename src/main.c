/*
 * File: main.c
 * Desc: Main entry point of packDB executable.
 * Author: Hossein Khosravi
 */

#include <stdio.h>

#include "keytable.h"
#include "general.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "[ERROR] Not enouph arguments.\n");
        return 1;
    }

    KeyTable *kt = keytable_new();
    if (is_null(kt)) {
        fprintf(stderr, "[ERROR] Could not initialize KeyTable.\n");
        return 1;
    }

    /*
     * Testing KeyTable
     */
    for (int i = 1; i < argc; i++)
        keytable_add(kt, argv[i], "1");
    keytable_print(kt);

    keytable_free(kt);
    return 0;
}
