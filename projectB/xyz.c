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

/* ================================== */
/* === vector operations => xyz.c === */
/* ================================== */

/* xyz_expr: makes vector */
xyz xyz_expr(double x, double y, double z)
{
    xyz my_vect = {x, y, z};
    /* my_vect.x = x;
     my_vect.y = y;
     my_vect.z = z;*/
    return my_vect;
}

/* xyz_add : add two vectors */
/* (x,y,z) + (X,Y,Z) = (x+X,y+Y,z+Z) */
xyz xyz_add(xyz v1, xyz v2)
{
    v1.x += v2.x;
    v1.y += v2.y;
    v1.z += v2.z;
    return v1;
}

/* xyz_sub : subtract the second vector from the first */
/* (x,y,z) - (X,Y,Z) = (x-X,y-Y,z-Z) */
xyz xyz_sub(xyz v1, xyz v2)
{
    v1.x -= v2.x;
    v1.y -= v2.y;
    v1.z -= v2.z;
    return v1;
}

/* xyz_neg : negate a vector */
/* -(x,y,z) = (-x,-y,-z) */
xyz xyz_neg(xyz v)
{
    v.x *= (-1);
    v.y *= (-1);
    v.z *= (-1);
    return v;
}

/* xyz_scale : scale the components of a vector by scalar s */
/* s(x,y,z) = (sx,sy,sz) */
xyz xyz_scale(double s, xyz v)
{
    v.x *= s;
    v.y *= s;
    v.z *= s;
    return v;
}

/* xyz_dot : compute the dot product of two vectors */
/* (x,y,z) dot (X,Y,Z) = xX+yY+zZ */
double xyz_dot(xyz v1, xyz v2)
{
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

/* xyz_mag : compute the magnitude of a vector */
/* the square root of the sum of the squares of the components */
double xyz_mag(xyz v)
{
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

/* xyz_norm : normalize the vector */
/* i.e., a vector pointing in the same direction whose magnitude is 1 */
/* - normalize a vector by scaling by 1 over its magnitude */
/* - if a vector's magnitude is zero, it can't be normalized; return it */
xyz xyz_norm(xyz v)
{
    return xyz_scale(1/xyz_mag(v), v);
}

/* xyz_dist : computes the distance between two locations */
double xyz_dist(location v1, location v2)
{
    return sqrt((v2.x - v1.x)*(v2.x - v1.x) +
                (v2.y - v1.y)*(v2.y - v1.y) +
                (v2.z - v1.z)*(v2.z-v1.z));
}

/* xyz_tos: produce a string representation of a vector */
char *xyz_tos(xyz v)
{
    char vect_str[128];
    int i;
    for (i = 0; i < 128; i++) {
        vect_str[i] = '\0';
        sprintf(vect_str, "(%lf, %lf, %lf)", v.x, v.y, v.z);
        return strdup(vect_str);
    }
}

/* xyz_show: print the string representation of a vector */
void xyz_show(FILE *f, xyz v)
{
    char* vect_str = xyz_tos(v);
    int i = 0;
    while (vect_str[i] != '\0') {
        fprintf(f, "%c", vect_str[i]);
        i++;
    }
}
