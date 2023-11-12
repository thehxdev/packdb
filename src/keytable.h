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
 */
typedef struct __table_node {
    void *value;
} TableNode;


/**
 * Main Hash-Table to store data of packdb
 */
typedef struct __key_table {
    TableNode *nodes[KEYTABLE_CAP];
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

#endif // KEYTABLE_H
