/* tree.c */
#include "tree.h"

Tree root = { .n = {
    .tag = (TagRoot | TagNode), /* the root is a node */
    .north = (Node *)&root,
    .west = 0,
    .east = 0,
    .path = "/"
}
};

void zero(int8 *str, int16 size) {
    int8 *p;
    int16 n;

    for (n=0, p=str; n < size; p++, n++)
        *p = 0;

    return;
}

Node *create_node(Node *parent, int8 *path) {
    Node *n;
    int16 size;

    errno = NoError;
    assert(parent);
    size = sizeof(struct s_node);
    n = (Node *)malloc((int)size);
    zero((int8 *)n, size);

    parent->west = n;
    n->tag = TagNode;
    n->north = parent;
    strncpy((char *)n->path, (char *)path, 255);

    return n;
}

Leaf *find_last_linear(Node *parent) {
    Leaf *l;
    
    errno = NoError;
    assert(parent);

    if (!parent->east) 
        reterr(NoError);

    for (l = parent->east; l->east; l = l->east);
    assert(l); 

    return l;
}

Leaf *create_leaf(Node *parent, int8 *key, int16 size) {
    Leaf *l;
    Node *n;

    assert(west);
    
    
}

int main() {
    Node *n, *n2;
 
    n = create_node((Node *)&root, (int8 *)"/Users");
    assert(n);
    n2 = create_node(n, (int8 *)"Users/login");
    assert(n2);

    printf("%p %p\n", n, n2);
    free(n2);
    free(n);

    return 0;
}