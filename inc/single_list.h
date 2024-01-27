#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>

// Define the element (container) structure for the list
typedef struct list{
    uint32_t data;
    struct list * next;
}List;
// Function to create a singly linked list
List * create_list(uint32_t data);
// Function add an element to the back of each previous element of the list
List * add_element_to_bottom(uint32_t data, List * head);
// Function to get the element at the provided index
uint32_t get_element_at_index(uint32_t index, List * head);
// Function to print all elements of the singly linked list
void print_list(List * head);