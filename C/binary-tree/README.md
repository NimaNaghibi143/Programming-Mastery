# Binary Tree

A hierarchical tree data structure in C, modelled loosely on a filesystem:
inner **nodes** form the skeleton (directories), and each node hangs a linked
list of **leaves** off its side (key/value entries). A global root is
statically allocated; everything below it lives on the heap.

## Layout

```
        root (Node)
          |
          v west
        Node ---east--> Leaf -> Leaf -> Leaf
          |
          v west
        Node ---east--> Leaf
```

- `north`  parent pointer (the root's `north` points to itself)
- `west`   child node (descend the tree)
- `east`   first leaf of a node, or next leaf in a leaf chain

## Files

| File       | Purpose                                                   |
| ---------- | --------------------------------------------------------- |
| `tree.h`   | Types, tags, and shared macros                            |
| `tree.c`   | Node/leaf allocators, traversal helpers, `main` demo      |
| `Makefile` | Build with `cc -Wall -O2 -std=c2x`                        |

## Types (`tree.h`)

```c
struct s_node {
    Tag tag;                // TagRoot | TagNode
    struct s_node *north;   // parent (root points to itself)
    struct s_node *west;    // child node
    struct s_leaf *east;    // first leaf
    int8 path[256];         // full path string
};

struct s_leaf {
    Tag tag;                // TagLeaf
    union u_tree *west;     // previous leaf, or owning node if first
    struct s_leaf *east;    // next leaf
    int8 key[128];
    int8 *value;            // heap-allocated, length `size`
    int16 size;
};

union u_tree { Node n; Leaf l; };
```

The union lets a single pointer refer to either a node or a leaf; the `tag`
byte at the head of both structs disambiguates the variant at runtime.

Tag bits:

| Macro     | Value | Meaning      |
| --------- | ----- | ------------ |
| `TagRoot` | `0x01`| Tree root    |
| `TagNode` | `0x02`| Inner node   |
| `TagLeaf` | `0x04`| Leaf entry   |

## API (`tree.c`)

- `Node *create_node(Node *parent, int8 *path)` — allocate a child node and
  link it as `parent->west`.
- `Leaf *create_leaf(Node *parent, int8 *key, int8 *value, int16 count)` —
  walk to the end of `parent`'s leaf chain (`find_last`) and append a new
  leaf with a copy of `value`.
- `Leaf *find_last_linear(Node *parent)` — `O(n)` walk to the tail of the
  leaf list. The `find_last` macro currently aliases this; a faster
  implementation can be swapped in by changing the macro.
- `void zero(int8 *str, int16 size)` — manual `memset`-to-zero helper.

Errors are signalled via `errno`; helpers return `NULL` (via the `reterr`
macro) on the error paths and `assert` on allocation failure.

## Build & Run

```sh
make         # produces ./tree
./tree       # runs the demo in main()
make clean   # remove tree and *.o
```

The bundled `main` creates two nested nodes and prints their addresses:

```c
n  = create_node((Node *)&root, (int8 *)"/Users");
n2 = create_node(n, (int8 *)"Users/login");
printf("%p %p\n", n, n2);
```