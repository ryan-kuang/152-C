/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 1
 */

#include "hw1.h"

/* Tests for Problem 1 */
void evidence_area_box()
{
    printf("*** testing area_box\n");
    printf("- expecting 6.000000: %lf\n", area_box(1, 1, 1));
    printf("- expecting 69.000000: %lf\n", area_box(1.5, 2, 9));
    printf("- expecting 988.320000: %lf\n", area_box(3.3, 24, 15.2));
    printf("- expecting 1.554218: %lf\n", area_box(0.934, 0.252, 0.45678));
    printf("- expecting 0.093750: %lf\n", area_box(0.125, 0.125, 0.125));
}

/* Tests for Problem 2 */
void evidence_digit_letters()
{
    printf("*** testing digit_letters\n");
    printf("- expecting 5: %u\n", digit_letters(8));
    printf("- expecting 4: %u\n", digit_letters(0));
    printf("- expecting 3: %u\n", digit_letters(2));
    printf("- expecting 4: %u\n", digit_letters(4));
    printf("- expecting 5: %u\n", digit_letters(7));
}

/* Tests for Problem 3 */
void evidence_valid_room()
{
    printf("*** testing valid_room\n");
    printf("- expecting 0: %d\n", valid_room(4836));
    printf("- expecting 1: %d\n", valid_room(4837));
    printf("- expecting 0: %d\n", valid_room(9813));
    printf("- expecting 0: %d\n", valid_room(101));
    printf("- expecting 1: %d\n", valid_room(9925));
    printf("- expecting 1: %d\n", valid_room(-215));
    printf("- expecting 1: %d\n", valid_room(12100));
    printf("- expecting 1: %d\n", valid_room(4900));
}

/* Tests for Problem 4 */
void evidence_rotary_pulses()
{
    printf("*** testing rotary_pulses\n");
    printf("- expecting 46: %d\n", rotary_pulses(7737021234));
    printf("- expecting 59: %d\n", rotary_pulses(6466293706));
    printf("- expecting 56: %d\n", rotary_pulses(1234567800));
    printf("- expecting 91: %d\n", rotary_pulses(1000000000));
    printf("- expecting 96: %d\n", rotary_pulses(100023000000));
    printf("- expecting 6: %d\n", rotary_pulses(123));
    printf("- expecting 125: %d\n", rotary_pulses(90876540302010000));
    printf("- expecting 151: %d\n", rotary_pulses(1000000000000000));
    printf("- expecting 3: %d\n", rotary_pulses(3));
    printf("- expecting 11: %d\n", rotary_pulses(56));
}

/* main: run the evidence functions above */
int main(int argc, char *argv[])
{
    evidence_area_box();
    evidence_digit_letters();
    evidence_valid_room();
    evidence_rotary_pulses();
    return 0;
}
