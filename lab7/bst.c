#include "adrbook.h"

const char *_bst_todo_format = "TODO [bst]: %s\nhalting\n";

/* bst_singleton: creates a BST consisting of one leaf node */
bst *bst_singleton(vcard *c)
{
    bst* new_bst = (bst*)malloc(sizeof(bst));
    if (new_bst == NULL) {
        fprintf(stderr, "bst_singleton: malloc failed\n");
        exit(1);
    }
    new_bst->c = c;
    new_bst->lsub = new_bst->rsub = NULL;
    return new_bst;
}

/* bst_insert: inserts a vcard into a non-empty BST
 * per cnet alphabetical order
 * raises an error if BST is empty
 */
int bst_insert(bst *t, vcard *c)
{
    if (t == NULL) {
        fprintf(stderr, "bst_insert: BST is empty\n");
        exit(1);
    }
    vcard* new_c = vcard_new(c->cnet, c->email, c->fname, c->lname, c->tel);
    bst* node = bst_singleton(new_c);
    while (t != NULL) {
        if (strcmp(c->cnet, t->c->cnet) > 0) {
            if (t->rsub == NULL) {
                t->rsub = node;
                return 1;
            }
            t = t->rsub;
        } else if (strcmp(c->cnet, t->c->cnet) < 0) {
            if (t->lsub == NULL) {
                t->lsub = node;
                return 1;
            }
            t = t->lsub;
        } else return 0;
    }
}


/* bst_num_entries: computes the total number of vcards in the tree */
unsigned int bst_num_entries(bst *t)
{
    unsigned int i = 0;
    if (t == NULL) {
        return 0;
    } else {
        i += 1 + bst_num_entries(t->lsub) + bst_num_entries(t->rsub);
    }
    return i;
}

/* bst_height: computes height of BST
 * empty tree has height 0
 */
unsigned int bst_height(bst *t)
{
    if (t == NULL) {
        return 0;
    } else {
        unsigned int ldepth = 0;
        unsigned int rdepth = 0;
        if (t->lsub != NULL) {
            ldepth = bst_height(t->lsub);
        }
        if (t->rsub != NULL) {
            rdepth = bst_height(t->rsub);
        }
        return fmax(ldepth, rdepth) + 1;
    }
}

/* bst_search: returns vcard and counts number of comparisons
 * returns NULL if nothing is found
 */
vcard *bst_search(bst *t, char *cnet, int *n_comparisons)
{
    int i = 0;
    n_comparisons = &i;
    if (t == NULL) {
        fprintf(stderr, "bst_search: empty tree\n");
        exit(1);
    } else {
        while (t != NULL) {
            if (strcmp(cnet, t->c->cnet) > 0) {
                i++;
                if (t->rsub == NULL) {
                    return NULL;
                }
                t = t->rsub;
            } else if (strcmp(cnet, t->c->cnet) < 0) {
                i++;
                if (t->lsub == NULL) {
                    return NULL;
                }
                t = t->lsub;
            } else return t->c;
        }
    }
}

/* inorder: prints strings in inorder traversal */
int inorder(FILE *f, bst *t, char c)
{
    int i = 0;
    if (t == NULL) {
        return 0;
    } else {
        i++;
        inorder(f, t->lsub, c);
        printf("%s\n", t->c->cnet);
        inorder(f, t->rsub, c);
    }
    return i;
}

/* bst_c: shows all cnet IDs that start with given character
 * in alphabetical order, and returns the number of
 * cnet IDs displayed
 */
unsigned int bst_c(FILE *f, bst *t, char c)
{
    if (t == NULL) {
        fprintf(stderr, "bst_c: BST is empty\n");
        exit(1);
    } else {
        while (t != NULL) {
            if (c == t->c->cnet[0]) {
                while (c == t->c->cnet[0]) {
                    return inorder(f, t, c);
                }
            } else if (strcmp(&c, t->c->cnet) > 0) {
                if (t->rsub == NULL) {
                    return 0;
                }
                t = t->rsub;
            } else if (strcmp(&c, t->c->cnet) < 0) {
                if (t->lsub == NULL) {
                    return 0;
                }
                t = t->lsub;
            }
        }
    }
}

/* bst_free: frees BST tree and all vcards */
void bst_free(bst *t)
{
    while (t != NULL) {
        bst_free(t->lsub);
        vcard_free(t->c);
        bst_free(t->rsub);
    }
}
