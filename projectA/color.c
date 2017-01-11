/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Project A
 * Professor Shaw
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* =================================== */
/* === color operations => color.c === */
/* =================================== */

/* reject if any component is outside [0.0,1.0] */
color color_expr(double r, double g, double b)
{
    if ((r < 0 || r > 1) || (g < 0 || g > 1) || (b < 0 || b > 1)) {
        fprintf(stderr, "input values must be between 0 and 1\n");
        exit(1);
    } else {
        color new_color = {r, g, b};
        return new_color;
    }
}

/* color_modulate : multiply the components or two colors */
/* (r,g,b) * (R,G,B) = (rR,gG,bB) */
color color_modulate(color c1, color c2)
{
    return color_expr(c1.r*c2.r, c1.g*c2.g, c1.b*c2.b);
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

/* color_scale : scale each component by given scalar, but */
/* don't allow any component in the result to fall outside [0,1] */
color color_scale(double s, color c)
{
    return (color_expr(within_bounds(0, 1, s*c.r),
                       within_bounds(0, 1, s*c.g),
                       within_bounds(0, 1, s*c.b)));
}

/* add components of colors, but */
/* don't allow any component in the result to exceed 1 */
color color_add(color c1, color c2)
{
    return (color_expr(within_bounds(0, 1, c1.r + c2.r),
                       within_bounds(0, 1, c1.g + c2.g),
                       within_bounds(0, 1, c1.b + c2.b)));
}

/* color_tos: produces a string representation of a color */
char *color_tos(color c)
{
    //color *c1 = color_expr(c.r, c.g, c.b);
    char str[128];
    for(int i = 0; i < 128; i ++) {
        str[i] = '\0';
    }
    sprintf(str, "(%f, %f, %f)", c.r, c.g, c.b);
    return strdup(str);
}

/* color_show: prints a string representation of a color */
void color_show(FILE *f, color c)
{
    fprintf(f, "color: {%f, %f, %f}", c.r, c.g, c.b);
}

/* color_show_bytes */
/* print three integers on [0,255] with spaces in between and a newline */
/* suitable for use in a PPM */
void color_show_bytes(FILE *f, color c)
{
    color c1 = color_scale(1, c);
    int a = round(255 * c1.r);
    int b = round(255 * c1.g);
    int d = round(255 * c1.b);
    fprintf(f, "%d %d %d\n", a, b, d);
}
