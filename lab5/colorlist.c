/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 5
 */

#include "color.h"
#include "colorlist.h"

/* === colorlist operations === */
/* cl_cons: cons a color to a colorlist */
colorlist *cl_cons(color *c, colorlist *cs)
{
    colorlist *my_cl = (colorlist*)malloc(sizeof(colorlist));
    my_cl->c = *c; //why is this * and not the pointer itself?
    my_cl->next = cs;
    return my_cl;
    free(my_cl);
}

/* cl_length: calculates length of colorlist */
unsigned int cl_length(colorlist *cs)
{
    int counter = 1;
    if (cs != 0) {
        while (cs->next != 0) {
            counter += 1;
            cs = cs->next;
        }
    return counter;
}
}

/* return the maximum red component of all colors
 * if the list is empty, raises an error
 */
double cl_max_red(colorlist *cs)
{
    double max = 0;
    if (cs != 0) {
        while (cs->next != 0) {
            if (cs->c.r > max) {
                max = cs->c.r;
                cs = cs->next;
            } else {
                cs = cs->next;
            }
        }
        if (cs->c.r > max) {
            max = cs->c.r;
        }
    } else {
        fprintf(stderr, "error(cl_max_red): colorlist is empty\n");
        exit(1);
    }
    return max;
}

/* cl_print: prints colorlist */
void cl_print(colorlist *cs)
{
    while (cs->next != 0) {
        printf("red: %lf green: %lf blue: %lf\n", cs->c.r, cs->c.g, cs->c.b);
        cs = cs->next;
    }
    printf("red: %lf green: %lf blue: %lf\n", cs->c.r, cs->c.g, cs->c.b);
}

/* cl_free: frees colorlist */
void cl_free(colorlist *cs)
{
    free(cs);
    cs = NULL;
   /* colorlist *temp;
    while (cs != 0) {
        temp = cs;
        cs = cs->next;
        free(temp);
    }*/
}
