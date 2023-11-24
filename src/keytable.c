/*
 * File: keytable.c
 * Desc: Implementation of functions defined in `keytable.h` file.
 * Author: Hossein Khosravi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keylist.h"
#include "keytable.h"
#include "general.h"
#include "str.h"


/**
 * Calculate hash value for a key
 *
 * @key: key string
 * ---
 * @ret: index in value's list
 */
static unsigned long calc_hash(const char *key) {
    unsigned int alphabet_size = 36; // a - z & 0 - 9
    unsigned long key_len = strlen(key);
    unsigned long alpha = alphabet_size ^ key_len;

    unsigned long num = 0;
    for (unsigned long i = 0; i < key_len; i++)
        num = ((alphabet_size * (key_len + key[i])) * key[i]) % KEYTABLE_CAP;

    return (alpha + num + key_len) % KEYTABLE_CAP;
}


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


static void keytable_free_helper(char **vals, KeyListNode *knp) {
    if (is_null(vals))
        return;

    if (knp) {
        keytable_free_helper(vals, knp->next);

        unsigned long hash = calc_hash(knp->name);
        check_then_free(vals[hash]);
        keylistnode_free(knp);
    }
}


void keytable_free(KeyTable *ktp) {
    if (ktp) {
        keytable_free_helper(ktp->vals, ktp->keys_list->head);
        free(ktp->keys_list);
        free(ktp);
    }
}


int keytable_add(KeyTable *ktp, const char *key, const char *val) {
    if (is_null(ktp) || is_null(key) || is_null(val))
        return 1;
    int err = keylist_append(ktp->keys_list, key);
    if (err == 1)
        return 1;

    unsigned long hash = calc_hash(key);
    ktp->vals[hash] = strdup(val);
    if (is_null(ktp->vals[hash])) {
        keylist_delete(ktp->keys_list, key);
        return 1;
    }

    return 0;
}


static void keytable_print_helper(char **vals, KeyListNode *knp) {
    if (knp && vals) {
        unsigned long hash = calc_hash(knp->name);
        if (vals[hash])
            printf("%s\t->\t%s\n", knp->name, vals[hash]);
        else
            printf("%s\t->\tNULL\n", knp->name);
        keytable_print_helper(vals, knp->next);
    }
}


void keytable_print(KeyTable *ktp) {
    keytable_print_helper(ktp->vals, ktp->keys_list->head);
}


int keytable_delete(KeyTable *ktp, const char *key) {
    if (is_null(ktp) || is_null(key))
        return 1;

    int err;
    unsigned int hash = calc_hash(key);

    err = keylist_delete(ktp->keys_list, key);
    if (!err)
        return 1;

    check_then_free(ktp->vals[hash]);
    return 0;
}
