#include "Struct_Rationales.h"

int main()
{
	FILE* ptr = fopen("src/integers.txt", "r");
	if (ptr == NULL) {
		printf("no such file.");
		exit(1);
	}
	int length = 0;
    int index = 0;
    int read_elements[100];
    /* Know the number of rationals to appear */
    fscanf(ptr, "%d ", &read_elements[index]);
    length = read_elements[index];
    /* Define an array to store the integers from the file */
    /* The length is considered twice of the input 'length' 
     * because there are two integers for 1 struct element 
    */
    int integers[(length * 2)];
	while (fscanf(ptr, "%d ", &read_elements[index]) == 1){
        integers[index] = read_elements[index];
        index++;
    }
    /* Define an array for the rationales and an index variable for filling up later*/
    Rationale arr_rationale[length];
    int arr_rationale_index = 0;
    /* Define a for loop to create the rational numbers */
    for(int i = 0; i < (length * 2); i++){
        if (i % 2 == 0)
            arr_rationale[arr_rationale_index].num = (double)integers[i];
        else{
            arr_rationale[arr_rationale_index].den = (double)integers[i];
            arr_rationale_index++;
        }
    }
    /* Calculate the sum of all the rational numbers */
    double sum = 0.0;
    for(int i = 0; i < length - 1; i++){
        sum += add(arr_rationale[i], arr_rationale[i+1]);
    }
    /* Calculate the average */
    double average = sum/length;
    printf("Sum of the rational numbers: %.4lf\n", sum);
    printf("Average of the rational numbers: %.4lf\n", average);
	return 0;
}
/* Define function that returns the addition of two rational numbers */
double add(Rationale a, Rationale b){
    if((a.den != 0) && (b.den != 0))
        return ((a.num/a.den) + (b.num/b.den));
    else{
        printf("Division by 0 found\n");
        exit(1);
    }
}
/* Define function that returns the subtraction of two rational numbers */
double subtract(Rationale a, Rationale b){
    if((a.den != 0) && (b.den != 0))
        return ((a.num/a.den) - (b.num/b.den));
    else{
        printf("Division by 0 found\n");
        exit(1);
    }
}
/* Define function that returns the multiplication of two rational numbers */
double multiply(Rationale a, Rationale b){
    if((a.den != 0) && (b.den != 0))
        return ((a.num/a.den) * (b.num/b.den));
    else{
        printf("Division by 0 found\n");
        exit(1);
    }
}
/* Define function that returns the division of two rational numbers */
double divide(Rationale a, Rationale b){
    if( (a.den != 0) && ( (b.num != 0) && (b.den != 0) ) ) 
        return ((a.num/a.den) / (b.num/b.den));
    else{
        printf("Division by 0 found\n");
        exit(1);
    }
}
