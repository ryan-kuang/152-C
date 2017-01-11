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
/* === sphere operations => sphere.c === */
/* ===================================== */

/* sphere_expr: creates new sphere */
sphere sphere_expr(location v, double r, color(*sc)(object *,location), color sh)
{

    sphere new_sph;
    new_sph.center = v;
    new_sph.radius = r;
    new_sph.surface_color = sc;
    new_sph.o = NULL;
    return new_sph;
}


char *sphere_tos(sphere s)
{
    int i;
    char buf[128];
    for(i=0; i<128; i++){
        buf[i]='\0';
    }
    sprintf(buf,"%f,%f,%f,%f,%f,%f,%f,",
            s.center.x,s.center.y,s.center.z,
            s.radius,s.shine.r,s.shine.g,s.shine.b);
    return strdup(buf);
    printf("\n");
}

void sphere_show(FILE *f, sphere s)
{
    fprintf(f,"%f,%f,%f,%f,%f,%f,%f,",
            s.center.x,s.center.y,s.center.z,
            s.radius,s.shine.r,s.shine.g,s.shine.b);
}
