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

int main() {

    return 0;
}