#include <stdlib.h>
#include <stdio.h>

/* Problem 1 */
/* area_box: calculates total outside surface area (double) of a 3-D box
 * given width, height, depth as doubles
 */
double area_box(double width, double height, double depth);

/* Problem 2 */
/* digit_letters: returns the number of letters in a digit's English word
 * takes in a single digit 0~9
 */
unsigned int digit_letters(unsigned int digit);

/* Problem 3 */
/* valid_room: given a room number, determines if it corresponds
 * to a valid room in the Roebuck Tower
 */
int valid_room(unsigned int room);

/* Problem 4 */
/* rotary_pulses: given a phone number, computes the number of pulses
 * required to dial the number
 * for assignment purposes, only calling phone numbers that solely
 * consist of zeros as error
 */
unsigned int rotary_pulses(unsigned long long int phone_num);
