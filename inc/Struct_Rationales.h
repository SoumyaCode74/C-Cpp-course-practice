#include <stdio.h>
#include <stdint.h>

typedef struct rationals{
    int32_t num;
    int32_t den;
}Rationale;

double add(Rationale, Rationale);
double subtract(Rationale, Rationale);
double multiply(Rationale, Rationale);
double divide(Rationale, Rationale);