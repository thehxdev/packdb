#ifndef KEYTABLE_H
#define KEYTABLE_H

#include "keylist.h"

#define KEYTABLE_LEN (1 << 16)

typedef struct __table_node {

} TableNode;

typedef struct __key_table {
    TableNode *nodes[KEYTABLE_LEN];
    KeyList *keysList;
} KeyTable;

#endif // KEYTABLE_H
