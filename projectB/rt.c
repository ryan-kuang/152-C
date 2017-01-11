#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* Tests for xyz.c */
void evidence_xyz_expr()
{
    printf("****** TESTING XYZ.C *******\n");
    xyz test_xyz = xyz_expr(1.0, 2.0, 3.0);
    printf("expecting 1.0: %f\n", test_xyz.x);
}

void evidence_xyz_add()
{
    xyz test_xyz = xyz_expr(1.0, 2.0, 3.0);
    xyz test_xyz1 = xyz_expr(1.0, 2.0, 3.0);
    xyz result = xyz_add(test_xyz, test_xyz1);
    printf("expecting 2.0: %f\n", result.x);
}

void evidence_xyz_dot()
{
    xyz test_xyz = xyz_expr(1, 2, 3);
    xyz test_xyz1 = xyz_expr(1.0, 2.0, 3.0);
    double result = xyz_dot(test_xyz, test_xyz1);
    printf("expecting 14.0: %f\n", result);
}

void evidence_xyz_norm()
{
    xyz test_xyz = xyz_expr(1, 2, 3);
    xyz result = xyz_norm(test_xyz);
    printf("%f %f %f\n", result.x, result.y, result.z);
}

void evidence_xyz_dist()
{
    xyz test_xyz = xyz_expr(1, 2, 3);
    xyz test_xyz1 = xyz_expr(2, 2, 3);
    double result = xyz_dist(test_xyz, test_xyz1);
    printf("expecting 1.0: %f\n", result);
}

void evidence_xyz_tos()
{
    xyz test_xyz = xyz_expr(1, 2, 3);
    char* test_str = xyz_tos(test_xyz);
    int i = 0;
    while (test_str[i] != '\0') {
        printf("%c", test_str[i]);
        i++;
    }
    printf("\n");
}

void evidence_xyz_show()
{
    xyz test_xyz = xyz_expr(1, 2, 3);
    xyz_show(stdout, test_xyz);
    printf("\n");
}

/* Tests for color.c */

void evidence_color_expr()
{
    printf("****** TESTING COLOR.C *******\n");
    printf("- expecting {1, 0, 0.3}:\n");
    color test_color = color_expr(1, 0, 0.3);
    printf("{%f %f %f}\n", test_color.r, test_color.g, test_color.b);
}

void evidence_color_scale()
{
    printf("*** testing color_scale\n");
    printf("- expecting {1, 0, 0.5}: \n");
    color test_color = color_expr(1, 0, 0.6);
    color result = color_scale(0.5, test_color);
    printf("{%lf %lf %lf}\n", result.r, result.g, result.b);
}

void evidence_color_tos()
{
    printf("*** testing color_tos\n");
    color test_color = color_expr(1, 0, 0.3);
    char* color_str = color_tos(test_color);
    int i = 0;
    while (color_str[i] != '\0') {
        printf("%c", color_str[i]);
        i++;
    }
    printf("\n");
}

void evidence_color_show_bytes()
{
    color test_color = color_expr(1, 0, 0.3);
    color_show_bytes(stdout, test_color);
    printf("\n");
}

/* Tests for sphere.c */

void evidence_sphere_expr()
{
    printf("****** TESTING SPHERE.C *******\n");
    printf("testing sphere_expr ***\n");
    xyz test_xyz = xyz_expr(1, 1, 1);
    color test_color = color_expr(1, 1, 1);
    object new_obj;
    new_obj.tag = SPHERE;
    
    sphere new_sph = sphere_expr(test_xyz, 1,
                                     sphere_horiz_stripes,
                                     test_color);
    new_sph.o = &new_obj;
    new_obj.o.s = new_sph;
    printf("%f %f %f\n", new_sph.center.x, new_sph.center.y, new_sph.center.z);
    printf("%f\n", new_sph.radius);
    printf("%u\n", new_sph.o->tag);
}

/* Tests for poster.c */

void evidence_poster_expr()
{
    printf("****** TESTING POSTERS.C *******\n");
    printf("testing poster_expr ***\n");
    xyz test_xyz = xyz_expr(0, 0, 0);
    color test_color = color_expr(1, 1, 1);
    object new_obj;
    new_obj.tag = POSTER;
    poster test_poster = poster_expr(test_xyz, 5, 5,
                                     poster_red_distance, test_color);
    test_poster.o = &new_obj;
    new_obj.o.p = test_poster;
    printf("%lf %lf %lf\n", test_poster.upper_left.x, test_poster.upper_left.y, test_poster.upper_left.z);
    printf("%lf %lf\n", test_poster.w, test_poster.h);
    printf("%u\n", test_poster.o->tag);
}

/* Tests for intersect.c */

void evidence_intersect()
{
    printf("****** TESTING INTERSECT.C *******\n");
    object obj;
    obj.tag = SPHERE;
    obj.o.s.center = xyz_expr(0, 0, 0);
    obj.o.s.radius = 1;
    obj.o.s.surface_color = sphere_horiz_stripes;
    
    object obj1;
    obj1.tag = POSTER;
    obj1.o.p.upper_left = xyz_expr(-1, 1, 5);
    obj1.o.p.w = 2.0;
    obj1.o.p.h = 2.0;
    obj1.o.p.surface_color = poster_red_distance;
    
    ray r = {xyz_expr(0, 0, -5), xyz_expr(0, 0, 1)};
    
    ray r1 = {xyz_expr(0, 0, -5), xyz_expr(1, 1, 1)};
    
    hit_test hit = intersect(r, obj);
    hit_test hit1 = intersect(r1, obj);
    hit_test hit2 = intersect(r, obj1);
    hit_test hit3 = intersect(r1, obj1);
    
    printf("expecting 1 : %d\n", hit.miss);
    printf("expecting 0 : %d\n", hit1.miss);
    printf("expecting 1 : %d\n", hit2.miss);
    printf("expecting 0 : %d\n", hit3.miss);
    printf("expecting 4 : %f\n", hit.t);
    printf("expecting 10 : %f\n", hit2.t);
}

/* Tests for raytracer.c */

void evidence_logical_loc()
{
    printf("****** TESTING RAYTRACER.C *******\n");
    printf("testing logical_loc ***\n");
    camera c;
    c.loc = xyz_expr(0, 0, -5);
    c.w = 30;
    c.h = 20;
    
    location new_loc = logical_loc(c, 0, 0);
    printf("%f %f %f\n", new_loc.x, new_loc.y, new_loc.z);
    location new_loc1 = logical_loc(c, 1, 0);
    printf("%f %f %f\n", new_loc1.x, new_loc1.y, new_loc1.z);
    location new_loc2 = logical_loc(c, 29, 19);
    printf("%f %f %f\n", new_loc2.x, new_loc2.y, new_loc2.z);
    
    camera c1;
    c1.loc = xyz_expr(0, 0, -5);
    c1.w = 10;
    c1.h = 14;
    
    location new_loc3 = logical_loc(c1, 0, 0);
    printf("%f %f %f\n", new_loc3.x, new_loc3.y, new_loc3.z);
    location new_loc4 = logical_loc(c1, 0, 13);
    printf("%f %f %f\n", new_loc4.x, new_loc4.y, new_loc4.z);
    
    camera c2;
    c2.loc = xyz_expr(0, 0, -5);
    c2.w = 10;
    c2.h = 10;
    
    location new_loc5 = logical_loc(c2, 0, 0);
    printf("%f %f %f\n", new_loc5.x, new_loc5.y, new_loc5.z);
}

void evidence_trace_ray()
{
    printf("testing trace_ray ***\n");
    scene new_scene;
    new_scene.bg = color_expr(0.00, 0.00, 0.25);
    
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj.tag = SPHERE;
    my_list->obj.o.s.center = xyz_expr(0.0, 0.0, 0.0);
    my_list->obj.o.s.radius = 1.0;
    my_list->obj.o.s.surface_color = sphere_horiz_stripes;
    
    obj_list* my_list1 = (obj_list*)malloc(sizeof(obj_list));
    my_list1->obj.tag = POSTER;
    my_list1->obj.o.p.upper_left = xyz_expr(-1.0, 1.0, 4.5);
    my_list1->obj.o.p.w = 3.00;
    my_list1->obj.o.p.h = 3.00;
    my_list1->obj.o.p.surface_color = poster_red_distance;

    my_list1->next = NULL;
    new_scene.objects = my_list1;
    
    ray new_ray;
    new_ray.origin = xyz_expr(0.0, 0.0, -5.0);
    new_ray.dir = xyz_expr(0.0, 0.0, 1.0);
    
    color new_col = trace_ray(new_scene, new_ray);
    color_show_bytes(stdout, new_col);
    printf("\n");
    free(my_list1);
    free(my_list);
}

void evidence_render()
{
  /* TESTING POSTERS (poster_red_distance)
    xyz test_xyz1 = xyz_expr(-1.5, 1.5, 4.5);
    color test_color1 = color_expr(0.0, 1.0, 1.0);
    object new_obj1;
    new_obj1.tag = POSTER;
    poster test_poster = poster_expr(test_xyz1, 3, 3,
                                     &poster_red_distance, test_color1);
    test_poster.o = &new_obj1;
    new_obj1.o.p = test_poster;
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj1;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage);*/
    
    /* TESTING POSTERS (poster_rgb_distance)
     xyz test_xyz1 = xyz_expr(-1.5, 1.5, 4.5);
     color test_color1 = color_expr(0.0, 1.0, 1.0);
     object new_obj1;
     new_obj1.tag = POSTER;
     poster test_poster = poster_expr(test_xyz1, 3, 3,
                                      &poster_rgb_distance, test_color1);
     test_poster.o = &new_obj1;
     new_obj1.o.p = test_poster;
     
     stage my_stage;
     my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
     my_stage.c.w = 120;
     my_stage.c.h = 120;
     my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
     obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
     my_list->obj = new_obj1;
     my_list->next = NULL;
     my_stage.s.objects = my_list;
     
     render(stdout, my_stage); */
    
    // TESTING SPHERES (sphere_horiz_stripes)
   /* xyz test_xyz = xyz_expr(1.0, 1.0, 1.0);
    color test_color = color_expr(1.0, 1.0, 1.0);
    sphere new_sph = sphere_expr(test_xyz, 1,
                                 &sphere_horiz_stripes,
                                 test_color);
    object new_obj;
    new_obj.tag = SPHERE;
    new_sph.o = &new_obj;
    new_obj.o.s = new_sph;
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage);*/
    
    /* TESTING SPHERES (sphere_loc_to_rgb)
     xyz test_xyz = xyz_expr(1.0, 1.0, 1.0);
     color test_color = color_expr(1.0, 1.0, 1.0);
     sphere new_sph = sphere_expr(test_xyz, 1,
                                  &sphere_loc_to_rgb,
                                  test_color);
     object new_obj;
     new_obj.tag = SPHERE;
     new_sph.o = &new_obj;
     new_obj.o.s = new_sph;
     
     stage my_stage;
     my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
     my_stage.c.w = 120;
     my_stage.c.h = 120;
     my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
     obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
     my_list->obj = new_obj;
     my_list->next = NULL;
     my_stage.s.objects = my_list;
     
     render(stdout, my_stage);*/
    
    /* TESTING horiz_stripes
    xyz test_xyz1 = xyz_expr(-1.5, 1.5, 4.5);
    color test_color1 = color_expr(0.0, 0.0, 0.25);
    light test_light1 = {xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1)};
    color amb1 = color_expr(0.1, 0.1, 0.1);
    object new_obj1;
    new_obj1.tag = POSTER;
    poster test_poster = poster_expr(test_xyz1, 3, 3,
                                     &map_texture_on_poster, color_expr(0, 0, 0));
    test_poster.o = &new_obj1;
    new_obj1.o.p = test_poster;
    new_obj1.t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 5);
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj1;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage); */
    
    /* TESTING make_waves
    xyz test_xyz1 = xyz_expr(-1.5, 1.5, 4.5);
    color test_color1 = color_expr(0.0, 0.0, 0.25);
    light test_light1 = {xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1)};
    color amb1 = color_expr(0.1, 0.1, 0.1);
    object new_obj1;
    new_obj1.tag = POSTER;
    poster test_poster = poster_expr(test_xyz1, 3, 3,
                                     &map_texture_on_poster, color_expr(0, 0, 0));
    test_poster.o = &new_obj1;
    new_obj1.o.p = test_poster;
    new_obj1.t = make_waves(100, 0, 0, color_expr(1, 0, 0));
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj1;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage);*/
    
    /* TESTING vert_stripes
    xyz test_xyz1 = xyz_expr(-1, 4, 1.5);
    color test_color1 = color_expr(0.0, 0.0, 0.25);
    light test_light1 = {xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1)};
    color amb1 = color_expr(0.1, 0.1, 0.1);
    object new_obj1;
    new_obj1.tag = POSTER;
    poster test_poster = poster_expr(test_xyz1, 0.5, 6,
                                     &map_texture_on_poster, color_expr(0, 0, 0));
    test_poster.o = &new_obj1;
    new_obj1.o.p = test_poster;
    new_obj1.t = make_vert_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 7);
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj1;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage);*/
    
    /* TESTING SPHERES horiz_stripes
    
    xyz test_xyz1 = xyz_expr(-0.5, 0.7, 3);
    color test_color1 = color_expr(0.0, 0.0, 0);
    light test_light1 = {xyz_expr(-0.58, 0.58, -0.58), color_expr(1, 1, 1)};
    color amb1 = color_expr(0.1, 0.1, 0.1);
    object new_obj1;
    new_obj1.tag = SPHERE;
    sphere test_sphere = sphere_expr(test_xyz1, 0.5, &map_texture_on_sphere, test_color1);
    test_sphere.o = &new_obj1;
    new_obj1.o.s = test_sphere;
    new_obj1.t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 5);
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0.0, 0.0, 0.25);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = new_obj1;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    
    render(stdout, my_stage); */
}

int main(int argc, char *argv[])
{
   /* evidence_xyz_expr();
    evidence_xyz_add();
    evidence_xyz_dot();
    evidence_xyz_norm();
    evidence_xyz_dist();
    evidence_xyz_tos();
    evidence_xyz_show();
    evidence_color_expr();
    evidence_color_scale();
    evidence_color_tos();
    evidence_color_show_bytes();
    evidence_sphere_expr();
    evidence_poster_expr();
    evidence_intersect();
    evidence_logical_loc();
    evidence_trace_ray();*/
    evidence_render();
    return 0;
}