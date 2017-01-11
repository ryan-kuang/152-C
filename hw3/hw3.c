/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 3
 */
 
#include "hw3.h"

/* Problem 1
 * all_positive: returns a pseudo-boolean int
 * represents true only if all elements of array a
 * with length alen are positive
 */
int all_positive(int a[], unsigned int alen)
{
    int i = 0;
    while(i < alen) {
        if (a[i] > 0) {
            i++;
        } else {
            return 0;
            break;
        }
    }
    return 1;
}

/* exists_positive: returns a pseudo-boolean int
 * represents true only if at least one element of the array is positive
 */
int exists_positive(int a[], unsigned int alen)
{
	int i = 0;
    while (i < alen) {
        if (a[i] > 0) {
            return 1;
            break;
        } else {
            i++;
        }
    }
    return 0;
}

/* first_positive: returns index of the first positive element in the array
 * returns -1 if no element is positive
 */
int first_positive(int a[], unsigned int alen)
{
    int i;
    for (i = 0; i < alen; i++) {
        if (a[i] > 0) {
            return i;
            break;
        }
    }
    return -1;
}

/* number_positives: returns number of positive elements in the array */
unsigned int number_positives(int a[], unsigned int alen)
{
    int i = 0;
    int j = 0;
    while (i < alen) {
        if (a[i] > 0) {
            j++;
            i++;
        } else {
            i++;
        }
    }
    return j;
}

/* negate: changes the sign of every element in the array
 * positive elements are updated to become negative elements
 * zero remains unchanged
 */
void negate(int a[], unsigned int alen)
{
    int i;
    for (i = 0; i < alen; i++) {
        if (a[i] != 0) {
            a[i] *= (- 1);
        } else {
            a[i] = 0;
        }
    }
}

/* partial_sums: returns new array containing partial sums over provided array
 * holds one more element than parameter array
 */
int* partial_sums(int a[], unsigned int alen)
{
    int* my_array = (int*)malloc(sizeof(int) * (alen + 1));
    int sum = a[0];
    my_array[0] = 0;
    my_array[1] = a[0];
    for (int i = 2; i <= alen; i++) {
        sum += a[i - 1];
        my_array[i] = sum;
    }
    return my_array;
}

/* rotate_right: modifies passed in array such that each value appears
 * one more spot to the right than in the previous array
 * last element becomes new first element
 */
void rotate_right(int a[], int alen)
{
    int i;
    for (i = alen; i > 0; i--) {
        a[i] = a[i - 1];
    }
    a[0] = a[alen];
}

/* Problem 2
 * factorization: given an integer, updates first elements of array factors
 * to contain the prime factors in monotonically increasing order
 * by increasing index
 * updates flen to be length of the result
 */
void factorization(unsigned int n, unsigned int factors[], unsigned int* flen)
{
    int i = 0;
    int j;
    if (n > 1) {
        while (n % 2 == 0) { //reduces n to an odd number
            factors[i] = 2;
            i++;
            n = n/2;
            *flen = i;
        }
        for (j = 3; j <= n; j += 2) { //skip even factors since n is odd
            while (n % j == 0) {
                factors[*flen] = j;
                n = n/j;
                *flen += 1;
            }
        }
    }
}

/* Problem 3
 * decode: takes in array of code numbers and its length
 * returns string with decoded message
 */
char* decode(unsigned int a[], unsigned int alen)
{
    char *s = malloc(alen + 1);
    if(s == NULL) {
        fprintf(stderr, "error(decode): not enough memory\n");
        exit(1);
    }
    int i;
    for(i = 0; i < (alen + 1); i++) {
        if(i == alen) {
            s[i] = '\0';
        } else if(a[i] == 0) {
            s[i] = ' ';
        } else {
            s[i] = 'A' + a[i] - 1;
        }
    }
    return s;
}
