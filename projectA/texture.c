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

/* poster_red_distance - calculate distance from upper-left-corner, use to
 * scale from black at upper-left to red at lower-right
 */
color poster_red_distance(object *o, location loc)
{
    double dist = xyz_dist(o->o.p.upper_left, loc);
    double diag = sqrt(o->o.p.w*o->o.p.w+o->o.p.h*o->o.p.h);
    color new_color = color_expr(dist/diag, 0.0, 0.0);
    return new_color;
}

/* poster_rgb_distance - calculate distance from upper-left-corner, use to
 * scale from all red at upper-left to all blue at lower-right, with
 * green in the middle, and gradations between them.
 */
/* ^^ edit: said "blue at lower-left", corrected to "at lower-right" */
color poster_rgb_distance(object *o, location loc)
{
    double dist1 = fabs(xyz_dist(loc, o->o.p.upper_left));
    double dist2 = fabs(xyz_dist(loc, xyz_expr(o->o.p.upper_left.x +
                                          o->o.p.w,
                                          o->o.p.upper_left.y -
                                          o->o.p.h,
                                          o->o.p.upper_left.z)));
    double diag = sqrt(o->o.p.w*o->o.p.w+o->o.p.h*o->o.p.h);

    if (dist1 <= diag/2.0) {
        color new_color = color_expr(1.0 - dist1/(diag/2.0), dist1/(diag/2.0), 0);
    } else if (dist2 <= diag/2) {
        color new_color = color_expr(0, 1.0 - dist2/(diag/2.0), dist2/(diag/2.0));
    } else {
        color new_color = color_expr(0, 1, 0);
    }
}

/* sphere_loc_to_rgb - scale the location so that it maps x, y, z onto r, g, b in
 * a way that shows gradations in the sphere. You are being given flexibility to
 * do this in a way that looks interesting to you.
 */
color sphere_loc_to_rgb(object *o, location loc)
{
    sphere s = o->o.s;
    xyz rloc = xyz_expr(s.center.x - s.radius*cos(M_PI/6), s.center.y + s.radius*sin(M_PI/6), s.center.z);
    xyz gloc = xyz_expr(s.center.x + s.radius*cos(M_PI/6), s.center.y + s.radius*sin(M_PI/6), s.center.z);
    xyz bloc = xyz_expr(s.center.x, s.center.y - s.radius, s.center.z);
    double rdist = xyz_dist(loc, rloc);
    double gdist = xyz_dist(loc, gloc);
    double bdist = xyz_dist(loc, bloc);
    if ((rdist < gdist) && (rdist < bdist)) {
        color new_color = color_expr(1 - rdist/xyz_dist(s.center, rloc),
                                     rdist/xyz_dist(s.center, rloc) -
                                     (bdist - gdist)/gdist,
                                     (bdist - gdist)/gdist);
        return new_color;
    } else if ((gdist < rdist) && (gdist < bdist)) {
        color new_color = color_expr(gdist/xyz_dist(s.center, gloc) -
                                     (bdist - gdist)/gdist,
                                     1 - gdist/xyz_dist(s.center, gloc),
                                     (bdist - gdist)/gdist);
        return new_color;
    } else {
        color new_color = color_expr(bdist/xyz_dist(s.center, bloc) -
                                     (bdist - gdist)/gdist,
                                     1 - bdist/xyz_dist(s.center, bloc),
                                     (bdist - gdist)/gdist);
        return new_color;
    }
}

/* sphere_stripes - color the sphere with 4 blue stripes on a white background.
 * the pattern is: WBWBWBWBW. The stripes and background are roughly equal height.
 */
color sphere_horiz_stripes(object *o, location loc)
{
    double r = o->o.s.radius;
    double pt = o->o.s.center.x - r;
    double width = 2*r/9;
    color c;
    int i;
    for (i = 0; i <= 9; i++) {
        if ((i % 2 == 0) && (loc.x >= pt + i*width))
        {
            c = color_expr(1.0, 1.0, 1.0);
        } else if ((i % 2 == 1) && (loc.x >= pt + i*width))
        {
            c = color_expr(0.0, 0.0, 1.0);
        }
    }
    return c;
}
