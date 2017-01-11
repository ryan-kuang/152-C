/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "color.h"

/* === color operations === */

/* make_color: creates new color with given rgb values */
color *make_color(double r, double g, double b)
{
    color *c = (color*)malloc(sizeof(color)); //is this necessary
    if (c == NULL) {
        fprintf(stderr, "error(color_new): not enough memory\n");
        exit(1);
    }
    c->r = r;
    c->g = g;
    c->b = b;
    return c;
    free(c);
}

/* color_new: creates new color
 * returns error if value is not in interval [0,1]
 */
color *color_new(double r, double g, double b)
{
    if ((r < 0 || r > 1) || (g < 0 || g > 1) || (b < 0 || b > 1)) {
        fprintf(stderr, "input values must be between 0 and 1\n");
        exit(1);
    } else {
        return make_color(r, g, b);
    }
}

/* color_dup: duplicates color */
color *color_dup(color *c)
{
    return make_color(c->r, c->g, c->b);
}

/* color_modulate: multiply the components of two colors
 * (r,g,b) * (R,G,B) = (rR,gG,bB)
 */
color* color_modulate(color *c1, color *c2)
{
    return make_color(c1->r * c2->r, c1->g * c2->g, c1->b * c2->b);
}

/* within_bounds: tests whether a value is below 0 or above 1
 * helper function for color_scale
 */
double within_bounds(int lower, int upper, double s)
{
    if (s > upper) {
        return upper;
    } else if (s < lower) {
        return lower;
    }
    return s;
}

/* color_scale: scales each component by given scalar
 * without exceeding [0,1]
 */
color* color_scale(double s, color *c)
{
    return (make_color(within_bounds(0, 1, s * c->r),
                      within_bounds(0, 1, s * c->g),
                      within_bounds(0, 1, s * c->b)));
}

/* color_add: adds components of colors
 * without exceeding [0,1]
 */
color *color_add(color *c1, color *c2)
{
    return (make_color(within_bounds(0, 1, c1->r + c2->r),
                      within_bounds(0, 1, c1->g + c2->g),
                      within_bounds(0, 1, c1->b + c2->b)));
}

/* color_tos: produces a string representation of a color */
char* color_tos(color *c)
{
    color *c1 = make_color(c->r, c->g, c->b);
    char str[128];
    for(int i = 0; i < 128; i ++) {
        str[i] = '\0';
    }
    sprintf(str, "(%f, %f, %f)", c1->r, c1->g, c1->b);
    return strdup(str);
}

/* color_print: prints rgb values of a color */
void color_print(color *c)
{
    printf("color: (%f, %f, %f)\n", c->r, c->g, c->b);
}

/* color_print_bytes: prints three integer values on [0,255]
 * with spaces in between and a newline
 */
void color_print_bytes(color *c)
{
    color *c1 = color_scale(1, c);
    int a = round(255 * c1->r);
    int b = round(255 * c1->g);
    int d = round(255 * c1->b);
    printf("%d %d %d\n", a, b, d);
}
