#ifndef KEYLIST_H
#define KEYLIST_H

typedef struct __key_node {
    char *name;
    struct __key_node *next;
    struct __key_node *prev;
} KeyNode;


typedef struct __key_list {
    KeyNode *head;
    KeyNode *tail;
} KeyList;


KeyList *keylist_new();

void keylist_free(KeyList *klp);

int keylist_append(KeyList *klp, const char *name);

void keylist_print(KeyList *klp);

#endif // KEYLIST_H
