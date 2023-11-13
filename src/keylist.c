/*
 * File: keylist.c
 * Desc: Implementation of functions defined in `keylist.h` file.
 * Author: Hossein Khosravi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keylist.h"
#include "general.h"
#include "str.h"


KeyListNode *KeyListNode_new(const char *name) {
    KeyListNode *kn = (KeyListNode*) malloc(sizeof(KeyListNode));
    if (!kn)
        return NULL;

    kn->name = strdup(name);
    if (is_null(kn->name)) {
        free(kn);
        return NULL;
    }

    kn->next = kn->prev = NULL;
    return kn;
}


void KeyListNode_free(KeyListNode *knp) {
    if (knp) {
        check_then_free(knp->name);
        free(knp);
    }
}


KeyList *keylist_new() {
    KeyList *kl = (KeyList*) malloc(sizeof(KeyList));
    if (is_null(kl))
        return NULL;

    kl->head = NULL;
    kl->tail = NULL;

    return kl;
}


static void keylist_free_helper(KeyListNode *node) {
    if (node != NULL) {
        keylist_free_helper(node->next);
        KeyListNode_free(node);
    }
}


void keylist_free(KeyList *klp) {
    if (klp) {
        keylist_free_helper(klp->head);
        free(klp);
    }
}


int keylist_append(KeyList *klp, const char *name) {
    if (is_null(klp) || is_null(name))
        return 1;

    KeyListNode *kn = KeyListNode_new(name);
    if (is_null(klp->head)) {
        klp->head = klp->tail = kn;
        return 0;
    }

    KeyListNode *last = klp->tail;

    kn->prev = klp->tail;
    if (last)
        last->next = kn;
    klp->tail = kn;
    return 0;
}


void keylist_print(KeyList *klp) {
    KeyListNode *tmp = klp->head;
    printf("[ ");
    while (tmp) {
        printf("\"%s\", ", tmp->name);
        tmp = tmp->next;
    }
    printf("]\n");
}


// TODO: Implement keylist_delete
int keylist_delete(KeyList *klp, const char *key);
