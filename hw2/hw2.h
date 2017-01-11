#include <stdlib.h>
#include <stdio.h>

/* nth_harmonic: takes an integer n
 * returns nth harmonic number as a double
 */
double nth_harmonic(unsigned int n);

/* harmonic_solve: finds the least value of n,
 * such that the nth harmonic number is at least x
 */
unsigned int harmonic_solve(double x);

/* pi_approx: takes in number of rectangles in Riemann sum
 * for integral representing a quarter of the unit circle
 * returns area of whole unit circle
 */
double pi_approx(unsigned int n);

/* circle: given radius, prints circle using asterisks and spaces
 */
void circle(unsigned int radius);

/* triangles: given number of rowns, columns and height of triangle,
 * prints pattern of repeating triangles using asterisks and spaces
 */
void triangles(unsigned int rows, unsigned int cols, unsigned int tri_height);

/* int_div: takes in a numberator and denominator,
 * produces the quotient and remainder as out-parameters
 */
void int_div(unsigned int n, unsigned int d, unsigned int* q, unsigned int* r);
