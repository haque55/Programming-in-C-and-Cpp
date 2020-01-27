#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

struct list *push_back(struct list *ptr, int value) {
    struct list *cursor, *newElement;
    cursor = ptr;
    newElement = (struct list *) malloc(sizeof(struct list));
    if (newElement == NULL) { // Check if malloc was successful
        return ptr;
    }

    (*newElement).data = value;
    // Last element of the list has to have a NULL next field
    (*newElement).next = NULL;

    // Check if list empty
    if (ptr == NULL)
        return newElement; // Return only the new element as it is the only one
    
    // Traverse the list until we reach the end
    while (((*cursor).next) != NULL) {
        cursor = (*cursor).next; // Move to the next element
    }
    (*cursor).next = newElement; // Point the last element to newElement
    return ptr;
}

struct list *push_front(struct list *ptr, int value) {
    struct list *newElement;
    newElement = (struct list *) malloc(sizeof(struct list));
    if (newElement == NULL) { // Check if malloc was successful
        return ptr;
    }

    (*newElement).data = value;
    (*newElement).next = ptr; // Reference to the first element of the structure

    // Return newElement as the new first element of the structure
    return newElement; 
}

struct list *delete_headElement(struct list *ptr) {
    if(ptr == NULL) { // Check if list is empty
        return ptr; // Return list as there is nothing to delete
    }
    struct list *temp = ptr;
    ptr = (*ptr).next; // ptr links to the next element in the list 
    free(temp);
    return ptr; // Return the tail of the list
}

void printList(struct list *ptr) {
    struct list *cursor = ptr;
    while(cursor != NULL) { // Traverse until we arrive at the end of the list
        printf("%d ", (*cursor).data);
        cursor = (*cursor).next;
    }
    printf("\n");
}

void dispose_list(struct list *ptr) {
    struct list *nextElement;
    while(ptr != NULL) { // Traverse until we arrive at the end of the list
        nextElement = (*ptr).next;
        free(ptr);
        ptr = nextElement; // Link to the following element
    }
}