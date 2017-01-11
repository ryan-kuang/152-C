/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 2
 */

#include "hw2.h"

double nth_harmonic(unsigned int n)
{
    if (n == 0) {
        return 0;
    } else {
        double sum = 0;
        int i;
        for (i = 1; i <= n; i++) {
            sum += (1.0 / i);
        }
        return sum;
    }
}

unsigned int harmonic_solve(double x)
{
    double sum = 0;
    int i;
    if (x > 1) {
        for (i = 1; sum < x; i++) {
            sum += (1.0 / i);
        }
        return (i - 1);
    } else {
        return 1;
    }
}

double pi_approx(unsigned int n)
{
    if (n == 0) {
        return 0;
    } else {
        double sum = 0;
        int i;
        double x = 0;
        for (i = 1; i <= n; i++) {
        sum += (1.0 / n) * sqrt(1 - x * x);
            x += (1.0 / n);
        }
        return 4 * sum;
    }
}

void circle(unsigned int radius)
{
    int x, y;
    for (y = 2 * radius; y >= 0; y--) {
        for (x = 0; x <= 2 * radius; x++) {
            if ((x - radius) * (x - radius) +
                (y - radius) * (y - radius) <= radius * radius) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void triangles(unsigned int rows, unsigned int cols, unsigned int tri_height)
{
    int l;
    int m;
    int k;
    for(k = 0; k < rows; k++) {
        for(m = 0; m < tri_height; m++) {
            for(l = 0; l < cols; l++) {
                int n = 0;
                while(n < tri_height) {
                    while(n <= m) {
                        printf("*");
                        n++;
                    }
                    printf(" ");
                    n++;
                }
            }
            printf("\n");
        }
    }
}

void int_div(unsigned int n, unsigned int d, unsigned int* q, unsigned int* r)
{
    if (d != 0) {
        int x;
        for (x = 1; d <= n; x++) {
            n -= d;
            *q = x;
        }
        *r = n;
    } else {
        fprintf(stderr, "error (int_div): cannot divide by zero\n");
        exit(1);
    }
    printf("quotient: %d\n", *q);
    printf("remainder: %d\n", *r);
}
