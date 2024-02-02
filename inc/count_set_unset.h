#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/* 
*   Accept the number from user, if not provided, raise error with #error
*   Define a union with 32-bit integer, and a struct array of 4 named bytes, define a member with bit field length 8
*   Write the number taken from user, to the integer of the union
*   Call a function to sweep downwards of the struct array member of the union, 
    check for the first non-zero value and return the number of active bits in the number 
*   Call a function that returns the number of 1s in the passed number
*   Print the number of 1s, subtract from total number of active bits to print the number of 0s
*/

typedef union{
    int32_t input_number;
    struct{
        int8_t byte;
    }bytes[4];
}Input;

Input number;

/* Function to return the number of active bits present */
uint8_t number_of_active_bits(Input);
/* Function to return the number of 1s in the number */
uint8_t number_of_set_bits(Input);
