/**
 * @file 	main.c
 * @brief 	The source code for the calculator application
 * @author	Soumyadeep Bose
 */

#include "main.h"


/**
 * @addtogroup	Global variables
 * @{
 */
int operation;	 			///< The variable to accept what operation to perform
double first_number = 0.0;	///< Variable to store the first number for the operation
double second_number = 0.0; ///< Variable to store the second number for the operation
/**
 * @}
 */

/**
 * @brief 	Main function for the application
 * @param	None
 * @retval	0
 */
int main(){
	printf("Enter the operation to perform: \n1 for Addition\n2 for Subtraction\n3 for Product\n4 for Division\n");
	scanf("%d", &operation);
	printf("Enter the first number: ");
	scanf("%lf", &first_number);
	printf("Enter the second number: ");
	scanf("%lf", &second_number);

	switch(operation){
		case (ADDITION):
			printf("%lf + %lf = %lf", first_number, second_number, addition(first_number, second_number));
			break;
		case (SUBTRACTION):
			printf("%lf - %lf = %lf", first_number, second_number, subtraction(first_number, second_number));
			break;
		case (PRODUCT):
			printf("%lf * %lf = %lf", first_number, second_number, product(first_number, second_number));
			break;
		case (DIVISION):
			if(second_number == 0.0){
				printf("%lf / %lf attempted! Exiting...", first_number, second_number);
				exit(-1);
			}
			printf("%lf / %lf = %lf", first_number, second_number, division(first_number, second_number));
			break;
		default:
			printf("Wrong choice");
			exit(-1);
	}
}

double addition(double a, double b){
	return a + b;
}
double subtraction(double a, double b){
	return a - b;
}
double product(double a, double b){
	return a * b;
}
double division(double a, double b){
	return a / b;
}
