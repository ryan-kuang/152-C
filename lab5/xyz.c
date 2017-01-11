/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 5
 */

#include "xyz.h"

/* === vector operations === */
/* xyz_new: creates a vector, given x, y, z values*/
xyz *xyz_new(double x, double y, double z)
{
    xyz *my_xyz = (xyz*)malloc(sizeof(xyz));
    my_xyz->x = x;
    my_xyz->y = y;
    my_xyz->z = z;

    return my_xyz;
    free(my_xyz);
}

/* create a fresh vector with same components as argument */
xyz *xyz_dup(xyz *v)
{
    return xyz_new(v->x, v->y, v->z);
}

/* xyz_add: adds two vectors */
xyz *xyz_add(xyz *v1, xyz *v2)
{
    return xyz_new(v1->x + v2->x,
                   v1->y + v2->y,
                   v1->z + v2->z);
}

/* xyz_sub: subtracts the second vector from the first */
xyz *xyz_sub(xyz *v1, xyz *v2)
{
    return xyz_new(v1->x - v2->x,
                   v1->y - v2->y,
                   v1->z - v2->z);
}

/* xyz_neg: negate a vector */
xyz *xyz_neg(xyz *v)
{
    return xyz_new(-1*v->x, -1*v->y, -1*v->z);
}

/* xyz_scale: scale the components of a vector by scalar s */
xyz *xyz_scale(double s, xyz *v)
{
    return xyz_new(s*v->x, s*v->y, s*v->z);
}

/* xyz_dot: compute the dot product of two vectors */
double xyz_dot(xyz *v1, xyz *v2)
{
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

/* xyz_mag: compute the magnitude of a vector */
double xyz_mag(xyz *v)
{
    return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}

/* xyz_norm: normalizes the vector
 * returns vector if its magnitude is zero
 */
xyz *xyz_norm(xyz *v)
{
    if (xyz_mag == 0) {
        return xyz_dup(v);
    } else {
        return xyz_scale(1/xyz_mag(v), v);
    }
}

/* xyz_tos: produce a string representation of a vector */
char *xyz_tos(xyz *v)
{
    char vect_str[128];
    int i;
    for (i = 0; i < 128; i++) {
        vect_str[i] = '\0';
        sprintf(vect_str, "(%lf, %lf, %lf)", v->x, v->y, v->z);
        return strdup(vect_str);
    }
}

/* xyz_print: print the string representation of a vector */
void xyz_print(xyz *v)
{
    char* vect_str = xyz_tos(v);
    int i = 0;
    while (vect_str[i] != '\0') {
        printf("%c", vect_str[i]);
        i++;
    }
}
