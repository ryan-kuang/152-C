#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>

#include "bucket.h"
#include "htbl.h"

#define DEFAULT_SIZE  11 /* default hash table size */
#define MAX_LINE_LEN 256 /* maximum length for lines read from stdin */

/* allocate a string on the heap and fill it with '\0' */
char *alloc_str(int sz) 
{
  char *s = malloc(sz);
  if (s==NULL) {
    fprintf(stderr,"alloc_str: malloc failed\n");
    exit(1);
  }
  memset(s,0,sz);
  return s;
}

/* trim_newline replaces the newline at the end of the string (if there
 * is one) with '\0', and then calls strdup on the result,
 * returning a pointer to the duplicated string.
 */
char *trim_newline(char *s)
{
  unsigned int slen = strlen(s);
  char *t = strdup(s);
  if (strlen(t)&&s[slen-1]=='\n')
    t[slen-1]='\0'; 
  return t;
  /* note: This implementation may result in a string (t) that is 
   * one byte longer than strictly necessary. We choose to pay that
   * modest price rather than complicate the code.
   */
}

/* display usage message */
void usage(char *exec_name)
{
  fprintf(stderr,"Usage: %s [OPTIONS]\n", exec_name);
  fprintf(stderr,"Options:\n");
  fprintf(stderr,"  -b      \tuse bad hash function\n");
  fprintf(stderr,"  -s <num>\tuse <num> (positive int) table size\n");
}

/* main:
 * read an optional size argument for hash table,
 * read in strings from standard input,
 * build hash table,
 * display hash table and a few statistics */
int main(int argc, char *argv[])
{
  htbl *t;
  int sz = DEFAULT_SIZE;
  int use_bad_hash = 0;
  char c;
  /* note: read about "getopt" to learn about command-line arg processing */
  while ((c=getopt(argc,argv,"bs:"))!=-1) {
    switch (c) {
    case 'b':
      use_bad_hash = 1;
      break;
    case 's':
      sz = atoi(optarg);
      if (sz<1) {
	fprintf(stderr,"%s error: nonpositive table size %d\n",*argv,sz);
	exit(1);
      }
      break;
    case '?':
      usage(*argv);
      exit(1);
    }
  }
  /* build a new empty hash table */
  t = htbl_new(use_bad_hash?&bad_hash:&good_hash,sz);
  /* read a line at a time from stdin, add non-empty strings to the table */
  while (!feof(stdin)) {
    char *s = alloc_str(MAX_LINE_LEN);
    char *l;
    unsigned int n;
    fgets(s,MAX_LINE_LEN,stdin);
    l = trim_newline(s);
    free(s);
    if (strlen(l)>0)
      htbl_ins(l,t,&n);
    free(l);
  }
  htbl_show(stdout,t);
  printf("\nThe hash table has %i buckets with %i entries (load factor %lg).\n",
	 t->n_buckets, 
	 htbl_num_entries(t),
	 htbl_load_factor(t));
  unsigned int max, max_index;
  htbl_max_bucket(t,&max,&max_index);
  printf("\nThe bucket with the most items in it contains %u items (bucket %u).\n",
	 max,max_index);
  /* test hash table membership */
  /* "aardvark" is not in the cnet file; "borja" is */
  printf("\ntesting htbl_member:\n");
  printf("membership of cnet \"aardvark\" (expecting 0): %i\n", 
	 htbl_member("aardvark",t));
  printf("membership of cnet \"borja\"    (expecting 1): %i\n", 
	 htbl_member("borja",t));
  htbl_free(t);
  return 0;
}
