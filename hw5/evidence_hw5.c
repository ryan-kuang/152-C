/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 5
 */

#include "hw5.h"

void evidence_intlist_remove_nth()
{
    printf("*** Testing intlist_remove_nth ***\n");

    /* test intlist */
    intlist* node1 = (intlist*)malloc(sizeof(intlist));
    node1->val = 1;
    node1->next = 0;
    intlist* node2 = (intlist*)malloc(sizeof(intlist));
    node2->val = 5;
    node2->next = node1;
    intlist* node3 = (intlist*)malloc(sizeof(intlist));
    node3->val = 2;
    node3->next = node2;

    intlist* test_intlist = intlist_remove_nth(node3, 1);

    printf("expecting 2: %d\n", test_intlist->val);
    printf("expecting 1: %d\n", test_intlist->next->val);

   /* free(node1);
    free(node2);
    free(node3);
    node1 = NULL;
    node2 = NULL;
    node3 = NULL;*/
}

void evidence_inttree_inorder_show()
{
    printf("*** Testing inttree_inorder_show ***\n");

    /* test tree */
    inttree* tree1 = (inttree*)malloc(sizeof(inttree));
    tree1->val = 1;
    inttree* tree2 = (inttree*)malloc(sizeof(inttree));
    tree2->val = 5;
    inttree* tree3 = (inttree*)malloc(sizeof(inttree));
    tree3->val = 2;
    tree3->left = tree1;
    tree3->right = tree2;

    printf("expecting 1 2 5:\n");
    inttree_inorder_show(tree3);
    printf("\n");

   /* free(tree1);
    free(tree2);
    free(tree3);
    tree1 = NULL;
    tree2 = NULL;
    tree3 = NULL;*/
}

void evidence_inttree_aggregate()
{
    printf("*** Testing inttree_aggregate ***\n");

    /* test tree */
    inttree* tree1 = (inttree*)malloc(sizeof(inttree));
    tree1->val = 1;
    inttree* tree2 = (inttree*)malloc(sizeof(inttree));
    tree2->val = 5;
    inttree* tree3 = (inttree*)malloc(sizeof(inttree));
    tree3->val = 2;
    tree3->left = tree1;
    tree3->right = tree2;

    printf("expecting 8: %d\n", inttree_aggregate(tree3));

    /*free(tree1);
    free(tree2);
    free(tree3);*/
}

/* test function */
int add1(int n)
{
    return n+1;
}

void evidence_inttree_apply()
{
    printf("*** Testing inttree_apply ***\n");

    /* test tree */
    inttree* tree1 = (inttree*)malloc(sizeof(inttree));
    tree1->val = 1;
    inttree* tree2 = (inttree*)malloc(sizeof(inttree));
    tree2->val = 5;
    inttree* tree3 = (inttree*)malloc(sizeof(inttree));
    tree3->val = 2;
    tree3->left = tree1;
    tree3->right = tree2;

    inttree_apply(tree3, add1);

    printf("expecting 3: %d\n", tree3->val);
    printf("expecting 6: %d\n", tree3->right->val);
    printf("expecting 2: %d\n", tree3->left->val);

    free(tree1);
    free(tree2);
    free(tree3);
}

void evidence_make_tree()
{
    printf("*** Testing make_tree ***\n");
    char buf[128];
    for (int i=0;i<128;i++){
        buf[i] = '\0';
    }
    sprintf(buf, "ab");
    strdup(buf);
    tree *t = malloc(sizeof(tree));
    *t = *make_tree(buf);
    if(t->u.node.left->tag==LEAF){
        printf("%c", t->u.node.left->u.leaf);
    }else{
        printf("no, not a leaf\n");
    }
    printf("\n");
}

void evidence_decode()
{
    printf("*** Testing decode ***\n");
    char cipher[128];
    for (int i=0;i<128;i++){
        cipher[i] = '\0';
    }
    sprintf(cipher, "LLLLLLLL");
    strdup(cipher);
    tree *t = malloc(sizeof(tree));
    *t = *make_tree("ABDE");

    char decoded[556];
    for (int j=0;j<556;j++){
        decoded[j] = '\0';
    }
    sprintf(decoded, "%s", decode(t, cipher));
    strdup(decoded);

    printf("%s\n", decoded);
    printf("\n");
    free(t);
}

int main(int argc, char *argv[])
{
    evidence_intlist_remove_nth();
    evidence_inttree_inorder_show();
    evidence_inttree_aggregate();
    evidence_inttree_apply();
    evidence_make_tree();
    evidence_decode();
    return 0;
}
