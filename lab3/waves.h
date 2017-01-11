#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* dist: takes in two pairs of x and y values
 * measures distance between the two pixels
 */
double dist(double x0, double y0, double x1, double y1);

/* draw_waves: generates a side_length x side_length image
 * with pattern of concentric blue circles
 */
void draw_waves(int side_length, int x_offset, int y_offset);
