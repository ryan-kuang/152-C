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
        return lighting(s, r, closest_hit);
    } else return s.bg;
}

/* main loop and ppm creation */
void ppm_header(FILE *f, int height, int width)
{
    fprintf(f,"P3\n");
    fprintf(f,"%d %d\n", width, height);
    fprintf(f,"255\n");
}

void render(FILE *f, stage g)
{
    int row, col;
    camera c = g.c;
    scene sc = g.s;
    ppm_header(f,c.h,c.w);
    /* loop over all locations in the pixel field */
    for(row=0; row<c.h; row++) {
        for(col=0; col<c.w; col++) {
            /* 1: Translate from physical to logical */
            location loc = logical_loc(c,col,row);
            /* 2: Create a directional vector from camera to pixel */
            direction dir = xyz_sub(loc,c.loc);
            /* 3: Normalize this vector */
            direction normdir = xyz_norm(dir);
            /* 4: Create a ray starting at the camera in the direction of normdir */
            ray r = {c.loc,normdir};
            /* 5: trace the ray through the scene and obtain the color */
            color col = trace_ray(sc,r);
            /* 6: print that pixel to the screen (which can be redirected to a file) */
            color_show_bytes(f,col);
        }
    }
}

/* shadow: tests whether a hit point is in shadow
 * traces shadow ray from hit location in direction of light
 */
int shadow(location p, light l, obj_list *objs) {
    location nudge = xyz_scale(0.0001, l.dir); //scales direction of light
    location lifted = xyz_add(p, nudge); //lifts location in direction of light
    ray shadowray;
    shadowray.origin = lifted;
    shadowray.dir = l.dir;
    obj_list *obl = objs;
    while (obl != NULL) {
        hit_test ht = intersect(shadowray, obl->obj);
        if (ht.miss == HIT)
            return 1;
        obl = obl->next;
    }
    return 0;
}

/* lighting: computes the color for the hit test
 * if hit_test is a miss, the color is the scene's background color
 * otherwise, it is determined by diffuse lighting
 */
color lighting(scene s, ray r, hit_test h)
{
    if (h.miss == 0)
        return s.bg;
    if (shadow(h.hit_point, s.light, s.objects))
        return color_modulate(h.surf,s.amb);
    color before = color_modulate(h.surf,
                                  color_add(s.amb,
                                            color_scale(
                                                        fmax(
                                                             0,xyz_dot(
                                                                       h.surf_norm,s.light.dir)),
                                                                      s.light.c)));
    color new_color;
    xyz n = h.surf_norm;
    xyz light_norm = xyz_norm(s.light.dir);
    color S = h.shine;
    xyz reflection = xyz_sub(xyz_scale(2*xyz_dot(n,light_norm), n),light_norm);
    xyz v = xyz_scale(-1, r.dir);
    if (xyz_dot(n,light_norm) > 0)
        new_color = color_scale(pow(fmax(xyz_dot(reflection, v), 0), 6), S);
    else
        new_color = color_expr(0,0,0);
    return color_add(new_color, before);
}
