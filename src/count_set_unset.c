/*
* Situation:    How many number of bits are set and unset for any 32-bit number?
* Task:         Write a program to report number of bits which are 1 and number of bits 
                which are 0, for a 32-bit number
* Action:       The following C program is written to solve the above mentioned task. 
                User needs to pass the number when prompted, any 32-bit signed integer
* Result:       For input 2,147,483,647 (0x7fffffff), the number of set bits are 31, and unset bits are 1
*/
#include "count_set_unset.h"

uint8_t length_of_number = 0;

int main(void){
    int32_t input;
    uint8_t number_of_ones;
    printf("Enter a positive or negative integer: ");
    scanf("%d",&input);
    number.input_number = input;
    length_of_number = number_of_active_bits(number);
    number_of_ones = number_of_set_bits(number);
    printf("Input number: %d(0x%x)\n", input, input);
    printf("Number of set bits: %d\n", number_of_ones);
    printf("Number of unset bits: %d\n", (length_of_number - number_of_ones));
}

uint8_t number_of_active_bits(Input number){
    for(int i = 3; i >= 0; i--){
        if(number.bytes[i].byte != 0)
            return (i+1)*8;
    }
}

uint8_t number_of_set_bits(Input number){
    int count = 0;
    for(int i = 0; i < length_of_number; i++){
        count += ((number.input_number >> i) & 1); // add a 1 every time the AND operation returns 1
    }
    return count;
}