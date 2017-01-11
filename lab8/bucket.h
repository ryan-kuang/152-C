#ifndef _BUCKET_H
#define _BUCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* bucket: linked list of hash table entries */

typedef struct bucket bucket;
struct bucket {
  char *s;
  unsigned long int hash; 
  /* store the hash with the string for faster comparison */
  bucket *next;
};

/* bucket_cons : (char*,unsigned long,bucket*) -> bucket* 
 * Given a string, a hash function, and a bucket, insert
 * the string into the bucket.
 * Copy the string with strdup so as to get a new copy.
 */
bucket *bucket_cons(char *s, unsigned long h, bucket *b);

/* bucket_num_entries : bucket* -> unsigned int */
unsigned int bucket_num_entries(bucket *b);

/* bucket_contains : (char*,unsigned long int,bucket*) -> int
 * Look for string in bucket.
 * - note: check first that hashes are equal, and only then call
 *   strcmp; strcmp is relatively expensive, so this is a savings
 */
int bucket_contains(char *s, unsigned long int h, bucket *b);

/* bucket_show : (FILE*,bucket*) -> <void> 
 * Display bucket to FILE *f.
 * You may display it in any format you like (within reason).
 */
void bucket_show(FILE *f, bucket *b);

/* bucket_free : bucket* -> <void> */
void bucket_free(bucket *b);

#endif /* _BUCKET_H */
