# Makefile for CS152 lab8 Winter 2016

.PHONY : clean

htbl: bucket.h bucket.c htbl.h htbl.c htbl-main.c
	clang -g -Wall -o htbl bucket.c htbl.c htbl-main.c -lm

clean:
	rm -rf htbl *.dSYM a.out
