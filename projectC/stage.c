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

/* =================================== */
/* === stage operations => stage.c === */
/* =================================== */

/* The function get_stage just needs to return a valid stage. */
/* The argument may be used, or not, at your discretion. */
stage get_stage(unsigned int selection)
{
    stage g;
    camera c = g.c;
    scene s = g.s;
    poster p;
    sphere sp;
    object o;

    if (selection == 1) {
        o.tag = POSTER;
        o.o.p = p;
        c.loc = xyz_expr(0, 0, -5);
        c.h = 120;
        c.w = 120;
        s.bg = color_expr(0, 0, 0.25);
        s.objects = ol_singleton(o);
        p.upper_left = xyz_expr(-1.50, 1.50, 4.50);
        p.w = 3.0;
        p.h = 3.0;
        p.surface_color = poster_red_distance;
    } else if (selection == 2) {
        o.tag = POSTER;
        o.o.p = p;
        c.loc = xyz_expr(0, 0, -5);
        c.h = 120;
        c.w = 120;
        s.bg = color_expr(0, 0, 0.25);
        s.objects = ol_singleton(o);
        p.upper_left = xyz_expr(-1.50,1.50,4.50);
        p.w = 3.0;
        p.h = 3.0;
        p.surface_color = poster_rgb_distance;
    } else if (selection == 3) {
        o.tag = SPHERE;
        o.o.s = sp;
        c.loc = xyz_expr(0, 0, -5);
        c.h = 120;
        c.w = 120;
        s.bg = color_expr(0, 0, 0.25);
        s.objects = ol_singleton(o);
        sp.center = xyz_expr(1.00, 0.00, 4.00);
        sp.radius = 1.00;
        sp.surface_color = sphere_loc_to_rgb;
    } else if (selection == 4) {
        o.tag = SPHERE;
        o.o.s = sp;
        c.loc = xyz_expr(0, 0, -5);
        c.h = 120;
        c.w = 120;
        s.bg = color_expr(0, 0, 0.25);
        s.objects = ol_singleton(o);
        sp.center = xyz_expr(0.00, 0.00, 3.00);
        sp.radius = 1.00;
        sp.surface_color = sphere_loc_to_rgb;
    } else {
        fprintf(stderr, "selection not available");
    }
    return g;
}
