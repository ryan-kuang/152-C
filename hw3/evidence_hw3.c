/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 3
 */

#include "hw3.h"

/* Defining arrays */
int a[] = {1, 2, 3, 4, 0};
int b[] = {-3, 0, 3, 4};
int c[] = {1, 2, 3, 4, 5, 6};
int d[] = {1, 2, 3, 4, 5, -6};
int e[] = {0};

/* Tests for Problem 1 */
void evidence_all_positive()
{
    printf("*** testing all_positive");
    printf("- expecting 0: %d\n", all_positive(a, 5));
    printf("- expecting 0: %d\n", all_positive(b, 4));
    printf("- expecting 1: %d\n", all_positive(c, 6));
    printf("- expecting 0: %d\n", all_positive(d, 6));
    printf("- expecting 0: %d\n", all_positive(e, 1));
}

void evidence_exists_positive()
{
    printf("*** testing exists_positive\n");
    printf("- expecting 1: %d\n", exists_positive(a, 5));
    printf("- expecting 1: %d\n", exists_positive(b, 4));
    printf("- expecting 1: %d\n", exists_positive(c, 6));
    printf("- expecting 1: %d\n", exists_positive(d, 6));
    printf("- expecting 0: %d\n", exists_positive(e, 1));
}

void evidence_first_positive()
{
    printf("*** testing first_positive\n");
    printf("- expecting 0: %d\n", first_positive(a, 5));
    printf("- expecting 2: %d\n", first_positive(b, 4));
    printf("- expecting 0: %d\n", first_positive(c, 6));
    printf("- expecting 0: %d\n", first_positive(d, 6));
    printf("- expecting -1: %d\n", first_positive(e, 1));
}

void evidence_number_positives()
{
    printf("*** testing number_positives\n");
    printf("- expecting 4: %d\n", number_positives(a, 5));
    printf("- expecting 2: %d\n", number_positives(b, 4));
    printf("- expecting 6: %d\n", number_positives(c, 6));
    printf("- expecting 5: %d\n", number_positives(d, 6));
    printf("- expecting 0: %d\n", number_positives(e, 1));
}

void evidence_negate()
{
    printf("*** testing negate\n");
    printf("- expecting {-1, -2, -3, -4, 0}: \n");
    negate(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    printf("- expecting {3, 0, -3, 4}: \n");
    negate(b, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d", b[i]);
    }
    printf("\n");
}

void evidence_partial_sums()
{
    printf("*** testing partial_sums\n");
    printf("- expecting {0, 1, 3, 6, 10, 15, 21}: \n");
    int* my_sums = partial_sums(c, 6);
    for (int i = 0; i <= 6; i++) {
        printf("%d", my_sums[i]);
    }
    printf("\n");
    printf("- expecting {0, 1, 3, 6, 10, 15, 9}: \n");
    int* my_sums1 = partial_sums(d, 6);
    for (int i = 0; i <= 6; i++) {
        printf("%d", my_sums1[i]);
    }
    printf("\n");
}

void evidence_rotate_right()
{
    printf("*** testing rotate_right\n");
    printf("- expecting {0, 1, 2, 3, 4}: \n");
    rotate_right(a, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
    printf("- expecting {4, -3, 0, 3}: \n");
    rotate_right(b, 4);
    for (int i = 0; i < 4; i++) {
        printf("%d", b[i]);
    }
    printf("\n");
}

/* Tests for Problem 2 */
void evidence_factorization()
{
    printf("*** testing factorization\n");
    printf("- expecting {2, 2, 3}: \n");
    unsigned int *array1, *array2, *array3, *array4, *array5;
    array1 = malloc(960);
    array2 = malloc(960);
    array3 = malloc(960);
    array4 = malloc(960);
    array5 = malloc(960);
    unsigned int p1, p2, p3, p4, p5;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    p5 = 0;
    factorization(12, array1, &p1);
    for (int i = 0; i < p1; i++) {
        printf("%d", array1[i]);
    }
    printf("\n");
    printf("- expecting {3, 3, 5, 7}: \n");
    factorization(315, array2, &p2);
    for (int i = 0; i < p2; i++) {
        printf("%d", array2[i]);
    }
    printf("\n");
    printf("- expecting {2, 2, 2, 3, 3, 3}: \n");
    factorization(216, array3, &p3);
    for (int i = 0; i < p3; i++) {
        printf("%d", array3[i]);
    }
    printf("\n");
    printf("- expecting {7}: \n");
    factorization(7, array4, &p4);
    for (int i = 0; i < p4; i++) {
        printf("%d", array4[i]);
    }
    printf("\n");
    printf("- expecting {}: \n");
    factorization(0, array5, &p5);
    for (int i = 0; i < p5; i++) {
        printf("%d", array5[i]);
    }
    printf("\n");
}

/* Tests for Problem 3 */
void evidence_decode()
{
    printf("*** testing decode\n");
    unsigned int i[] = {9, 0, 12, 15, 22, 5, 0, 3, 1, 20};
    unsigned int j[] = {4, 1, 4};
    char *my_decode = decode(j, 3);
    for(int i = 0; i < 3; i ++) {
        printf("%c", my_decode[i]);
    }
    printf("\n");
    char *my_decode1 = decode(i, 11);
    for(int i = 0; i < 10; i ++) {
        printf("%c", my_decode1[i]);
    }
    printf("\n");
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_all_positive();
    evidence_exists_positive();
    evidence_first_positive();
    evidence_number_positives();
    evidence_negate();
    evidence_partial_sums();
    evidence_rotate_right();
    evidence_factorization();
    evidence_decode();
    return 0;
}
