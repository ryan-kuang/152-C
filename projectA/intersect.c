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


/* === Intersection Testing === */

/* within_poster: returns 1 if true, 0 if false */
int within_poster(location pos, poster p)
{
    if ((pos.x >= p.upper_left.x)&&
        (pos.x <= p.upper_left.x + p.w)&&
        (pos.y <= p.upper_left.y) &&
        (pos.y >= p.upper_left.y - p.h)) {
        return 1;
    } else {
        return 0;
    }
}

/* hit_test: testing whether rays intersect objects */
hit_test intersect(ray r, object obj)
{
    hit_test hit;
    if (obj.tag == SPHERE) {
        location A = xyz_sub(r.origin, obj.o.s.center);
        double B = xyz_dot(A, xyz_norm(r.dir));
        double C = xyz_dot(A, A) - (obj.o.s.radius*obj.o.s.radius);
        double D = B * B - C;
        double t = -1*B - sqrt(D);

        if ((D > 0)&&(t > 0)) {
            hit.miss = 1;
            hit.t = t;
            hit.hit_point = ray_position(r, t);
            hit.surf = obj.o.s.surface_color(&obj, hit.hit_point);
        } else {
            hit.miss = 0;
            hit.t = 0;
        }
    } else if (obj.tag == POSTER) {
        xyz n = {0, 0, -1};
        double d = fabs(obj.o.p.upper_left.z);
        double t = -((xyz_dot(r.origin, n) + d))/xyz_dot(xyz_norm(r.dir), n);

        if ((t > 0)&&(within_poster(ray_position(r, t), obj.o.p) == 1)) {
            hit.miss = 1;
            hit.t = t;
            hit.hit_point = ray_position(r, t);
            hit.surf = obj.o.p.surface_color(&obj, hit.hit_point);
        } else {
            hit.miss = 0;
            hit.t = 0;
        }
    }
    return hit;
}
