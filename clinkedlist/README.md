## Linkedlist Reference

#### Structure
```C
struct Node {
    int         data;
    struct Node *next;
}

struct LinkedList {
    struct Node *head;
}
```

#### Methods
`linkedlist_init(Node *nodeptr, int8_t val)` Initializes the structure

`linkedlist_destroy(Node *nodeptr)` Destructs the structure

`linkedlist_lookup(Node *nodeptr, int8_t n)` Returns if any number `n` found in the structure

`linkedlist_append(Node *nodeptr, int8_t n)` Appends new `Node` in the structure

`linkedlist_prepend(Node *nodeptr, int8_t n)` Prepends new `Node` in the structure

`linkedlist_insert(Node *nodeptr, int8_t n, int idx)` Inserts new `Node` in the structure on `index`

`linkedlist_remove(Node *nodeptr, int8_t idx)` Removes `Node` located on `index` in the structure

#### Private Methods
`_linedlist_new_node(int8_t n)` Creates new `Node` structure
