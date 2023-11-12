/*
 * File: keytable.c
 * Desc: Implementation of functions defined in `keytable.h` file.
 * Author: Hossein Khosravi
 */

#include <stdlib.h>

#include "keylist.h"
#include "keytable.h"
#include "general.h"


// TODO: Implement a hash function

// static unsigned int calc_hash(const char *name);


KeyTable *keytable_new() {
    KeyTable *k = (KeyTable*) malloc(sizeof(KeyTable));
    if (is_null(k))
        return NULL;

    k->keys_list = keylist_new();
    if (is_null(k->keys_list)) {
        free(k);
        return NULL;
    }
    k->nodes_count = 0; 
    return k;
}


static void keytable_free_helper(TableNode **ntp, KeyNode *knp) {
    if (is_null(ntp))
        return;

    if (knp) {
        keytable_free_helper(ntp, knp->next);
        keynode_free(knp);
    }
}


void keytable_free(KeyTable *ktp) {
    if (ktp) {
        keytable_free_helper(ktp->nodes, ktp->keys_list->head);
        free(ktp->keys_list);
        free(ktp);
    }
}
