/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 4
 */

#include "hw4.h"

/* Definitions */
char* a = "hello world";

void evidence_array_char()
{
    printf("*** testing array_words\n");
    printf("- expecting hello: \n");
    char* my_string = array_char(a, ' ');
    for (int i = 0; i < strlen(a); i++) {
        printf("%c", my_string[i]);
    }
    printf("\n");
}

void evidence_prints_arrays()
{
    printf("*** testing prints_arrays\n");
    prints_arrays(a);
    printf("\n");
}

void evidence_num_delim()
{
    printf("*** testing num_delim\n");
    printf("%d", num_delim(a, ' '));
    printf("\n");
    printf("%d", num_delim(a, 'l'));
    printf("\n");
}

void evidence_make_array()
{
    printf("*** testing make_array");
    printf("- expecting world: \n");
    prints_arrays(make_array (a, 6));
    printf("\n");
}

void evidence_split_at()
{
    printf("*** testing split_at");
    printf("- expecting hello\nworld: \n");
    char** my_array = split_at(a, ' ');
    int i = 0;
    while (my_array[i] != NULL) {
        prints_arrays(my_array[i]);
        i++;
    }
    printf("\n");
}

/* evidence_add_measurements: testing add_measurements */
void evidence_add_measurements()
{
    struct measurement* m1 = (struct measurement*)malloc(sizeof(struct measurement));
    struct measurement* m2 = (struct measurement*)malloc(sizeof(struct measurement));
    struct measurement* m3 = (struct measurement*)malloc(sizeof(struct measurement));
    char x = 10;
    printf("*** testing add_measurements\n");
    m1->value = 1.0;
    m1->units = &x;
    m1->exponent = 1000;

    m2->value = 2.0;
    m2->units = &x;
    m2->exponent = 1000;

    *m3 = add_measurements(*m1, *m2);
    printf("expecting 3.0: %f\n", m3->value);

    m1->value = 3.0;
    m1->units = &x;
    m1->exponent = 1000;

    m2->value = 4.0;
    m2->units = &x;
    m2->exponent = 1000;

    *m3 = add_measurements(*m1, *m2);
    printf("expected 7.0, result : %f\n", m3->value);
}

/* evidence_scale_measurement: testing scale_measurements */
void evidence_scale_measurement()
{
    struct measurement* m1 = (struct measurement*)malloc(sizeof(struct measurement));
    struct measurement* m2 = (struct measurement*)malloc(sizeof(struct measurement));
    char x = 10;

    printf("*** testing scale_measurements\n");
    m1->value = 1.0;
    m1->units = &x;
    m1->exponent = 1;

    m2->value = 2.0;
    m2->units = &x;
    m2->exponent = 2;

    printf("expected 2.0: %f\n", scale_measurement(*m1, 2.0).value);
    printf("expected 6.0: %f\n", scale_measurement(*m2, 3.0).value);
}

/* evidence_multiply_measurements: testing multiply_measurements */
void evidence_multiply_measurements()
{
    struct measurement* m1 = (struct measurement*)malloc(sizeof(struct measurement));
    struct measurement* m2 = (struct measurement*)malloc(sizeof(struct measurement));
    char x = 10;

    printf("*** testing multiply_measurements\n");
    m1->value = 5.0;
    m1->units = &x;
    m1->exponent = 1;
    m2->value = 10.0;
    m2->units = &x;
    m2->exponent = 2;

    printf("expected 50.0: %f\n", multiply_measurements(*m1, *m2).value);
    printf("expected 3: %d\n", multiply_measurements(*m1, *m2).exponent);
}

/* measurement_tos: returns string-formatted version of the measurement,
 * consisting of the number, a space, the units, and a carat ^ and the exponent (if not 1)
 */
void evidence_measurement_tos()
{
    struct measurement* m1 = (struct measurement*)malloc(sizeof(struct measurement));
    char* x = "cm";
    m1->value = 5.0;
    m1->units = x;
    m1->exponent = 1;

    char* my_measurement = measurement_tos(*m1);
    printf("*** testing measurement_tos\n");
    int i = 0;
    while (my_measurement[i] != '\0') {
        printf("%c", my_measurement[i]);
        i++;
    }
    printf("\n");

    m1->value = 6.0;
    m1->units = x;
    m1->exponent = 3;

    char* my_measurement1 = measurement_tos(*m1);
    int j = 0;
    while (my_measurement1[j] != '\0') {
        printf("%c", my_measurement1[j]);
        j++;
    }
    printf("\n");
}

/* Problem 3 */

/* evidence_int_list_nth : testing int_list_nth */
void evidence_int_list_nth()
{
    printf("*** testing int_list_nth\n");
    int a[] = {1, 2, 3, 4, 5};
    struct int_arraylist array1;
    array1.a = a;
    array1.alen = 5;
    struct int_list xs;
    xs.tag = ARRAY;
    xs.u.array = array1;

    printf("expecting 2: %d\n", int_list_nth(xs, 1));
    printf("expecting 3: %d\n", int_list_nth(xs, 2));
    printf("expecting 5: %d\n", int_list_nth(xs, 4));

    struct int_linkedlist* root = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    root->val = 3;
    root->next = NULL; //NULL pointer
    struct int_linkedlist* node2 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node2->val = 2;
    node2->next = root;
    struct int_linkedlist* node1 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node1->val = 1;
    node1->next = node2;
    struct int_list xs1;
    xs1.tag = LINKED;
    xs1.u.linked = node1;

    printf("expecting 1: %d\n", int_list_nth(xs1, 0));
    printf("expecting 2: %d\n", int_list_nth(xs1, 1));
    printf("expecting 3: %d\n", int_list_nth(xs1, 2));

    free(root);
    free(node2);
    free(node1);
}

/* evidence_int_list_set : testing int_list_set */
void evidence_int_list_set()
{
    printf("*** testing int_list_set\n");
    int a[] = {1, 2, 3, 4, 5};
    struct int_list xs;
    struct int_arraylist array1;
    array1.a = a;
    array1.alen = 5;
    xs.tag = ARRAY;
    xs.u.array = array1;

    int_list_set(xs, 0, 2);
    int_list_set(xs, 1, 3);
    int_list_set(xs, 2, 4);
    int_list_set(xs, 3, 5);
    int_list_set(xs, 4, 6);
    printf("expecting {2, 3, 4, 5, 6}:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d", xs.u.array.a[i]);
    }
    printf("\n");
    int_list_set(xs, 1, 2);
    printf("expecting 2: %d\n", xs.u.array.a[1]);
    int_list_set(xs, 1, 3);
    printf("expecting 3: %d\n", xs.u.array.a[1]);

    struct int_linkedlist* root = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    root->val = 3;
    root->next = NULL;
    struct int_linkedlist* node2 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node2->val = 2;
    node2->next = root;
    struct int_linkedlist* node1 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node1->val = 1;
    node1->next = node2;
    struct int_list xs1;
    xs1.tag = LINKED;
    xs1.u.linked = node1;

    int_list_set(xs1, 0, 9);
    int_list_set(xs1, 1, 8);
    int_list_set(xs1, 2, 7);
    printf("expecting 9: %d\n", xs1.u.linked->val);
    printf("expecting 8: %d\n", xs1.u.linked->next->val);
    printf("expecting 7: %d\n", xs1.u.linked->next->next->val);
    int_list_set(xs1, 0, 2);
    printf("expecting 2: %d\n", xs1.u.linked->val);
    int_list_set(xs1, 0, 3);
    printf("expecting 3: %d\n", xs1.u.linked->val);

    free(root);
    free(node2);
    free(node1);
}

/* evidence_int_list_append : testing int_list_append */
void evidence_int_list_append()
{
    printf("*** testing int_list_append\n");
    int a[] = {1, 2, 3, 4, 5};
    struct int_list s;
    struct int_list* xs = &s;
    struct int_arraylist array1;
    array1.a = a;
    array1.alen = 5;
    xs->tag = ARRAY;
    xs->u.array = array1;

    int_list_append(xs, 1);
    printf("expecting 1: %d\n", xs->u.array.a[5]);
    int_list_append(xs, 2);
    printf("expecting 2: %d\n", xs->u.array.a[5]);
    int_list_append(xs, 3);
    printf("expecting 3: %d\n", xs->u.array.a[5]);

    struct int_linkedlist* root = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    root->val = 3;
    root->next = NULL;
    struct int_linkedlist* node2 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node2->val = 2;
    node2->next = root;
    struct int_linkedlist* node1 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node1->val = 1;
    node1->next = node2;
    struct int_list xs1;
    xs1.tag = LINKED;
    xs1.u.linked = node1;
    struct int_list* ptr_list = &xs1;

    int_list_append(ptr_list, 1);
    printf("expecting 1: %d\n", ptr_list->u.linked->next->val);
    int_list_append(ptr_list, 2);
    printf("expecting 2: %d\n", ptr_list->u.linked->next->next->val);
    int_list_append(ptr_list, 3);
    printf("expecting 3: %d\n", ptr_list->u.linked->next->next->val);

    free(root);
    free(node2);
    free(node1);
}

/* evidence_int_list_prepend: testing int_list_append */
void evidence_int_list_prepend()
{
    printf("*** testing int_list_prepend\n");
    int a[] = {1, 2, 3, 4, 5};
    struct int_list s;
    struct int_list* xs = &s;
    struct int_arraylist array1;
    array1.a = a;
    array1.alen = 5;
    xs->tag = ARRAY;
    xs->u.array = array1;

    int_list_prepend(xs, 1);
    printf("expecting 2: %d\n", xs->u.array.a[1]);
    int_list_prepend(xs, 2);
    printf("expecting 3: %d\n", xs->u.array.a[2]);
    int_list_prepend(xs, 3);
    printf("expecting 4: %d\n", xs->u.array.a[3]);

    struct int_linkedlist* root = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    root->val = 3;
    root->next = NULL;
    struct int_linkedlist* node2 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node2->val = 2;
    node2->next = root;
    struct int_linkedlist* node1 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node1->val = 1;
    node1->next = node2;
    struct int_list xs1;
    xs1.tag = LINKED;
    xs1.u.linked = node1;
    struct int_list* ptr_list = &xs1;

    int_list_prepend(ptr_list, 1);
    printf("expecting 2: %d\n", ptr_list->u.linked->next->val);
    int_list_prepend(ptr_list, 2);
    printf("expecting 3: %d\n", ptr_list->u.linked->next->next->val);
    int_list_prepend(ptr_list, 3);
    printf("expecting 4: %d\n", ptr_list->u.linked->next->next->val);

    free(root);
    free(node2);
    free(node1);

}

/* evidence_int_list_show: testing int_list_append */
void evidence_int_list_show()
{
    printf("*** testing int_list_show\n");
    int a[] = {1, 2, 3, 4, 5};
    struct int_list s;
    s.u.array.a = a;
    s.u.array.alen = 5;
    s.tag = ARRAY;
   /* struct int_list* xs = &s;
    struct int_arraylist array1;
    array1.a = a;
    array1.alen = 5;
    xs->tag = ARRAY;
    xs->u.array = array1; */

    int_list_show(s);
    printf("\n");
   // int_list_show(*xs);
     printf("\n");
   // int_list_show(xs);

    struct int_linkedlist* root = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    root->val = 3;
    root->next = NULL;
    struct int_linkedlist* node2 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node2->val = 2;
    node2->next = root;
    struct int_linkedlist* node1 = (int_linkedlist*)malloc(sizeof(int_linkedlist));
    node1->val = 1;
    node1->next = node2;
    struct int_list xs1;
    xs1.tag = LINKED;
    xs1.u.linked = node1;
    struct int_list* ptr_list = &xs1;

    //int_list_show(*ptr_list);
    int_list_show(xs1);

    free(root);
    free(node2);
    free(node1);
}


/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    //evidence_array_char();
    //evidence_prints_arrays();
    //evidence_num_delim();
    //evidence_make_array();
    evidence_split_at();
    evidence_add_measurements();
    evidence_scale_measurement();
    evidence_multiply_measurements();
    evidence_measurement_tos();
    evidence_int_list_nth();
    evidence_int_list_set();
    evidence_int_list_append();
    evidence_int_list_prepend();
    evidence_int_list_show();
    return 0;
}
