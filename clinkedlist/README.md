## Linkedlist Reference

#### Structure
```C
struct Node {
    int data;
    *Node next;
}
```

#### Methods
`linkedlist_init(nodeptr *Node)` Initializes the structure

`linkedlist_destroy(nodeptr *Node)` Destructs the structure

`linkedlist_lookup(nodeptr *Node, int n)` Returns if any number `n` found in the structure

`linkedlist_append(nodeptr *Node, int n)` Appends new `Node` in the structure

`linkedlist_prepend(nodeptr *Node, int n)` Prepends new `Node` in the structure

`linkedlist_insert(nodeptr *Node, int n, int idx)` Inserts new `Node` in the structure on `index`

`linkedlist_remove(nodeptr *Node, int idx)` Removes `Node` located on `index` in the structure
