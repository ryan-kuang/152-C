# Makefile for Lab 5, CMSC 15200, Feb 2016

xyz: xyz.h xyz.c ev_xyz.c
	clang -lm -g -Wall -o ev_xyz xyz.c ev_xyz.c

color: color.h color.c ev_color.c
	clang -lm -g -Wall -o ev_color color.c ev_color.c

colorlist: color.h color.c colorlist.h colorlist.c ev_colorlist.c
	clang -lm -g -Wall -o ev_colorlist color.c colorlist.c ev_colorlist.c
