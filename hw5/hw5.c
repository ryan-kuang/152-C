/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 5
 */

#include "hw5.h"

/* Problem 1 */
/* intlist_remove_nth: removes the nth element from the linked list
 * whose head is provided
 */
intlist* intlist_remove_nth(intlist* xs, unsigned int n)
{
    intlist* xs1 = malloc(sizeof(intlist));
    intlist* final = malloc(sizeof(intlist));
    if (n == 0) {
        if (xs == NULL) {
            fprintf(stderr, "n is greater than number of items in the list\n");
            exit(1);
        }
        final = xs->next;
        return final;
    }
    while (n != 1) {
        if ( xs == NULL ) {
            fprintf(stderr, "n is greater than number of items in the list\n");
            exit(1);
        }
        final->val = xs->val;
        final->next = xs->next;
        xs = xs->next;
        final = final->next;
        n--;
    }
    xs1 = xs->next;
    if (xs1 == NULL) {
        final->val = xs->val;
        return final;
    } else {
        final->val = xs->val;
        final->next = xs1->next;
        return final;
    }
}

/* Problem 2 */
/* inttree_inorder_show: prints in-order traversal of a given tree */
void inttree_inorder_show(inttree* t)
{
    if (t != NULL) {
        inttree_inorder_show(t->left);
        printf("%d ", t->val);
        inttree_inorder_show(t->right);
    }
}

/* inttree_aggregate: modifies a tree to aggregate its values upwards */
int inttree_aggregate(inttree* t)
{
    if (t == NULL) {
        return 0;
    }
    int old_val = t->val;
    t->val = inttree_aggregate(t->left) + inttree_aggregate(t->right);
    return t->val + old_val;
}

/* inttree_apply: modifies the provided tree by updating the value at each node
 * to be the result obtained by calling the passed-in function
 */
void inttree_apply(inttree* t, int (*f)(int))
{
    if (t != NULL) {
        inttree_apply(t->left, f);
        t->val = f(t->val);
        inttree_apply(t->right, f);
    }
}

/* Problem 3 */
/* Power_2 : checks if an integer is a power of 2 */
int Power_2 (int n)
{
    while (n % 2 == 0 && n > 1) {
        n /= 2;
    }
    if (n == 1) {
        return 1;
    } else return 0;
}

/* make_tree: given a string containing character values of the leafs,
 * reconstructs a binary tree
 */
tree* make_tree(char* leafs)
{
    int slen = strlen(leafs);
    tree *t = malloc(sizeof(tree));

    if (Power_2(slen) != 1) {
        fprintf(stderr, "error, cannot make tree with odd number of leafs\n");
        exit(1);
    }
    if (slen == 1) {
        t->tag = LEAF;
        t->u.leaf = *leafs;
    } else {
        char* buf = malloc(sizeof(char)*(slen));
        char* left_side = memcpy(buf, leafs + slen/2, slen/2);
        char* right_side = memcpy(buf, leafs, slen/2);
        t->tag = NODE;
        t->u.node.left=make_tree(left_side);
        t->u.node.right=make_tree(right_side);
    }
    return t;
}

/* Problem 4 */
/* decode: decodes the specified message
 * given a key
 */
char* decode(tree* key, char* cipher)
{
    tree* t = key;
    int i = 0;
    char buf[128];
    for(int j = 0; j < 128; j++){
        buf[j]='\0';
    }
    while(cipher[i]!='\0'){
        tree* new_t = t;
        if (new_t -> tag == LEAF) {
            sprintf(buf, "%c", new_t->u.leaf);
            new_t = t;
            i++;
        }
        if (cipher[i] == 'L') {
            new_t=new_t->u.node.left;
            i++;
        } else if (cipher[i] == 'R') {
            new_t = new_t->u.node.right;
            i++;
        } else {
            i++;
        }
    }
    return strdup(buf);
}
