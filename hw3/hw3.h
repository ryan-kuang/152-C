#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Problem 1
 * all_positive: returns a pseudo-boolean int
 * represents true only if all elements of array a
 * with length alen are positive
 */
int all_positive(int a[], unsigned int alen);

/* exists_positive: returns a pseudo-boolean int
 * represents true only if at least one element of the array is positive
 */
int exists_positive(int a[], unsigned int alen);

/* first_positive: returns index of the first positive element in the array
 * returns -1 if no element is positive
 */
int first_positive(int a[], unsigned int alen);

/* number_positives: returns number of positive elements in the array */
unsigned int number_positives(int a[], unsigned int alen);

/* negate: changes the sign of every element in the array
 * positive elements are updated to become negative elements
 * zero remains unchanged
 */
void negate(int a[], unsigned int alen);

/* partial_sums: returns new array containing partial sums over provided array
 * holds one more element than parameter array
 */
int* partial_sums(int a[], unsigned int alen);

/* rotate_right: modifies passed in array such that each value appears
 * one more spot to the right than in the previous array
 * last element becomes new first element
 */
void rotate_right(int a[], int alen);

/* Problem 2
 * factorization: given an integer, updates first elements of array factors
 * to contain the prime factors in monotonically increasing order
 * by increasing index
 * updates flen to be length of the result
 */
void factorization(unsigned int n, unsigned int factors[], unsigned int* flen);

/* Problem 3
 * decode: takes in array of code numbers and its length
 * returns string with decoded message
 */
char* decode(unsigned int a[], unsigned int alen);
