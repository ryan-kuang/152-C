/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Lab 2
 */

#include "lab2.h"

/* Tests for Hexadecimal Conversions */
void evidence_hex_char()
{
    printf("*** testing hex_char\n");
    printf("- expecting 0F\n");
    hex_char(15);
    printf("\n");
    printf("- expecting 11\n");
    hex_char(17);
    printf("\n");
    printf("- expecting 1E\n");
    hex_char(30);
    printf("\n");
    printf("- expecting 01\n");
    hex_char(1);
    printf("\n");
    printf("- expecting C1\n");
    hex_char(193);
    printf("\n");
    printf("- expecting F0\n");
    hex_char(240);
    printf("\n");
}

void evidence_hex_int()
{
    printf("*** testing hex_int\n");
    printf("- expecting 0000000F\n");
    hex_int(15);
    printf("\n");
    printf("- expecting 00000700\n");
    hex_int(1792);
    printf("\n");
    printf("- expecting 3B87F378\n");
    hex_int(998765432);
    printf("\n");
    printf("- expecting 499602D2\n");
    hex_int(1234567890);
    printf("\n");
    printf("- expecting 00000000\n");
    hex_int(0);
    printf("\n");
    printf("- expecting 0001869F\n");
    hex_int(99999);
    printf("\n");
}

/* Tests for Octal conversions */
void evidence_octal_char()
{
    printf("*** testing octal_char\n");
    printf("- expecting 144\n");
    octal_char(100);
    printf("\n");
    printf("- expecting 011\n");
    octal_char(9);
    printf("\n");
    printf("- expecting 372\n");
    octal_char(250);
    printf("\n");
    printf("- expecting 000\n");
    octal_char(0);
    printf("\n");
    printf("- expecting 111\n");
    octal_char(73);
    printf("\n");
}

void evidence_octal_int()
{
    printf("*** testing octal_int\n");
    printf("- expecting 00000003400\n");
    octal_int(1792);
    printf("\n");
    printf("- expecting 00000000764\n");
   octal_int(500);
    printf("\n");
    printf("- expecting 00000000545\n");
    octal_int(357);
    printf("\n");
    printf("- expecting 00000000000\n");
   octal_int(0);
    printf("\n");
    printf("- expecting 00010000000\n");
    octal_int(2097152);
    printf("\n");
}

/* Tests for Binary conversions */
void evidence_binary_char()
{
    printf("*** testing binary_char\n");
    printf("- expecting 00010001\n");
    binary_char(17);
    printf("\n");
    printf("- expecting 00000001\n");
    binary_char(1);
    printf("\n");
    printf("- expecting 00000010\n");
    binary_char(2);
    printf("\n");
    printf("- expecting 00001000\n");
    binary_char(8);
    printf("\n");
    printf("- expecting 00001101\n");
    binary_char(13);
    printf("\n");
}

void evidence_binary_int()
{
    printf("*** testing binary_int\n");
    printf("- expecting 00000000000000000000000000010001\n");
    binary_int(17);
    printf("\n");
    printf("- expecting 00000000000000000000000000000001\n");
    binary_int(1);
    printf("\n");
    printf("- expecting 00000010000000000000000000000000\n");
    binary_int(16777216);
    printf("\n");
    printf("- expecting 00010000000000000000000000000001\n");
    binary_int(134217729);
    printf("\n");
    printf("- expecting 00000000000000000000000000001101\n");
    binary_int(13);
    printf("\n");
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_hex_char();
    evidence_hex_int();
    evidence_octal_char();
    evidence_octal_int();
    evidence_binary_char();
    evidence_binary_int();
    return 0;
}
