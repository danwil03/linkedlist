#include "linkedlist.h"

int linkedlist_init(LinkedList *llptr, int8_t val) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *new_node = _linkedlist_new_node(val);
    llptr->head = new_node;

    return LINKEDLIST_SUCCESS;
}

int linkedlist_append(LinkedList *llptr, int8_t val) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *current_node = llptr->head;
    while(current_node->next != NULL) {
        current_node = current_node->next;
    }

    Node *new_node = _linkedlist_new_node(val);
    current_node->next = new_node;

    return LINKEDLIST_SUCCESS;
}

int linkedlist_lookup(LinkedList *llptr, int8_t target) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *current_node = llptr->head;
    while(current_node != NULL && current_node->val != target) {
        current_node = current_node->next;
    }

    if(current_node == NULL) {
        return LINKEDLIST_ERROR;
    }

    return LINKEDLIST_SUCCESS;
}

int linkedlist_insert(LinkedList *llptr, int8_t val, int8_t idx) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *current_node = llptr->head;
    int8_t current_idx = 0;
    while(current_idx < idx-1 && current_node->next != NULL) {
        current_node = current_node->next;
        current_idx += 1;
    }
    if(current_idx != idx-1) {
        return LINKEDLIST_ERROR;
    }
    Node *new_node = _linkedlist_new_node(val);
    Node *next_node = current_node->next;
    current_node->next = new_node;
    new_node->next = next_node;

    return LINKEDLIST_SUCCESS;
}

int linkedlist_remove(LinkedList *llptr, int8_t idx) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *current_node = llptr->head;
    int8_t current_idx = 0;
    while(current_idx < idx-1 && current_node->next != NULL) {
        current_node = current_node->next;
        current_idx += 1;
    }
    if(current_idx != idx-1) {
        return LINKEDLIST_ERROR;
    }
    Node *next_node = current_node->next->next;
    free(current_node->next);
    current_node->next = next_node;
    
    return LINKEDLIST_SUCCESS;
}

int linkedlist_print(LinkedList *llptr) {
    if(llptr == NULL) {
        return LINKEDLIST_ERROR;
    }

    Node *current_node = llptr->head;
    while(current_node != NULL) {
        printf("%i\n", current_node->val);
        current_node = current_node->next;
    }

    return LINKEDLIST_SUCCESS;
}

Node * _linkedlist_new_node(int8_t val) {
    Node *new_node = malloc(sizeof(Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

int main() {
    LinkedList *linkedlist;
    assert(linkedlist_init(linkedlist, 1) == LINKEDLIST_SUCCESS);
    assert(linkedlist_append(linkedlist, 2) == LINKEDLIST_SUCCESS);
    assert(linkedlist_append(linkedlist, 3) == LINKEDLIST_SUCCESS);
    assert(linkedlist_append(linkedlist, 4) == LINKEDLIST_SUCCESS);
    assert(linkedlist_append(linkedlist, 5) == LINKEDLIST_SUCCESS);

    printf("%i\n", linkedlist_lookup(linkedlist, 4));
    printf("%i\n", linkedlist_lookup(linkedlist, 7));

    assert(linkedlist_insert(linkedlist, 6, 3) == LINKEDLIST_SUCCESS);
    assert(linkedlist_print(linkedlist) == LINKEDLIST_SUCCESS);

    assert(linkedlist_remove(linkedlist, 3) == LINKEDLIST_SUCCESS);
    assert(linkedlist_print(linkedlist) == LINKEDLIST_SUCCESS);

    return 0;
}
