#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

#define LINKEDLIST_ERROR   -1
#define LINKEDLIST_SUCCESS 0

typedef struct Node {
    int8_t      val;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
} LinkedList;

int linkedlist_init(LinkedList *llptr, int8_t val);
int linkedlist_append(LinkedList *llptr, int8_t val);
int linkedlist_prepend(LinkedList *llptr, int8_t val);
int linkedlist_insert(LinkedList *llptr, int8_t val, int8_t idx);
int linkedlist_lookup(LinkedList *llptr, int8_t target);
int linkedlist_print(LinkedList *llptr);

Node * _linkedlist_new_node(int8_t val);

#endif
