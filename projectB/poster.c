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


/* ===================================== */
/* === slab operations => poster.c ===== */
/* ===================================== */

poster poster_expr(location ulc, double w, double h, color(*sc)(object*,location), color sh)
{
    poster new_poster;
    new_poster.upper_left = ulc;
    new_poster.w = w;
    new_poster.h = h;
    new_poster.surface_color = sc;
    new_poster.shine = sh;
    new_poster.o = NULL;
    return new_poster;
}
