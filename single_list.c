#include "single_list.h"

int main(){
    List * start;
    int i = 1;
    start = create_list(i++);
    List * beginning = start; // Retaining the starting address of the list
    for(int j = 1; j < 10; j++){
        // Pass the current container address and receive the latest added container address
        start = add_element_to_bottom(i++, start);
    }
    // Print the 5th element, starting from 0
    printf("5th element in the list: %d\n", get_element_at_index(4, beginning));
    // Print all list elements
    print_list(beginning);
}

List * create_list(uint32_t data){
    List * head = malloc(sizeof(List));
    head -> data = data;
    head -> next = NULL;
    return head;
}

List * add_element_to_bottom(uint32_t data, List * head){
    // Create the container to add, and put in the data in the container
    List * container = create_list(data);
    // Link the container to the supplied container by adding to the back of the supplied container
    // add_element_to_top strategy would assign the head's address to container -> next    
    head -> next = container;
    // Return the address of the last added container for the next container to add in
    return container;
}

uint32_t get_element_at_index(uint32_t index, List * head){
    /* 
    * this function should return the data of the container at the provided index
    * it will loop until the index is reached
    * while looping, it will check whether the presently reached container address is NULL
    * if it's NULL, it will exit program, by printing error message to stderr
    * else, it will complete loop, and return the data
    */
    List *h = head;
    for(int i = 0; i < index; i++){
        if (h != NULL){
            // Traverse through the list with changing links to reach the desired container
            h = h -> next;
        }
        else{
            printf("[ERROR]: Index out of bounds: %d\n", index);
            exit(1);
            }
        }
    return h -> data;
}

void print_list(List * head)
{
    /* 
    * this function should print all the elements of the list, starting from the head
    * until the tail is reached, it loops and prints the data of each container starting from the head
    */
    List * h = head;
    while(h != NULL){
        printf("%d <--> ", h -> data);
        h = h -> next;
    }
    printf("END\n");
}