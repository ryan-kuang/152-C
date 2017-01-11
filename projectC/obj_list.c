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

/* ======================================== */
/* === object list ops => obj_list.c === */
/* ======================================== */


obj_list *ol_cons(object o, obj_list *os)
{
    obj_list *new_list = (obj_list*)malloc(sizeof(obj_list));
    if (new_list==NULL) {
        fprintf(stderr,"error (ol_cons): malloc failed\n");
        exit(1);
    }
    new_list->obj = o;
    new_list->next = os;
    return new_list;
}

obj_list *ol_singleton(object s)
{
    return ol_cons(s,NULL);
}

/*char *ol_tos(obj_list *os)
{
    int i;
    char buf[256];
    for(i=0;i<256;i++){
        buf[i]='\0';
    }
    while(os!=NULL){
        switch(os->obj.tag){
            case POSTER:
                sprintf(buf,"%f,%f,%f,%f,%f,%f,%f,%f",os->obj.o.p.upper_left.x,os->obj.o.p.upper_left.y,os->obj.o.p.upper_left.z,os->obj.o.p.w,os->obj.o.p.h,os->obj.o.p.shine.r,os->obj.o.p.shine.g,os->obj.o.p.shine.b);
            case SPHERE:
                sprintf(buf,"%f,%f,%f,%f,%f,%f,%f,",os->obj.o.s.center.x,os->obj.o.s.center.y,os->obj.o.s.center.z,os->obj.o.s.radius,os->obj.o.s.shine.r,os->obj.o.s.shine.g,os->obj.o.s.shine.b);
        }
        os=os->next;
    }
    return strdup(buf);
    printf("\n");
}*/

/*void ol_show(FILE *f, obj_list *os)
{
    while(os!=NULL){
        switch(os->obj.tag){
            case POSTER:
                fprintf(f,"%f,%f,%f,%f,%f,%f,%f,%f",os->obj.o.p.upper_left.x,os->obj.o.p.upper_left.y,os->obj.o.p.upper_left.z,os->obj.o.p.w,os->obj.o.p.h,os->obj.o.p.shine.r,os->obj.o.p.shine.g,os->obj.o.p.shine.b);
            case SPHERE:
                fprintf(f,"%f,%f,%f,%f,%f,%f,%f,",os->obj.o.s.center.x,os->obj.o.s.center.y,os->obj.o.s.center.z,os->obj.o.s.radius,os->obj.o.s.shine.r,os->obj.o.s.shine.g,os->obj.o.s.shine.b);
        }
        os = os -> next;
    }
}*/

void ol_free(obj_list *ss)
{
    if (ss) {
        ol_free(ss->next);
        free(ss);
    }
}

//char *ol_tos(obj_list *os);

//void ol_show(FILE *f, obj_list *os);

//void ol_free(obj_list *ss);
