/**********************************************************************************
****** C program to sort a singly linked list of integers in ascending order ****** 
***********************************************************************************/

#include "sorted_linked_list.h"

int main(void){
    /* Create the first element of the linked list with initial value 0*/
    List * start = create_element_of_list(0);
    /* Store the first value */
    scanf("%d", &(start->data));
    /* Create the linked list of NUMBER_OF_ELEMENTS number of elements */
    for(int i = 2; i <= NUMBER_OF_ELEMENTS; i++){
        start = take_input_and_place_element_on_top(start);
    }
    /* Save the address of the HEAD of the list */
    List * beginning = start;
    /* Print the list before sorting */
    printf("Before sorting:\n");
    print_list(beginning);
    /* Sort the list using bubble sort algorithm */
    bubble_sort_list(beginning);
    /* Print the list after sorting */
    printf("After sorting:\n");
    print_list(beginning);
    return 0;
}

/* Define a function to create an element of a singly-linked list */
List * create_element_of_list(int32_t data){
    List * head = malloc(sizeof(List));
    head->data = data;
    head->next = NULL;
    return head;
}

/* Define a function to take input from user and place on top of the list */
List * take_input_and_place_element_on_top(List * head){
    uint32_t input_data;
    scanf("%d", &input_data);
    /* With the input from the user, create a container containing the data */
    List * container = create_element_of_list(input_data);
    /* Link the passed container "below" the new container */
    if (head != NULL){
        container->data = input_data;
        container->next = head;
    }
    else{
        container->data = input_data;
        container->next = NULL;
    }
    return container;
}
/* Define a function to sort the list elements' data in ascending order, using bubble-sort */
void bubble_sort_list(List * head){
    /* The idea is to iterate the list, save the container data at current iteration, 
     * run another loop to iterate the entire list, comparing the saved container data,
     * and swapping the saved data with the currently reached container data of the second
     * loop. Only the data are swapped, the addresses of containers maintained the same
    */
    int32_t tmp, present_data, compare_data;
    List * compare_element = head;
    List * present_element = head;
    List * beginning = head;
    while(present_element != NULL){
        compare_element = beginning;
        present_data = present_element -> data;
        while(compare_element != NULL){
            compare_data = compare_element -> data;
            if (compare_data > present_data){
                tmp = present_element -> data;
                present_element -> data = compare_element -> data;
                compare_element -> data = tmp;
                }
            compare_element = compare_element->next;
        }
        present_element = present_element -> next;
    }
}
/* Define a function to print each element's data of the list, starting from the address passed */
void print_list(List * head){
    while(head != NULL){
        if ((head -> data) < 0){
            printf("(%d)-->", head->data);
        }
        else{
            printf("%d-->", head->data);
        }
        head = head->next;
    }
    printf("END\n");
}