#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct colorlist colorlist;

/* colorlist: linked list containing colors */
struct colorlist {
    color c;
    colorlist *next;
};

/* cl_cons: cons a color to colorlist */
colorlist *cl_cons(color *c, colorlist *cs);

/* cl_length: returns length of colorlist */
unsigned int cl_length(colorlist *cs);

/* cl_max_red: returns maximum red component of all colors
 * if the list is empty, raises an error
 */
double cl_max_red(colorlist *cs);

/* cl_print: prints colorlist */
void cl_print(colorlist *cs);

/* cl_free: frees colorlist */
void cl_free(colorlist *cs);
