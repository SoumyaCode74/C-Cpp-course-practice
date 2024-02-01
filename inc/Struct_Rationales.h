#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct rationals{
    double num;
    double den;
}Rationale;

double add(Rationale, Rationale);
double subtract(Rationale, Rationale);
double multiply(Rationale, Rationale);
double divide(Rationale, Rationale);