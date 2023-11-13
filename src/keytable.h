/*
 * File: keytable.h
 * Desc: Hash-Table to store information thah passed to packdb.
 * Author: Hossein Khosravi
 */

#ifndef KEYTABLE_H
#define KEYTABLE_H

#include <stddef.h>
#include "keylist.h"

/**
 * Capacity of KeyTable
 */
#define KEYTABLE_CAP (1 << 16)


/**
 * TableNode used to store a key's value.
 * (NOT USED YET)
 */
#if 0
typedef struct __table_node {
    void *value;
} TableNode;
#endif // TableNode


/**
 * Main Hash-Table to store data of packdb
 */
typedef struct __key_table {
    char *vals[KEYTABLE_CAP];
    KeyList *keys_list;
    size_t nodes_count;
} KeyTable;


/**
 * @WARN!
 * Create a new KeyTable instance
 * ---
 * @ret: pointer to new KeyTable | NULl
 */
KeyTable *keytable_new();


/**
 * Free a KeyTable from memory
 *
 * @ktp: pointer to a KeyTable
 */
void keytable_free(KeyTable *ktp);


/**
 * Add a new key-value to KeyTable
 *
 * @ktp: pointer to a KeyTable
 * @key: key string
 * @val: value in string form
 * ---
 * @ret: 0 OK | 1 Error
 */
int keytable_add(KeyTable *ktp, const char *key, const char *val);


/**
 * Print a KeyTable elements to stdout recursively
 *
 * @ktp: pointer to a KeyTable
 */
void keytable_print(KeyTable *ktp);

#endif // KEYTABLE_H
