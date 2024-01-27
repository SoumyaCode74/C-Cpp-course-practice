/*
 * Add a function to ask int input, create a container, and add on top of the existing list.
 * If the list passed is NULL, only create container and add int input
 * Add a function to swap the containers based on the int data, return the starting address of the list
 * pass the starting address of the list to a function that prints all the elements of the list.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NUMBER_OF_ELEMENTS      (5)

typedef struct list{int32_t data; struct list * next;}List;
List * create_element_of_list(int32_t data);
List * take_input_and_place_element_on_top(List * head);
void bubble_sort_list(List * head);
void print_list(List * head);