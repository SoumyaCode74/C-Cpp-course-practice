/******************************************************************************

Situation:  For a given number, what can be the value of each byte and nibbles?
Task:       Write a program to extract from a given 32-bit number, the positional bytes, 
            and corresponding upper and lower nibbles of each byte
Action:     The following program is written in C that extracts from a random integer

Result:     Original number: 1554589635(0x5ca927c3)
            Byte 0=195, upper nibble=0xc, Lower nibble=0x3
            Byte 1=39, upper nibble=0x2, Lower nibble=0x7
            Byte 2=169, upper nibble=0xa, Lower nibble=0x9
            Byte 3=92, upper nibble=0x5, Lower nibble=0xc

            Original number: -1237037634(0xb6444dbe)
            Byte 0=190, upper nibble=0xb, Lower nibble=0xe
            Byte 1=77, upper nibble=0x4, Lower nibble=0xd
            Byte 2=68, upper nibble=0x4, Lower nibble=0x4
            Byte 3=182, upper nibble=0xb, Lower nibble=0x6

*******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

union test{
    int32_t num;
    struct{
        uint8_t a : 4;
        uint8_t b : 4;
    }bytes[4];
};

int main()
{
    union test Test;
    srand(time(NULL));
    Test.num = (-1 * ( (rand()%2)?1:(-1) )) * rand();
    printf("Original number: %d(0x%x)\n", Test.num, Test.num);
    for(int i = 0; i < 4; i++){
        printf("Byte %d=%d, upper nibble=%#x, Lower nibble=%#x\n", i, (uint8_t)( (Test.num & (0xFF << (i * 8))) >> (i * 8) ), Test.bytes[i].b, Test.bytes[i].a);
    }
    return 0;
}