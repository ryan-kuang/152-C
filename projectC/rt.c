#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "raytracer.h"

/* Tests for intersect.c */

/* Tests for raytracer.c */

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

/* Tests for Intersect */

void evidence_left_test()
{
    object obj;
    obj.tag = CUBE;
    cube cube;
    cube.front_top_left = xyz_expr(1, 2, 3);
    cube.length = 2;
    obj.o.c = cube;
    cube.o = &obj;
    ray r = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 1, 4))};
    
    hit_test hit = left_test(r, obj.o.c);
    
    printf("expecting  4.24: %f\n", hit.t);
}

void evidence_top_test()
{
    object obj;
    obj.tag = CUBE;
    cube cube;
    cube.front_top_left = xyz_expr(1, 2, 3);
    cube.length = 2;
    obj.o.c = cube;
    cube.o = &obj;
    ray r = {xyz_expr(0, 0, 0), xyz_norm(xyz_expr(2, 2, 4))};
    
    hit_test hit = top_test(r, obj.o.c);
    
    printf("expecting  2: %f\n", hit.t);
}

void evidence_right_test()
{
    object obj;
    obj.tag = CUBE;
    cube cube;
    cube.front_top_left = xyz_expr(1, 2, 3);
    cube.length = 2;
    obj.o.c = cube;
    cube.o = &obj;
    ray r = {xyz_expr(0, 0, 0), xyz_norm(xyz_expr(1, 0.5, 1.5))};
    
    hit_test hit = right_test(r, obj.o.c);
    
    printf("expecting  2: %f\n", hit.t);
}

void evidence_bottom_test()
{
    object obj;
    obj.tag = CUBE;
    cube cube;
    cube.front_top_left = xyz_expr(1, 3, 3);
    cube.length = 2;
    obj.o.c = cube;
    cube.o = &obj;
    ray r = {xyz_expr(0, 0, 0), xyz_norm(xyz_expr(2, 1, 4))};
    
    hit_test hit = bottom_test(r, obj.o.c);
    
    printf("expecting  4.58: %f\n", hit.t);
}

void evidence_pst_int()
{
    poster left = poster_expr(xyz_expr(1, 2, 2), 1, 1,
                       &poster_red_distance, color_expr(0, 0, 0));
    object o;
    o.tag = POSTER;
    o.o.p = left;
    ray r = {xyz_expr(0, 0, 0), xyz_expr(0.5, 1, 1)};
    
    hit_test hit = pst_int(r, left, left.upper_left.z, xyz_expr(-1, 0, 0), 'F');
    
    printf("expecting  1: %f\n", hit.t);
    
}
void evidence_cube_int()
{
    printf("****** TESTING INTERSECT.C *******\n");
    printf("testing cube_int:\n");
    object obj;
    obj.tag = CUBE;
    cube c;
    c.front_top_left = xyz_expr(1, 2, 3);
    c.length = 2;
    obj.o.c = c;
    obj.o.c.o = &obj;
    
    object obj1;
    obj1.tag = CUBE;
    cube cube1;
    cube1.front_top_left = xyz_expr(1, 3, 3);
    cube1.length = 2;
    obj1.o.c = cube1;
    cube1.o = &obj;
    
    ray r = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(2, 1, 4))};
    ray r1 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 0.5, 1.5))};
    ray r2 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 1, 4))};
    ray r3 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(2, 2, 4))};
    ray r4 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 0, 0))};
    
    hit_test result = cube_int(r, obj.o.c);
    printf("expecting  : %f\n", result.t);
    
    hit_test result1 = cube_int(r1, obj.o.c);
    printf("expecting : %f\n", result1.t);
    hit_test result2 = cube_int(r2, obj.o.c);
    printf("expecting  : %f\n", result2.t);
    hit_test result3 = cube_int(r3, obj.o.c);
    printf("expecting  : %f\n", result3.t);
    hit_test result4 = cube_int(r4, obj.o.c);
    printf("expecting  0: %f\n", result4.t);
}

void evidence_intersect()
{
    printf("testing intersect:\n");
    object obj;
    obj.tag = CUBE;
    cube c;
    c.shine;
    c.front_top_left = xyz_expr(1, 2, 3);
    c.length = 2;
    obj.o.c = c;
    obj.o.c.o = &obj;
    
    object new_obj1;
    new_obj1.tag = CUBE;
    
    //     cube cube1 = {{-1.3,0.55,0},1.5,&map_texture_around_cube,{1,1,1}};
    cube cube2    = {{-1.3,0.55,0},1.5,&map_texture_on_cube_faces,{1,1,1}};
    cube2.o = &new_obj1;
    new_obj1.o.c = cube2;
    new_obj1.t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 5);
    
    ray r = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(2, 1, 4))};
    ray r1 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 0.5, 1.5))};
    ray r2 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 1, 4))};
    ray r3 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(2, 2, 4))};
    ray r4 = {xyz_expr(0, 0, -1), xyz_norm(xyz_expr(1, 0, 0))};
    
    hit_test result = cube_int(r, obj.o.c);
    printf("expecting  : %f\n", result.t);
    
    hit_test result1 = intersect(r1, new_obj1);
    printf("expecting : %f\n", result1.t);
    hit_test result2 = intersect(r2, new_obj1);
    printf("expecting  : %f\n", result2.t);
    hit_test result3 = intersect(r3, new_obj1);
    printf("expecting  : %f\n", result3.t);
    hit_test result4 = intersect(r4, new_obj1);
    printf("expecting  0: %f\n", result4.t);
    
    /*object obj1;
    obj1.tag = CUBE;
    obj1.o.c.front_top_left = xyz_expr(0, 2, 1);
    obj1.o.c.length = 1;
    obj1.o.c.o = &obj1;
    
    object obj2;
    obj2.tag = CUBE;
    cube cube1;
    cube1.front_top_left = xyz_expr(0, 1, 1);
    cube1.length = 1;
    obj2.o.c = cube1;
    cube1.o = &obj2;
    
    object obj;
    obj.tag = CUBE;
    cube cube;
    cube.front_top_left = xyz_expr(1, 2, 3);
    cube.length = 2;
    obj.o.c = cube;
    cube.o = &obj;
    
    ray r3 = {xyz_expr(0, 0, 0), xyz_expr(0.5, 1, 1)};
    
    ray r = {xyz_expr(0, 0, -5), xyz_expr(0, 0, 1)};
    
    ray r1 = {xyz_expr(0, 0, -5), xyz_expr(1, 1, 1)};
    
    ray r2 = {xyz_expr(0, 0, -0.5), xyz_expr(1, 0.5, 1)};
    
    hit_test hit = intersect(r2, obj1);
    hit_test hit1 = intersect(r3, obj);
    hit_test hit4 = intersect(r, obj2);
    hit_test hit5 = intersect(r1, obj2);
    hit_test hit6 = intersect(r2, obj2);
    
    printf("expecting 6: %f\n", hit4.t);
    printf("expecting  : %f\n", hit.t);
    printf("expecting  : %f\n", hit6.miss);
    printf("expecting  : %f\n", hit.t);*/
}

void evidence_render()
{
    //TESTING horiz_stripes    
     object new_obj1;
     new_obj1.tag = CUBE;
    
    cube cube2    = {{-1.3,0.55,0},1.5,&map_texture_on_cube_faces,{1,1,1}};
     cube2.o = &new_obj1;
     new_obj1.o.c = cube2;
     new_obj1.t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 5);
    
     stage my_stage;
     my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
     my_stage.c.w = 120;
     my_stage.c.h = 120;
     my_stage.s.bg = color_expr(0, 0, 0.5);
     obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
     my_list->obj = new_obj1;
     my_list->next = NULL;
     my_stage.s.objects = my_list;
    light l;
    l.dir = xyz_expr(1, 1, -1);
    l.c = color_expr(0.4, 0.2, 0.1);
    my_stage.s.light = l;
    my_stage.s.amb = color_expr(0.5, 0.5, 0.5);
    
     render(stdout, my_stage);
    
   /* object obj;
    obj.tag = CUBE;
    cube cube1 = {{-1.3,0.55,0},1.5,&map_texture_around_cube,{1,1,1}};
    cube1.o = &obj;
    obj.o.c = cube1;
    obj.t = make_horiz_stripes(color_expr(0.5, 0.5, 0.8), color_expr(0.9, 0, 0), 5);
    
    stage my_stage;
    my_stage.c.loc = xyz_expr(0.0, 0.0, -5);
    my_stage.c.w = 120;
    my_stage.c.h = 120;
    my_stage.s.bg = color_expr(0, 0, 0.5);
    obj_list* my_list = (obj_list*)malloc(sizeof(obj_list));
    my_list->obj = obj;
    my_list->next = NULL;
    my_stage.s.objects = my_list;
    light l;
    l.dir = xyz_expr(1, 1, -1);
    l.c = color_expr(0.4, 0.2, 0.1);
    my_stage.s.light = l;
    my_stage.s.amb = color_expr(0.5, 0.5, 0.5);
    
    render(stdout, my_stage);*/
    
    
    //TESTING spheres
    /*xyz test_xyz = xyz_expr(0, 0, 3);
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
    light l;
    l.dir = xyz_expr(-.59, .59, -.59);
    l.c = color_expr(1, 1, 1);
    my_stage.s.light = l;
    my_stage.s.amb = color_expr(0.1, 0.1, 0.1);
    
    render(stdout, my_stage);*/
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
    evidence_poster_expr();*/
   // evidence_intersect();
    //evidence_trace_ray();
    evidence_render();
  //  evidence_left_test();
    //evidence_top_test();
    //evidence_right_test();
    //evidence_bottom_test();
  //  evidence_pst_int();
    //evidence_cube_int();
    //evidence_intersect();
    return 0;
}