#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* xyz: structure definition for vectors */
typedef struct xyz {
    double x;
    double y;
    double z;
} xyz;

/* xyz_new: creates a vector, given x, y, z values*/
xyz *xyz_new(double x, double y, double z);

/* xyz_dup: create a new vector with same components as argument */
xyz *xyz_dup(xyz *v);

/* xyz_add: adds two vectors */
xyz *xyz_add(xyz *v1, xyz *v2);

/* xyz_sub: subtracts the second vector from the first */
xyz *xyz_sub(xyz *v1, xyz *v2);

/* xyz_sub: subtracts the second vector from the first */
xyz *xyz_sub(xyz *v1, xyz *v2);

/* xyz_neg: negate a vector */
xyz *xyz_neg(xyz *v);

/* xyz_scale: scale the components of a vector by scalar s */
xyz *xyz_scale(double s, xyz *v);

/* xyz_dot: compute the dot product of two vectors */
double xyz_dot(xyz *v1, xyz *v2);

/* xyz_mag: compute the magnitude of a vector */
double xyz_mag(xyz *v);

/* xyz_norm: normalize the vector */
xyz *xyz_norm(xyz *v);

/* xyz_tos: produce a string representation of a vector */
char *xyz_tos(xyz *v);

/* xyz_print: print the string representation of a vector */
void xyz_print(xyz *v);
