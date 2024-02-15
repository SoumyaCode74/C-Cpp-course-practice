/**
 * @file main.h
 * @brief This is a small project on designing a calculator application using C
 * @author: Soumyadeep Bose
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * @addtogroup Enum
 * @{
 */
/**
 * @brief This is an enum describing the ID numbers of the math operations to perform
 */

typedef enum{
	ADDITION = 1,
	SUBTRACTION,
	PRODUCT,
	DIVISION
}Operation;
/**
 * @}
 */

/**
 * @addtogroup Functions
 * @{
 */
/**
 * @brief 		Calculate the addition of two double numbers
 * @param[in] 	First number of type double
 * @param[in] 	Second number of type double
 * @retval		Addition of the two numbers of type double
 */
double addition(double a, double b);
/**
 * @brief		Calculate the subtraction of two double numbers
 * @param[in]	First number of type double
 * @param[in]	Second number of type double
 * @retval		Difference of the two numbers of type double
 */
double subtraction(double a, double b);
/**
 * @brief		Calculate the product of two double numbers
 * @param[in]	First number of type double
 * @param[in]	Second number of type double
 * @retval		Product of the two numbers of type double
 */
double product(double a, double b);
/**
 * @brief		Calculate the division of two double numbers
 * @note		Ensure the denomintor is not equal to zero, else program will exit
 * @param[in]	First number of type double
 * @param[in]	Second number of type double
 * @retval		Division value of the two numbers of type double
 */
double division(double a, double b);

/**
 * @}
 */
#endif /* MAIN_H_ */
