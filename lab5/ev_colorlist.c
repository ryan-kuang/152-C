#include "color.h"
#include "colorlist.h"

/* Definitions */

void evidence_cl_cons()
{
    color *c1 = (color*)malloc(sizeof(color));
    c1->r = 1;
    c1->g = 2;
    c1->b = 3;
    color *c2 = (color*)malloc(sizeof(color));
    c2->r = 2;
    c2->g = 1;
    c2->b = 4;
    colorlist *root = (colorlist*)malloc(sizeof(colorlist));
    root->next = 0;
    root->c = *c2;
    colorlist *test_cl = (colorlist*)malloc(sizeof(colorlist));
    test_cl->c = *c1;
    test_cl->next = root;

    printf("*** testing cl_cons\n");
    colorlist *my_cl = cl_cons(c1, test_cl);
    cl_print(my_cl);
    printf("\n");
    colorlist *my_cl1 = cl_cons(c2, test_cl);
    cl_print(my_cl1);
    printf("\n");
    free(c1);
    free(c2);
    free(root);
    free(test_cl);
}

void evidence_cl_length()
{
    colorlist *test_cl = (colorlist*)malloc(sizeof(colorlist));
    color *c1 = (color*)malloc(sizeof(color));
    c1->r = 1;
    c1->g = 1;
    c1->b = 1;
    color *c2 = (color*)malloc(sizeof(color));
    c2->r = 0;
    c2->g = 0.5;
    c2->b = 0.7;
    test_cl->c = *c1;
    colorlist *root = (colorlist*)malloc(sizeof(colorlist));
    root->next = 0;
    root->c = *c2;
    test_cl->next = root;
    colorlist *my_cl = cl_cons(c1, test_cl);

    printf("*** testing cl_length\n");
    printf("- expecting 2: %d\n", cl_length(test_cl));
    printf("- expecting 3: %d\n", cl_length(my_cl));
    printf("\n");
    free(c1);
    free(c2);
    free(root);
    free(test_cl);
}

void evidence_cl_max_red()
{
    colorlist *test_cl = (colorlist*)malloc(sizeof(colorlist));
    color *c1 = (color*)malloc(sizeof(color));
    c1->r = 0.1;
    c1->g = 1;
    c1->b = 1;
    color *c2 = (color*)malloc(sizeof(color));
    c2->r = 0.12;
    c2->g = 0.5;
    c2->b = 0.7;
    test_cl->c = *c1;
    colorlist *root = (colorlist*)malloc(sizeof(colorlist));
    root->next = 0;
    root->c = *c2;
    test_cl->next = root;
    colorlist *my_cl = cl_cons(c2, test_cl);

    printf("*** testing cl_max_red\n");
    printf("- expecting 0.12: %lf\n", cl_max_red(test_cl));
    printf("- expecting 0.12: %lf\n", cl_max_red(my_cl));
    printf("\n");

    free(c1);
    free(c2);
    free(root);
    free(test_cl);
}

void evidence_cl_print()
{
    colorlist *test_cl = (colorlist*)malloc(sizeof(colorlist));
    color *c1 = (color*)malloc(sizeof(color));
    c1->r = 1;
    c1->g = 1;
    c1->b = 1;
    color *c2 = (color*)malloc(sizeof(color));
    c2->r = 0;
    c2->g = 0.5;
    c2->b = 0.7;
    test_cl->c = *c1;
    colorlist *root = (colorlist*)malloc(sizeof(colorlist));
    root->next = 0;
    root->c = *c2;
    test_cl->next = root;
    colorlist *my_cl = cl_cons(c1, test_cl);

    printf("*** testing cl_print\n");
    cl_print(test_cl);
    printf("\n");
    cl_print(my_cl);

    free(c1);
    free(c2);
    free(root);
    free(test_cl);
}

void evidence_cl_free()
{
    colorlist *test_cl = (colorlist*)malloc(sizeof(colorlist));
    color *c1 = (color*)malloc(sizeof(color));
    c1->r = 1;
    c1->g = 1;
    c1->b = 1;
    color *c2 = (color*)malloc(sizeof(color));
    c2->r = 0;
    c2->g = 0.5;
    c2->b = 0.7;
    test_cl->c = *c1;
    colorlist *root = (colorlist*)malloc(sizeof(colorlist));
    root->next = 0;
    root->c = *c2;
    test_cl->next = root;

    free(c1);
    free(c2);
    free(root);
    free(test_cl);

    cl_free(test_cl);
    printf("*** testing cl_free\n");
    cl_print(test_cl);
    printf("\n");
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_cl_cons();
    evidence_cl_length();
    evidence_cl_max_red();
    evidence_cl_print();
    evidence_cl_free();
    return 0;
}
