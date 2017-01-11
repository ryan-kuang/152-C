/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 3
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "waves.h"

/* evidence_dist: tests distance function */
void evidence_dist()
{
    printf("*** testing evidence_dist\n");
    printf("- expecting 5.000000: %lf\n", dist(0, 0, 3, 4));
    printf("- expecting 141.421356: %lf\n", dist(0, 0, 100, 100));
    printf("- expecting 5.099020: %lf\n", dist(0, 1, 1, 6));
    printf("- expecting 91.923882: %lf\n", dist(90, 10, 5, 45));
    printf("- expecting 1.581139: %lf\n", dist(2, 3, 1.5, 4.5));
}

/* main: runs tests above */
int main(int argc, char *argv[])
{
    evidence_dist();
    return 0;
}
