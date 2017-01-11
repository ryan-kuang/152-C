/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 3
 */

#include "waves.h"

/* dist: takes in two pairs of x and y values
 * measures distance between the two pixels
 */
double dist(double x0, double y0, double x1, double y1)
{
    return sqrt((x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0));
}

color trace_ray(scene s, ray r)
{
    object o = s.objects->obj;
    hit_test h;

    h = intersect(r, o);

    while(s.objects!=NULL){
        if(h.miss==1){
            switch(o.tag){
                case SPHERE:
                    return o.o.s.surface_color(&o, h.hit_point);
                case POSTER:
                    return o.o.p.surface_color(&o, h.hit_point);
            }
        }else{
            s.objects = s.objects->next;
        }
    }
    return s.bg;
}

/* draw_waves: generates a side_length x side_length image
 * with pattern of concentric blue circles
 */
void draw_waves(int side_length, int x_offset, int y_offset)
{
    if (side_length > 0) {
        printf("P3 \n%d", side_length); //printing ppm image
        printf(" %d", side_length);
        printf(" \n255\n");

        double center_x = side_length/2 + x_offset; //offset center coordinates
        double center_y = side_length/2 + y_offset;
        double col; //indicates column number (x coordinate)
        double row; //indicates row number (y coordinate)
        for (row = 0; row < side_length; row++) {
            for (col = 0; col < side_length; col++) {
                int b = (sin(dist(col, row, center_x, center_y)) + 1) * 255/2;
                printf("0 0 %d", b);
                printf("\n");
            }
        }
    } else {
        fprintf(stderr, "error (draw_waves): image size must be positive\n");
        exit(1);
    }
}
