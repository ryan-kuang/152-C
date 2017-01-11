#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* struct color: denotes color by red green and blue values */
typedef struct color {
    /* each value must be on interval [0,1] */
    double r;
    double g;
    double b;
} color;

/* === color operations === */

/* make_color: creates new color with given rgb values */
color *make_color(double r, double g, double b);

/* color_new: enforce that each value is on interval [0,1] */
color *color_new(double r, double g, double b);

/* color_dup: duplicates color */
color *color_dup(color *c);

/* color_modulate: multiply the components of two colors
 * (r,g,b) * (R,G,B) = (rR,gG,bB)
 */
color *color_modulate(color *c1, color *c2);

/* color_scale: scales each component by given scalar within [0,1] */
color *color_scale(double s, color *c);

/* color_add: adds components of colors without exceeding 1 */
color *color_add(color *c1, color *c2);

/* color_tos: produces a string representation of a color */
char *color_tos(color *c);

/* color_print: prints rgb values of a color */
void color_print(color *c);

/* color_print_bytes: prints three integer values on [0,255]
 * with spaces in between and a newline
 */
void color_print_bytes(color *c);
