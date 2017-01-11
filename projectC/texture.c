/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Project A
 * Professor Shaw
 */

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "raytracer.h"
#include <unistd.h>

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
    xyz rloc = xyz_expr(s.center.x - s.radius*cos(M_PI/6),
                        s.center.y + s.radius*sin(M_PI/6), s.center.z);
    xyz gloc = xyz_expr(s.center.x + s.radius*cos(M_PI/6),
                        s.center.y + s.radius*sin(M_PI/6), s.center.z);
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
 * the pattern is: WBWBWBWBW
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

/* map_texture_on_sphere: takes an object and intersection point
 * uses the bitmap contained in the object, the attributes of the sphere,
 * and the intersection point to determine the color at that pixel
 * uses the circumference of a horizontal circle drawn on the
 * sphere at that point to determine the width
 */
color map_texture_on_sphere(object *o, location intersection)
{
    double pt = sqrt (pow ((intersection.x - o->o.s.center.x), 2)) +
    (pow ((intersection.z - o->o.s.center.z), 2));
    double arc = pt * (fabs
                         (M_PI/2 +
                          (atan
                           ((o->o.s.center.x - intersection.x)/
                            (o->o.s.center.z - intersection.z)))));
    double xratio = arc/(M_PI * pt);
    double yratio = (fabs ((o->o.s.center.y + o->o.s.radius) - intersection.y))
    /(2 * o->o.s.radius);
    int col = (int) (xratio * o->t->width);
    int row = (int) (yratio * o->t->height);
    return o->t->pixels[row][col];
}

/* map_texture_on_poster: takes an object and an intersection point
 * determines color at the intersection point
 * scales the height and width to match the poster
 */
color map_texture_on_poster(object *o, location intersection)
{
    double texture_w = o->t->width;
    double poster_w = o->o.p.w;
    double texture_h = o->t->height;
    double poster_h = o->o.p.h;
    color** colormap = o->t->pixels;

    double distx = fabs(intersection.x - o->o.p.upper_left.x);
    double disty = fabs(intersection.y - o->o.p.upper_left.y);

    double scalex = texture_w/poster_w;
    double scaley = texture_h/poster_h;

    int x = distx * scalex;
    int y = disty * scaley;

    return colormap[x][y];
}

/* make_horiz_stripes: takes in two colors and a number of stripes
 * maps alternating stripes onto object
 */
texture *make_horiz_stripes(color c1, color c2, int num_stripes)
{
    texture *t = malloc(sizeof(texture));
    if(t == NULL){
        fprintf(stderr, "the allocation is incomplete");
        exit(1);
    }

    color** pixels = (color**)malloc(sizeof(color*) * num_stripes);

    for (int i = 0; i < num_stripes; i++) {
        pixels[i] = (color*)malloc(sizeof(color) * num_stripes);
    }

    for (int j = 0; j < num_stripes; j++) {
        for (int i = 0; i < num_stripes; i++) {
            if (j % 2 == 0) {
                pixels[j][i] = c1;
            } else {
                pixels[j][i] = c2;
            }
        }
    }
    t->pixels = pixels;
    t->width = num_stripes;
    t->height = num_stripes;
    return t;
}

/* dist: takes in two pairs of x and y values
 * measures distance between the two pixels
 */
double dist(double x0, double y0, double x1, double y1)
{
    return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

/* make_waves: makes a square image of the given length
 * with pattern of waves
 */
texture *make_waves(int length, int x_offset, int y_offset, color col)
{
    texture *t = malloc(sizeof(texture));
    if(t == NULL){
        fprintf(stderr, "the allocation is incomplete");
        exit(1);
    }

    color** pixels = (color**)malloc(sizeof(color*) * length);
    for(int i = 0; i < length; i++) {
        pixels[i] = (color*)malloc(sizeof(color) * length);
    }

    double center_x = length/2 + x_offset; //offset center coordinates
    double center_y = length/2 + y_offset;
    int c; //indicates column number (x coordinate)
    int r; //indicates row number (y coordinate)

    for (r = 0; r < length; r++) {
        for (c = 0; c < length; c++) {
            int b = (sin(dist(c, r, center_x, center_y)) + 1)/2;
            pixels[r][c] = color_scale(b, col);
        }
    }
    t->pixels = pixels;
    t->width = length;
    t->height = length;
    return t;
}

/* make_vert_stripes: prints vertical stripes */
texture *make_vert_stripes(color c1, color c2, int num_stripes)
{
    texture *t = malloc(sizeof(texture));
    if(t == NULL){
        fprintf(stderr, "the allocation is incomplete");
        exit(1);
    }

    color** pixels = (color**)malloc(sizeof(color*) * num_stripes);

    for (int i = 0; i < num_stripes; i++) {
        pixels[i] = (color*)malloc(sizeof(color) * num_stripes);
    }

    for (int j = 0; j < num_stripes; j++) {
        for (int i = 0; i < num_stripes; i++) {
            if (i % 2 == 0) {
                pixels[j][i] = c1;
            } else {
                pixels[j][i] = c2;
            }
        }
    }
    t->pixels = pixels;
    t->width = num_stripes;
    t->height = num_stripes;
    return t;
}

/****** MAPPING TEXTURES ONTO CUBES ******/
/* map_poster: maps texture on one face of a cube */
color map_poster(poster p, location intersection, texture* t, char a)
{
    double poster_l = p.w; //poster width and height are equal
    double texture_w = t->width; //width of texture
    double texture_h = t->height; //height of texture
    color** colormap = t->pixels;

    double distx; //horizontal distance from upper left corner of poster
    double disty; //vertical distance from upper left corner of poster

    switch (a) {
        case 'F':
            distx = fabs(intersection.x - p.upper_left.x);
            disty = fabs(intersection.y - p.upper_left.y);
            break;
        case 'L':
        case 'R':
            distx = fabs(intersection.z - p.upper_left.z);
            disty = fabs(intersection.y - p.upper_left.y);
            break;
        case 'T':
        case 'B':
            distx = fabs(intersection.x - p.upper_left.x);
            disty = fabs(intersection.z - p.upper_left.z);
            break;
        default:
            fprintf(stderr,
                    "error(map_poster): unrecognized character input %c", a);
            exit(1);
    }

    double scalex = texture_w/poster_l;
    double scaley = texture_h/poster_l;

    int x = distx * scalex; //horizontal scale factor
    int y = disty * scaley; //vertical scale factor

    return colormap[x][y];
}

/* map_texture_on_cube_faces: takes an object and an intersection point
 * determines the color at that intersection point.
 */
color map_texture_on_cube_faces(object *o, location intersection)
{
    if (o->tag != CUBE) {
        fprintf(stderr,
                "error(map_texture_on_cube_faces): object isn't a cube");
        exit(1);
    }
    cube c = o->o.c;
    double length = c.length;
    xyz cube_ul = o->o.c.front_top_left; //upper left corner of cube
    xyz cube_br = xyz_expr(cube_ul.x + length, cube_ul.y - length,
                                     cube_ul.z + length); //bottom right corner
    //creates posters of each side
    poster front = poster_expr(cube_ul,length,length,c.surface_color,c.shine);
    poster left = poster_expr(cube_ul,length,length,c.surface_color,c.shine);
    poster top = poster_expr(xyz_expr(cube_ul.x, cube_ul.y, cube_ul.z + length),
                             length, length, c.surface_color, c.shine);
    poster right = poster_expr(xyz_expr(cube_ul.x + length,cube_ul.y,cube_ul.z),
                               length,length,c.surface_color,c.shine);
    poster bottom = poster_expr(xyz_expr(cube_br.x-length,cube_br.y,cube_br.z),
                                length,length,c.surface_color,c.shine);

    //checks each poster
    if (on_poster(front, intersection, 'F')) {
        return map_poster(front, intersection, o->t, 'F');
    }
    if (on_poster(left, intersection, 'L')) {
        return map_poster(left, intersection, o->t, 'L');
    }
    if (on_poster(right, intersection, 'R')) {
        return map_poster(right, intersection, o->t, 'R');
    }
    if (on_poster(top, intersection, 'T')) {
        return map_poster(top, intersection, o->t, 'T');
    }
    if (on_poster(bottom, intersection, 'B')) {
        return map_poster(bottom, intersection, o->t, 'B');
    }
}

/* map_texture_around_cube takes an object and an intersection point
 * flatten the cube into a "+" sign and map that "+" sign onto the
 * 2D bitmap
 */
color map_texture_around_cube(object *o, location intersection)
{
    if (o->tag != CUBE) {
        fprintf(stderr, "error(map_texture_around_cube): object is not a cube");
        exit(1);
    }
    xyz cube_ul = o->o.c.front_top_left; //upper left of cube
    double length = o->o.c.length; //length of cube
    int texture_w = o->t->width;
    int texture_h = o->t->height;
    double new_len = 3 * length;
    double x_fact;
    double y_fact;
    int row;
    int col;

    if(cube_ul.x < intersection.x && //testing location of intersect
       intersection.x < (cube_ul.x + length) &&
       cube_ul.y > intersection.y &&
       intersection.y > (cube_ul.y - length)) {
        x_fact = intersection.x - cube_ul.x + length; //set x factor
        y_fact = cube_ul.y - intersection.y + length; //set y factor
    } else if(intersection.x < cube_ul.x &&
              cube_ul.z < intersection.z &&
              intersection.z < (cube_ul.z + length) &&
              cube_ul.y > intersection.y &&
              intersection.y > (cube_ul.y - length)) {
        x_fact = intersection.z - cube_ul.z;
        y_fact = cube_ul.y - intersection.y + length;
    } else if(intersection.y > cube_ul.y &&
              cube_ul.x < intersection.x &&
              intersection.x < (cube_ul.x + length) &&
              cube_ul.z < intersection.z &&
              intersection.z < (cube_ul.z + length)) {
        x_fact = intersection.x - cube_ul.x + length;
        y_fact = intersection.z - cube_ul.z + 2 * length;
    } else if(cube_ul.z < intersection.z &&
              intersection.z < (cube_ul.z + length) &&
              cube_ul.y > intersection.y &&
              intersection.y > (cube_ul.y - length)) {
        x_fact = (2 * length) + (intersection.z - cube_ul.z);
        y_fact = cube_ul.y - intersection.y + length;
    } else if(cube_ul.x < intersection.x &&
              intersection.x < (cube_ul.x + length) &&
              cube_ul.z < intersection.z &&
              intersection.z < (cube_ul.z + length)) {
        x_fact = intersection.x - cube_ul.x + length;
        y_fact = (2 * length) + (intersection.z - cube_ul.z);
    }
    else {
        fprintf(stderr, "invalid coordinate");
        exit(1);
    }
    row = (int)((x_fact / new_len) * texture_w);
    col = (int)((y_fact / new_len) * texture_h);
    return o->t->pixels[row][col];
}

/* ****** READING PPMs ****** */
/* scale_color: converts ppm color [0, 255] to [0, 1] */
color scale_color(unsigned r, unsigned g, unsigned b)
{
    return color_expr(r/255.0, g/255.0, b/255.0);
}

/* make_texture: takes in pixels, width and height
 * returns texture
 */
texture* make_texture(color** pixels, unsigned width, unsigned height)
{
    texture* t = (texture*)malloc(sizeof(texture));
    t->pixels = pixels;
    t->width = width;
    t->height = height;
    return t;
}

/* make_bitmap_from_file: opens the file,reads the information
 * in the file to allocate and populate the texture map,
 * closes the file and returns the resulting texture
 */
texture *make_bitmap_from_file(char *filename)
{
    if (access(filename, F_OK) == -1) {
        fprintf(stderr, "error(make_bitmap_from_file): file does not exist\n");
        exit(1);
    }
    //opens file
    FILE *f = fopen(filename, "r");
    if (!f) {
        fprintf(stderr, "error(make_bitmap_from_file): file cannot be opened\n");
        exit(1);
    }
    //scans files and stores width and height values
    unsigned width, height, row, col, r, g, b;
    fscanf(f, "P3\n");
    fscanf(f, "%d %d\n", &width, &height);
    fscanf(f, "255\n");

    //allocates bitmap
    color **pixels = (color**)malloc(sizeof(color*)*height);
    if (!pixels) {
        fprintf(stderr, "error(make_bitmap_from_file): malloc failed\n");
        exit(1);
    }
    for (row = 0; row < height; row++) {
        color *c = (color*)malloc(sizeof(color)*width);
        if (!c) {
            fprintf(stderr, "error(make_bitmap_from_file): malloc failed\n");
            exit(1);
        }
        for (col = 0; col < width; col++) {
            fscanf(f, "%d %d %d", &r, &g, &b);
            c[col] = scale_color(r, g, b);
        }
        pixels[row] = c;
    }
    //closes file
    fclose(f);
    return make_texture(pixels, width, height);
}
