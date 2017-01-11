/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 2
 */

#include "hw2.h"

/* Tests for Problem 1 */
void evidence_nth_harmonic()
{
    printf("*** testing nth_harmonic\n");
    printf("- expecting 0: %lf\n", nth_harmonic(0));
    printf("- expecting 1.5: %lf\n", nth_harmonic(2));
    printf("- expecting 2.283333333: %lf\n", nth_harmonic(5));
    printf("- expecting 1.5: %lf\n", nth_harmonic(10));
    printf("- expecting 0: %lf\n", nth_harmonic(100));
}

/* Tests for Problem 2 */
void evidence_harmonic_solve()
{
    printf("*** testing harmonic_solve\n");
    printf("- expecting 3: %d\n", harmonic_solve(1.78));
    printf("- expecting 1: %d\n", harmonic_solve(1));
    printf("- expecting 2: %d\n", harmonic_solve(1.5));
    printf("- expecting 3: %d\n", harmonic_solve(1.51));
    printf("- expecting 1: %d\n", harmonic_solve(-3));
}

/* Tests for Problem 3 */
void evidence_pi_approx()
{
    printf("*** testing pi_approx\n");
    printf("- expecting 0.000000: %lf\n", pi_approx(0));
    printf("- expecting 4.000000: %lf\n", pi_approx(1));
    printf("- expecting 3.732051: %lf\n", pi_approx(2));
    printf("- expecting 3.584220: %lf\n", pi_approx(3));
    printf("- expecting 3.151177: %lf\n", pi_approx(200));
    printf("- expecting 3.141791: %lf\n", pi_approx(10000));
    printf("%lf\n", pi_approx(100000000));
}

/* Tests for Problem 4 */
void evidence_circle()
{
    printf("*** testing circle\n");
    circle(0);
    circle(1);
    circle(5);
    circle(10);
}

/* Tests for Problem 55555 */
void evidence_triangles()
{
    printf("*** testing triangles\n");
    triangles(0, 0, 0);
    triangles(1, 1, 2);
    triangles(2, 3, 4);
    triangles(3, 3, 5);
    triangles(1, 2, 4);
}

/* Tests for Problem 6 */
void evidence_int_div()
{
    printf("*** testing int_div\n");
    unsigned int q;
    unsigned int r;
    int_div(10, 3, &q, &r);
    int_div(5, 2, &q, &r);
    int_div(6, 3, &q, &r);
    int_div(5, 2, &q, &r);
    //int_div(5, 0, &q, &r); tested error case
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_nth_harmonic();
    evidence_harmonic_solve();
    evidence_pi_approx();
    evidence_circle();
    evidence_triangles();
    evidence_int_div();
    return 0;
}
