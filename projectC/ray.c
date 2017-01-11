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

/* =============================== */
/* === ray operations => ray.c === */
/* =============================== */

/* ray_position: interpreting direction as velocity, calculate position
 * of ray r after time t.
 */
xyz ray_position(ray r, double t)
{
    return xyz_add(r.origin, xyz_scale(t, r.dir));
}

//char *ray_tos(ray r);

//void ray_show(FILE *f, ray r);
