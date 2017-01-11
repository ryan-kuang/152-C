/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 4
 */

#include "hw4.h"

/* Problem 1 */

/* array_char: takes in a string pointer s and delimiter d
 * produces array of characters
 */
char* array_char(char* s, char d)
{
    int i = 0;
    int* word_len = &i;
    char* my_array = (char*)malloc(sizeof(char) * (*word_len + 1));
    while (s[i] != d) {
        if (s[i] == '\0') {
            my_array[i] = '\0';
            i++;
        } else {
            my_array[i] = s[i];
            i++;
        }
    }
    my_array[*word_len + 1] = '\0';
    return my_array;
}

/* prints_arrays: prints arrays of characters in a string */
void prints_arrays(char* s)
{
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

/* num_delim: calculates number of delimiters in string */
int num_delim(char* s, char d)
{
    int i = 0;
    int j = 0;
    while (s[i] != '\0') {
        if (s[i] == d) {
            j++;
            i++;
        }
        i++;
    }
    return j;
}

/* make_array : makes new array based on old array */
char* make_array (char* s, int n)
{
    char* my_array = (char*)malloc(sizeof(char) * (strlen(s)-n));
    for (int i = 0; s[i + n] != '\0'; i++) {
        my_array[i] = s[i + n];
    }
    return my_array;
}

/* split_at: takes in a string pointer s and delimiter d
 * splits string into words, starting a new word
 * each time the delimiter character counts
 * words returned in array of strings
 */
char** split_at(char* s, char d)
{
    int i = 0;
    char** array_strings = (char**)malloc(sizeof(char*)*(num_delim(s, d) + 1));
    while (i < num_delim(s, d)) {
        array_strings[i] = array_char(s, d);
        s = make_array(s, strlen(array_strings[i] +1));
        i++;
    }
    return array_strings;
}

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
struct measurement add_measurements(struct measurement m1, struct measurement m2)
{
    if ((m1.units != m2.units)||(m1.exponent != m2.exponent))
    {
        fprintf(stderr, "error(add_measurements): different units or exponents\n");
        exit(1);
    } else {
        m1.value += m2.value;
        return m1;
    }
}

/* scale_measurement: returns copy of the measurement,
 * with the value scaled by factor lambda
 */
struct measurement scale_measurement(struct measurement m, double lambda)
{
    m.value *= lambda;
    return m;
}

/* multiply_measurements: multiplies two struct measurements
 * units must match but exponents don't
 */
struct measurement multiply_measurements(struct measurement m1, struct measurement m2)
{
    if (m1.units != m2.units)
    {
        fprintf(stderr, "error(multiply_measurements): different exponents\n");
        exit(1);
    } else {
        m1.value *= m2.value;
        m1.exponent += m2.exponent;
        return m1;
    }
}

/* measurement_tos: returns string-formatted version of the measurement,
 * consisting of the number, a space, the units, and a carat ^ and the exponent
 */
char* measurement_tos(struct measurement m)
{
    char buf[128];
    int i;
    for (i = 0; i < 128; i++)
        buf[i] = '\0';
    if (m.exponent == 1) {
        sprintf(buf, "(%lf %s)", m.value, m.units);
    } else {
        sprintf(buf, "(%lf %s%c%d)", m.value, m.units, '^', m.exponent);
    }
    return strdup(buf);
    char* ms = measurement_tos(m);
    free(ms);
}

/* converstion: unit conversion factor */
struct conversion {
    char *from, *to;
    double mult_by;
};

/* convert_units: takes in list of known conversion factors, list length,
 * a measurement and units to convert to
 */
/*struct measurement convert_units(struct conversion* conversions,
                                 unsigned int n_conversions,
                                 struct measurement m,
                                 char* to); */

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
struct int_list int_array_new()
{
    struct int_list my_array;
    struct int_arraylist array;
    my_array.tag = ARRAY;
    my_array.u.array = array;

    return my_array;
}

/* int_linked_new: makes new empty list in linkedlist format */
struct int_list int_linked_new()
{
    struct int_linkedlist linked;
    struct int_linkedlist* A;
    A = NULL;
    linked.next = A;
    linked.val = 0;
    struct int_list my_linked;
    my_linked.tag = LINKED;
    my_linked.u.linked = &linked;

    return my_linked;
}

/* int_list_nth: given an int_list, and unsigned int n
 * returns the nth value in the provided list, using zero-based indexing
 */
int int_list_nth(struct int_list xs, unsigned int n)
{
    int_linkedlist* my_list = xs.u.linked;
    int* temp = (int*)malloc(sizeof(int));
    int* p;
    p = temp;
    if (xs.tag == ARRAY) {
        if (xs.u.array.alen < n) {
            fprintf(stderr, "error (int_list_nth): list is too short");
            exit(1);
        } else {
            return xs.u.array.a[n];
        }
    } else if (xs.tag == LINKED) {
        while (my_list != NULL) { //nth element must be within the list
            if (n == 0) {
                return my_list->val; //return nth element
                break;
            } else {
                my_list = my_list->next;
                n--;
            }
        } //my_list is NULL or n == 1
        if (n > 0) {
            //the nth element is longer than my_list
            fprintf(stderr, "error (int_list_nth): list is too short");
            exit(1);
        }
    }
}

/* int_list_set: overwrites the nth value in the list
 * with the specified new value val
 */
void int_list_set(struct int_list xs, unsigned int n, int val)
{
    if (xs.tag == ARRAY) {
        if (xs.u.array.alen < n) {
            fprintf(stderr, "error (int_list_set): list is too short");
            exit(1);
        } else {
            xs.u.array.a[n] = val;
        }
    } else if (xs.tag == LINKED) {
        int_linkedlist* my_list = xs.u.linked;
        while (my_list != NULL) {
            if (n == 0) {
                my_list->val = val;
                break;
            } else {
                my_list = my_list->next;
                n--;
            }
        }
        if (n > 0) {
            fprintf(stderr, "error (int_list_nth): list is too short");
            exit(1);
        }
    }
}

/* int_list_append: appends given value to end of list */
void int_list_append(struct int_list* xs, int val)
{
    if (xs->tag == ARRAY) {
        int* old_array = xs->u.array.a;
        int* new_array = (int*)malloc(sizeof(int) * (xs->u.array.alen + 1));
        int i = 0;
        while (i < xs->u.array.alen) {
            new_array[i] = xs->u.array.a[i];
            i++;
        }
        new_array[xs->u.array.alen + 1] = val;
        xs->u.array.alen += 1;
        //free(old_array);
        xs->u.array.a = new_array;
    } else if (xs->tag == LINKED) {
        int_linkedlist* my_list = xs->u.linked; //necessary cause never modify head node
        //node to be added to end of list
        int_linkedlist* my_val = (int_linkedlist*)malloc(sizeof(int_linkedlist));
        my_val->val = val;
        my_val->next = NULL; //pointer to null
        //traverse list
        while (my_list->next != NULL) {
            my_list = my_list->next; //not within list bounds?
        }
        my_list->next = my_val;
    }
}

/* int_list_prepend: appends given value to beginning of list */
void int_list_prepend(struct int_list* xs, int val) //diff between this and array
{
    if (xs->tag == ARRAY) {
        int old_alen = xs->u.array.alen;
        int* my_array = (int*)malloc(sizeof(int) * (old_alen + 1));
        my_array[0] = val;
        for (int i = 1; i < old_alen + 1; i++) {
            my_array[i] = xs->u.array.a[i];
        }
       // free(xs->u.array.a); //still need to do this?
        xs->u.array.a = my_array;

    } else if (xs->tag == LINKED) {
        int_linkedlist* my_val = (int_linkedlist*)malloc(sizeof(int_linkedlist));
        my_val->val = val;
        my_val->next = xs->u.linked; //how to start this can't do this?
    }
}

/* int_list_show: prints the contents of the list to the screen */
void int_list_show(struct int_list xs)
{
    if (xs.tag == ARRAY) {
        printf("%d ", xs.u.array.alen);
        int* my_array = xs.u.array.a;
        if (*my_array != NULL) {
            while (*my_array != NULL) {
                printf("%d ", *my_array);
                my_array++;
            }
        } else {
            printf("list does not exist");
        }
    } else if (xs.u.linked != NULL) {
            int_linkedlist* my_list = xs.u.linked;
            while (my_list != NULL) {
                printf("%d ", my_list->val);
                my_list = my_list->next;
            }
        } else {
            printf("list does not exist");
        }
    }

typedef struct digitlist digitlist;

struct digitlist {
    unsigned char digit;
    digitlist* next;
};

digitlist* add_digits(unsigned char base, digitlist* ds1, digitlist* ds2);
