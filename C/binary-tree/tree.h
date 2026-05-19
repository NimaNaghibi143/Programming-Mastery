/* tree.h */

#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <errno.h>

typedef unsigned int int32;
typedef unsigned short int int16;
typedef unsigned char int8;
struct s_node {
    struct s_node *north; /* if we are at the root node this *up points to itself*/
    struct s_node *west;
    struct s_leaf *east;
    int8 path[256]; /* contains the whole path*/
};
typedef struct s_node Node;

struct s_leaf {
    union u_tree *west;
    struct s_leaf *east;
    int8 key[128]; 
    int8 *value;
    int16 size; /* size of the value */
};
typedef struct s_leaf Leaf;

/* 
all the different vars in the union share the same mem space which means 
we only have one node or one leaf at the same time!
but in the structure we can have everything at the same time.
*/
union u_tree {
    Node n;
    Leaf l;
};
typedef union u_tree Tree;
