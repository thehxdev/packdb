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


KeyListNode *keylistnode_new(const char *name) {
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


void keylistnode_free(KeyListNode *knp) {
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
        keylistnode_free(node);
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

    KeyListNode *kn = keylistnode_new(name);
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


KeyListNode *keylist_find(KeyList *klp, const char *key) {
    if (is_null(klp) || is_null(key))
        return NULL;

    KeyListNode *tmp = klp->head;
    while (tmp) {
        if (strcmp(tmp->name, key) == 0)
            return tmp;
        tmp = tmp->next;
    }

    return tmp;
}


int keylist_delete(KeyList *klp, const char *key) {
    if (is_null(klp) || is_null(key))
        return 1;

    KeyListNode *tmp = keylist_find(klp, key);
    if (is_null(tmp))
        return 1;

    KeyListNode *before = tmp->prev;
    KeyListNode *after  = tmp->next;

    if (is_null(before)) {
        klp->head = after;
    } else {
        before->next = after;
    }

    if (is_null(after)) {
        klp->tail = before;
    } else {
        after->prev = before;
    }

    keylistnode_free(tmp);
    return 0;
}
