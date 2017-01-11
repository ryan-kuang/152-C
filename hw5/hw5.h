#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct intlist intlist;

struct intlist {
    int val;
    intlist* next;
};

intlist* intlist_remove_nth(intlist* xs, unsigned int n);

typedef struct inttree inttree;

struct inttree {
    int val;
    inttree *left, *right;
};

void inttree_inorder_show(inttree* t);
int inttree_aggregate(inttree* t);
void inttree_apply(inttree* t, int (*f)(int));

typedef struct tagged_tree tree;

struct node {
    tree *left, *right;
};

union tree_union {
    struct node node;
    char leaf;
};

enum tree_tag {
    NODE, LEAF
};

struct tagged_tree {
    enum tree_tag tag;
    union tree_union u;
};

tree* make_tree(char* leafs);

char* decode(tree* key, char* cipher);
