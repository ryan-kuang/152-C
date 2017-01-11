/* Ryan Kuang, ryankuang
 * CS152, Winter 2016
 * Homework 1
 */

#include "hw1.h"

double area_box(double width, double height, double depth)
{
    if (width > 0 && height > 0 && depth > 0) {
        return 2 * (width * height + height * depth + width * depth);
    } else {
        fprintf(stderr, "error (area_box): all inputs must be positive\n");
        exit(1); //box dimensions cannot be negative or zero
    }
}

unsigned int digit_letters(unsigned int digit)
{
    if (digit > 9) {
        fprintf(stderr, "error (digit_letters): only single digit inputs\n");
        exit(1);
    } else {
        switch (digit) {
            case 1: //matching digit to cases with three letters
            case 2:
            case 6:
               return 3;
            case 4: //matching digit to cases with four letters
            case 5:
            case 9:
            case 0:
                return 4;
        default: //remaining cases contain five letters
            return 5;
        }
    }
}

int valid_room(unsigned int room)
{
    if (room <= 9924 && room >= 101) { //tests valid floor number
        if (room <= 4836 && 1 <= room % 100 <= 36) { //tests valid room number
            return 1; //returns true
        } else if (room >= 4912 && 12 <= room % 100 <= 24) {
            return 0;
        } else {
            return 0; //returns false
        }
    } else {
        return 0;
    }
}

unsigned int rotary_pulses(unsigned long long int phone_num)
{
    if (phone_num < 10) {
        if (phone_num == 0) { //tests whether phone_num starts with zero
            fprintf(stderr,
                    "error (rotary_pulses): phone number cannot be zeros\n");
            exit(1);
        } else {
            return phone_num;
        }
    } else if (phone_num % 10 == 0) { //modulo gives digit on the right
        return 10 + rotary_pulses(phone_num / 10);
        //counts ten pulses for digit zero
    } else {
        return (phone_num % 10) + rotary_pulses(phone_num / 10);
        //otherwise counts same number of pulses as the digit
    }
}
