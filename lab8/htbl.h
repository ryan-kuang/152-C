#ifndef _HTBL_H
#define _HTBL_H

#include "bucket.h"

/* hash table of strings, with linked list buckets */

struct hash_table {
  unsigned long int(*hash)(char *);
  bucket **buckets;
  unsigned int n_buckets;
};
typedef struct hash_table htbl;

/* good_hash : char -> unsigned int
 * compute hash code for given string
 * - see description of exercise for algorithm 
 */
unsigned long int good_hash(char *s);

/* bad_hash : char -> unsigned int
 * implement this however you like, as long as it's bad 
 */
unsigned long int bad_hash(char *s);

/* htbl_new : ((string -> unsigned long),int) -> htbl*
 * allocate space for a new hash table of given size
 * - all buckets must initially be the empty list 
 */
htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz);

/* htbl_num_entries : htbl* -> unsigned int
 * return the total number of entries in all buckets 
 */
unsigned int htbl_num_entries(htbl *t);

/* htbl_load_factor : htbl* -> float
 * The load factor is the mean number of elements per bucket. 
 */
double htbl_load_factor(htbl *t);

/* htbl_max_bucket : (htbl*, unsigned int*, int*) -> <void>
 * Return, via out parameters, the max number of items in any
 * bucket, and the index of that bucket.
 * - If there is more than one bucket with that number of
 *   items, you may return any of those bucket indexes.
 */
void htbl_max_bucket(htbl *t, unsigned int *m, unsigned int *i);

/* htbl_ins : (char*, htbl*, unsigned int*) -> int
 * add string s to hash table t 
 * - no special treatment for duplicates, just insert them again
 * - return, via out parameter n, the number of strings in s's bucket 
 *   after inserting s
 */
void htbl_ins(char *s, htbl *t, unsigned int *n);

/* htbl_member : (char*, htbl*) -> int
 * test membership of given string in given table 
 */
int htbl_member(char *s, htbl *t);

/* htbl_show : (FILE*, htbl*) -> <void>
 * Print a representation of the hash table to f.
 * See exercise description for details.
 */
void htbl_show(FILE *f, htbl *t);

/* htbl_free : htbl* -> <void>
 * Be sure to free everything. Drawing a picture may help.
 */
void htbl_free(htbl *t);

#endif /* _HTBL_H */
