/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 2
 */

#include "lab2.h"

/* Helper Functions */
/* prints_zeros: prints leading zeros in base representations */
void prints_zeros(int digits)
{
    if (digits == 0) {
    } else {
        printf("%d", 0);
        prints_zeros(digits - 1);
    }
}

/* general_helper: takes in a base, integer n and number of digits
 * prints binary, octal or hexadecimal representation of integer
 */
void general_helper(unsigned int base, unsigned int n, int digits)
{
    if (n == 0) {
        prints_zeros(digits);
    } else if (n % base == 0) {
        general_helper(base, n / base, digits - 1);
        printf("%d", 0);
    } else if (n % base >= 10) { //for hexadecimal base
        general_helper(base, n / base, digits - 1);
        printf("%c", n % base + 55); //prints letters using ASCII
    } else {
        general_helper(base, n / base, digits - 1);
        printf("%d", n % base);
    }
}

/* Hexadecimal Conversions */
/* hex_char: writes an unsigned char in hexadecimal base 16 */
void hex_char(unsigned char byte)
{
    general_helper(16, byte, 2);
}

/* hex_int: writes an unsigned int in base 6 */
void hex_int(unsigned int n)
{
    general_helper(16, n, 8);
}

/* Octal Conversions */
/* octal_char: writes an unsigned char in octal base 8 */
void octal_char(unsigned char byte)
{
    general_helper(8, byte, 3);
}

/* octal_int: writes an unsigned int in octal base 8 */
void octal_int(unsigned int n)
{
    general_helper(8, n, 11);
}

/* Binary Conversions */
/* binary_char: writes an unsigned char in binary base 2 */
void binary_char(unsigned char byte)
{
    general_helper(2, byte, 8);
}

/* binary_int: writes an unsigned int in binary base 2 */
void binary_int(unsigned int n)
{
    general_helper(2, n, 31);
}
