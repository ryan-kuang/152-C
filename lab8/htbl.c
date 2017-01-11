#include "bucket.h"
#include "htbl.h"

/* hash table of strings, with linked list buckets */

/*
 struct hash_table {
 unsigned long int(*hash)(char *);
 bucket **buckets;
 unsigned int n_buckets;
 };
 typedef struct hash_table htbl;
 */

/* good_hash : char -> unsigned int
 * compute hash code for given string
 * - see description of exercise for algorithm
 */
unsigned long int good_hash(char *s)
{
    unsigned long int res = 17;
    for (; *s != '\0'; s++) {
        res = res*37 + *s;
    }
    return res;
}

/* bad_hash : char -> unsigned int
 * implement this however you like, as long as it's bad
 * strlen seems pretty bad
 */
unsigned long int bad_hash(char *s)
{
    return 37 * strlen(s);
}

/* htbl_new : ((string -> unsigned long),int) -> htbl*
 * allocate space for a new hash table of given size
 * - all buckets must initially be the empty list
 */
htbl *htbl_new(unsigned long int(*h)(char*), unsigned int sz)
{
    htbl* htbl_new = (htbl*)malloc(sizeof(htbl));
    bucket** buckets = (bucket**)malloc(sizeof(bucket*)*sz);
    for (int i = 0; i < sz; i++) {
        buckets[i] = NULL;
    }
    htbl_new->hash = h;
    htbl_new->buckets = buckets;
    htbl_new->n_buckets = sz;
    return htbl_new;
}

/* htbl_num_entries : htbl* -> unsigned int
 * return the total number of entries in all buckets
 */
unsigned int htbl_num_entries(htbl *t)
{
    unsigned int sum = 0;
    for (int i = 0; i < t->n_buckets; i++) {
        sum += bucket_num_entries(t->buckets[i]);
    }
    return sum;
}

/* htbl_load_factor : htbl* -> float
 * The load factor is the mean number of elements per bucket.
 */
double htbl_load_factor(htbl *t)
{
    return htbl_num_entries(t)/(t->n_buckets/1.0);
}

/* htbl_max_bucket : (htbl*, unsigned int*, int*) -> <void>
 * Return, via out parameters, the max number of items in any
 * bucket, and the index of that bucket.
 * - If there is more than one bucket with that number of
 *   items, you may return any of those bucket indexes.
 */
void htbl_max_bucket(htbl *t, unsigned int *m, unsigned int *i)
{
    *m = 0;
    *i = 0;
    for (int n = 0; n < t->n_buckets; n++) {
        if (bucket_num_entries(t->buckets[n]) > *m) {
            *m = bucket_num_entries(t->buckets[n]);
            *i = n;
        }
    }
}

/* htbl_ins : (char*, htbl*, unsigned int*) -> int
 * add string s to hash table t
 * - no special treatment for duplicates, just insert them again
 * - return, via out parameter n, the number of strings in s's bucket
 *   after inserting s
 */
void htbl_ins(char *s, htbl *t, unsigned int *n)
{
    unsigned int index = t->hash(s) % t->n_buckets;
    t->buckets[index] = bucket_cons(s, t->hash(s), t->buckets[index]);
    *n = bucket_num_entries(t->buckets[index]);
}

/* htbl_member : (char*, htbl*) -> int
 * test membership of given string in given table
 */
int htbl_member(char *s, htbl *t)
{
    unsigned int index = t->hash(s) % t->n_buckets;
    return bucket_contains(s, t->hash(s), t->buckets[index]);
}

/* htbl_show : (FILE*, htbl*) -> <void>
 * Print a representation of the hash table to f.
 * See exercise description for details.
 */
void htbl_show(FILE *f, htbl *t)
{
    fprintf(f, "PRINTING BUCKETS\n");
    for (int n = 0; n < t->n_buckets; n++) {
        fprintf(f, "Bucket %d:\n", n);
        bucket_show(f, t->buckets[n]);
        fprintf(f, "\n");
    }
}

/* htbl_free : htbl* -> <void>
 * Be sure to free everything. Drawing a picture may help.
 */
void htbl_free(htbl *t)
{
    for (int n = 0; n < t->n_buckets; n++) {
        bucket_free(t->buckets[n]);
    }
    free(t);
}