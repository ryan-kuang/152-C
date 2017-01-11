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

/* logical_loc: computes the logical location in the logical view plane
 * given a camera and location in the physical view
 */
location logical_loc(camera c, unsigned int x, unsigned int y)
{
    if (c.w > c.h) {
        double factor = 2.0/c.w;
        return xyz_expr((-1 + factor/2 + x*factor),
                        (1 - (2 - factor*c.h)/2.0 - factor/2 - factor*y),
                        0);
    } else if (c.w < c.h) {
        double factor = 2.0/c.h;
        return xyz_expr((-1 + (2 - factor*c.w)/2.0 + factor/2 + factor*x),
                        (1 - factor/2 - y*factor),
                        0);
    } else {
        double factor = 2.0/c.w;
        return xyz_expr((-1 + factor/2 + x*factor),
                        (1 - factor/2 - y*factor),
                        0);
    }
}

/* trace_ray: follows a ray from the camera to the scene
 * tests whether it intersects with an object
 * returns the color corresponding to the pixel at the closest intersection
 */

color trace_ray(scene s, ray r)
{
    hit_test closest_hit;
    hit_test hit1 = intersect(r, s.objects->obj);
    closest_hit = hit1;
    while (s.objects->next != NULL) {
        hit_test hit_next = intersect(r, s.objects->next->obj);
        if ((hit_next.miss == HIT && hit_next.t > 0 &&
             hit_next.t < closest_hit.t) ||
            closest_hit.miss == MISS) {
            closest_hit = hit_next;
        }
        s.objects = s.objects->next;
    }
    if (closest_hit.miss == HIT) {
        return closest_hit.surf;
    } else return s.bg;
}

/* render: prints ppm output to file f */
void render(FILE *f, stage g)
{
    camera c = g.c;
    scene s = g.s;
    location l;
    ray r;
    r.origin = c.loc;

    printf("P3 \n%d", c.w); //printing ppm image
    printf(" %d", c.h);
    printf(" \n255\n");

    int i, j;
    for (i = 0; i < c.w; i++) {
        for (j = 0; j < c.h; j++) {
            l = logical_loc(c, i, j);
            r.dir = xyz_norm(xyz_sub(l, r.origin));
            color new_color = trace_ray(s, r);
            color_show_bytes(f, new_color);
        }
    }
}
