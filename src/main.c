/*
 * File: main.c
 * Desc: Main entry point of packDB executable.
 * Author: Hossein Khosravi
 */

#include <stdio.h>

#include "keylist.h"
#include "general.h"


int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "[ERROR] Not enouph arguments.\n");
        return 1;
    }

    KeyList *kl = keylist_new();
    if (is_null(kl)) {
        fprintf(stderr, "[ERROR] Cannot initialize keylist.\n");
        return 1;
    }

    /*
     * Testing KeyList
     * Storing command-line arguments in a KeyList
     * and print them in list form.
     */
    for (int i = 1; i < argc; i++)
        keylist_append(kl, argv[i]);
    keylist_print(kl);

    keylist_free(kl);
    return 0;
}
