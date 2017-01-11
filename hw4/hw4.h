#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Problem 1*/

/* array_char: takes in a string pointer s and delimiter d
 * produces array of characters
 */
char* array_char(char* s, char d);

/* prints_arrays: prints arrays of characters in a string */
void prints_arrays(char* s);

/* num_delim: calculates number of delimiters in string */
int num_delim(char* s, char d);

/* make_array : makes new array based on old array */
char* make_array (char* s, int n);

/* split_at: takes in a string pointer s and delimiter d
 * splits string into words, starting a new word
 * each time the delimiter character counts
 * words returned in array of strings
 */
char** split_at(char* s, char d);

/* Problem 2 */

/* struct measurement: represents measurement that
 * consists of a numeric value and a unit
 */
struct measurement {
    double value;
    char* units;
    unsigned int exponent;
};

/* add_measurements: adds two struct measurements
 * prints error and exits if values have different units or exponents
 */
struct measurement add_measurements(struct measurement m1, struct measurement m2);

/* scale_measurement: returns copy of the measurement,
 * with the value scaled by factor lambda
 */
struct measurement scale_measurement(struct measurement m, double lambda);

/* multiply_measurements: multiplies two struct measurements
 * units must match but exponents don't
 */
struct measurement multiply_measurements(struct measurement m1, struct measurement m2);

/* measurement_tos: returns string-formatted version of the measurement,
 * consisting of the number, a space, the units, and a carat ^ and the exponent
 */
char* measurement_tos(struct measurement m);

/* Problem 3 */

/* struct presents list of integers as array */
struct int_arraylist {
    int* a;
    unsigned int alen;
};

typedef struct int_linkedlist int_linkedlist;

/* struct presents list of integers as linked list */
struct int_linkedlist {
    int val;
    int_linkedlist* next;
};

/* union of list of integers as array and linked list  */
union int_listunion {
    struct int_arraylist array;
    int_linkedlist* linked;
};

/* type consisting of arrays and linked lists */
enum int_listtag {
    ARRAY, LINKED
};

/* struct indicating name of list and data type */
struct int_list {
    enum int_listtag tag;
    union int_listunion u;
};

/* int_array_new: makes new empty list in array format */
struct int_list int_array_new();

/* int_linked_new: makes new empty list in linkedlist format */
struct int_list int_linked_new();

/* int_list_nth: given an int_list, and unsigned int n
 * returns the nth value in the provided list, using zero-based indexing
 */
int int_list_nth(struct int_list xs, unsigned int n);

/* int_list_set: overwrites the nth value in the list
 * with the specified new value val
 */
void int_list_set(struct int_list xs, unsigned int n, int val);

/* int_list_append: appends given value to end of list */
void int_list_append(struct int_list* xs, int val);

/* int_list_prepend: appends given value to end of list */
void int_list_prepend(struct int_list* xs, int val);

/* int_list_show: appends given value to end of list */
void int_list_show(struct int_list xs);
