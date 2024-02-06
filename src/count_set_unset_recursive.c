#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int c_set = 0;
int c_reset = 0;

void count_set_unset(int);

int main()
{
    srand(time(NULL));
    int a = (-1*(rand()%2)) * (rand()%(100*100*100*100));
    if(a < 0)
        a += (int)pow(2.0,32.0);    // Get the negative binary equivalent's decimal form
    return 0;
}

void count_set_unset(int n){
    if(n%2)
        c_set += 1;
    else
        c_reset += 1;
    
    if(n/2)
        count_set_unset(n/2);
    else
        printf("No. of set bits: %d, no. of unset bits: %d\n", c_set, c_reset);
}