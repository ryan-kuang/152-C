#include <math.h>
#include "raytracer.h"

/* === intersect.c === */

/* to fill in slots not used in project A */
color _c0 = {0,0,0};
xyz   _v0 = {0,0,0};

hit_test sph_int(ray r, sphere s)
{
    xyz A = xyz_sub(r.origin,s.center);
    double B = xyz_dot(A,r.dir);
    double C = xyz_dot(A,A)-s.radius*s.radius;
    double D = B*B-C;
    double t = (-B)-sqrt(D);
    if (D>0&&t>0) {
        hit_test ht = {HIT,t,ray_position(r,t),_c0,_c0,_v0};
        return ht;
    } else {
        // if it doesn't hit, then it's a miss, and nothing else in the struct matters
        hit_test ht = {MISS,0,_v0,_c0,_c0,_v0};
        return ht;
    }
}

/* on_poster: returns 1 if true, 0 if false */
int on_poster(poster p, location pos, char a)
{
    switch (a) {
            case 'F':
            if ((pos.x >= p.upper_left.x)&&
                (pos.x <= p.upper_left.x + p.w)&&
                (pos.y <= p.upper_left.y) &&
                (pos.y >= p.upper_left.y - p.h)) {
                return 1;
            } else {
                return 0;
            }
            case 'L':
            case 'R':
            if ((pos.z >= p.upper_left.z)&&
                (pos.z <= p.upper_left.z + p.w)&&
                (pos.y <= p.upper_left.y) &&
                (pos.y >= p.upper_left.y - p.h)) {
                return 1;
            } else {
                return 0;
            }
            case 'T':
            case 'B':
            if ((pos.x >= p.upper_left.x)&&
                (pos.x <= p.upper_left.x + p.w)&&
                (pos.z <= p.upper_left.z) &&
                (pos.z >= p.upper_left.z - p.h)) {
                return 1;
            } else {
                return 0;
            }
        default:
            return 0;
    }
}

/* pst_int: modified pst_int from Professor Shaw's code
 * to take in a double (distance from plane to origin) and
 * normal vector to surface and character marker
 */
hit_test pst_int(ray r, poster p, double d, xyz n, char a)
{
    double t = -(xyz_dot(r.origin,n)+d)/xyz_dot(r.dir,n);
    location hp = ray_position(r,t);
    if (t>0 && on_poster(p, hp, a)) {
        hit_test ht = {HIT,t,hp, {1, 1, 1}, {1, 1, 1}, n};
        return ht;
    }
    hit_test ht = {MISS,0,{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    return ht;
}

/* tests for left face intersection */
hit_test left_test(ray r, cube c)
{
    xyz loc = c.front_top_left;
    poster left = poster_expr(loc, c.length, c.length, c.surface_color, c.shine);
    return pst_int(r, left, loc.x, xyz_expr(-1, 0, 0), 'L');
}

/* tests for top face intersection */
hit_test top_test(ray r, cube c)
{
    xyz loc = c.front_top_left;
    poster top = poster_expr(xyz_expr(loc.x, loc.y, loc.z + c.length),
                             c.length, c.length, c.surface_color, c.shine);
    return pst_int(r, top, -loc.y, xyz_expr(0, 1, 0), 'T');
}

/* tests for right face intersection */
hit_test right_test(ray r, cube c)
{
    xyz cube_ul = c.front_top_left;
    xyz loc = xyz_expr(c.front_top_left.x + c.length, c.front_top_left.y - c.length,
                       c.front_top_left.z + c.length);
    poster right = poster_expr(xyz_expr(cube_ul.x + c.length, cube_ul.y, cube_ul.z),
                               c.length, c.length, c.surface_color, c.shine);
    return pst_int(r, right, -loc.x, xyz_expr(1, 0, 0), 'R');
}

/* tests for bottom face intersection */
hit_test bottom_test(ray r, cube c)
{
    xyz cube_ul = c.front_top_left;
    xyz loc = xyz_expr(c.front_top_left.x + c.length, c.front_top_left.y - c.length,
                       c.front_top_left.z + c.length);
    poster bottom = poster_expr(xyz_expr(loc.x - c.length, loc.y, loc.z),
                                c.length, c.length, c.surface_color, c.shine);
    return pst_int(r, bottom, loc.y, xyz_expr(0, -1, 0), 'B');
}

/* cube_int: tests whether a ray intersects a cube c */
hit_test cube_int(ray r, cube c)
{
    poster face = poster_expr(c.front_top_left, c.length, c.length, c.surface_color, c.shine);
    hit_test front = pst_int(r, face, c.front_top_left.z, xyz_expr(0, 0, -1), 'F');
    hit_test left = left_test(r, c);
    hit_test top = top_test(r, c);
    hit_test right = right_test(r, c);
    hit_test bottom = bottom_test(r, c);
    
    hit_test tmp = front;
    if (front.miss == HIT) {
        return front; //must be closest hit
    }
    if ((left.miss == HIT && left.t < tmp.t)||tmp.miss == MISS) {
        tmp = left;
    }
    if ((right.miss == HIT && right.t < tmp.t)||tmp.miss == MISS) {
        tmp = right;
    }
    if ((top.miss == HIT && top.t < tmp.t)||tmp.miss == MISS) {
        tmp = top;
    }
    if ((bottom.miss == HIT && bottom.t < tmp.t)||tmp.miss == MISS) {
        tmp = bottom;
    }
    return tmp;
}

/* intersect: tests whether ray intersects object */
hit_test intersect(ray r, object obj)
{
    hit_test hit;
    switch (obj.tag) {
        case SPHERE:
            hit = sph_int(r,obj.o.s);
            hit.surf = obj.o.s.surface_color(&obj, hit.hit_point);
            return hit;
        case POSTER:
            hit = pst_int(r, obj.o.p,
                          obj.o.p.upper_left.z, xyz_expr(0, 0, -1), 'F');
            hit.surf = obj.o.p.surface_color(&obj, hit.hit_point);
            return hit;
        case CUBE:
            hit = cube_int(r, obj.o.c);
            hit.surf = obj.o.c.surface_color(&obj, hit.hit_point);
            return hit;
            break;
        default:
            fprintf(stderr,"error (intersect): unknown object tag\n");
            exit(1);
    }
}
