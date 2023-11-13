/*
 * File: keylist.h
 * Desc: Doubly linked-list to store keys of the KeyTable.
 * Author: Hossein Khosravi
 */

#ifndef KEYLIST_H
#define KEYLIST_H

/**
 * Node of a double linked-list that holds
 * name of keys in hash-table (keytable)
 */
typedef struct __key_node {
    char *name;
    struct __key_node *next;
    struct __key_node *prev;
} KeyListNode;


/**
 * Keep track of head and tail of the
 * double linked-list.
 * Benefits:
 *   1. Constant time append to list
 *   2. Constant time delete from list
 *   3. Don't lose head and tail pointers
 */
typedef struct __key_list {
    KeyListNode *head;
    KeyListNode *tail;
} KeyList;


/**
 * @WARN!
 * Create a new KeyListNode instance
 *
 * @name: key string
 * ---
 * @ret: pointer to a new KeyListNode | NULL
 */
KeyListNode *KeyListNode_new(const char *s);


/**
 * Free a KeyListNode from memory recursively 
 *
 * @knp: pointer to a KeyListNode
 */
void KeyListNode_free(KeyListNode *knp);


/**
 * @WARN!
 * Create a new KeyList instance
 * ---
 * @ret: pointer to a new KeyList | NULL
 */
KeyList *keylist_new();


/**
 * Free a KeyList from memory recursively 
 *
 * @klp: pointer to a KeyList
 */
void keylist_free(KeyList *klp);


/**
 * Append a new key string to KeyList
 *
 * @klp: pointer to a KeyList instance
 * @s: key string
 * ---
 * @ret: 0 Ok | 1 Error
 */
int keylist_append(KeyList *klp, const char *s);


/**
 * Delete a key from KeyList
 *
 * @klp: pointer to a KeyList
 * @key: key string
 * ---
 * @ret: 0 Ok | 1 Error
 */
int keylist_delete(KeyList *klp, const char *key);


/**
 * Print a KeyList to stdout
 * (Just for testing.)
 * 
 * @klp: Pointer to a KeyList
 */
void keylist_print(KeyList *klp);

#endif // KEYLIST_H
