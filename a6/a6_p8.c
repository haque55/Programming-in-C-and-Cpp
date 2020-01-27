#include<stdio.h>
#include<stdlib.h>

struct list {
    int data;
    struct list *next;
};

// Function returns a pointer of type struct list which is a singly linked list
// It takes 2 arguments, a pointer of type struct list and an integer
// The integer is the value which will be added at the end of the list
// It traverses the list and when it reaches the end, it modifies the field
// next of the last element to point to the new element
struct list *push_back(struct list *ptr, int value);

// Function returns a pointer of type struct list which is a singly linked list
// It takes 2 arguments, a pointer of type struct list and an integer
// The integer is the value which will be added at the front of the list
// It pushes the list forward by adding a new element to the list
struct list *push_front(struct list *ptr, int value);

// Function returns a pointer of type struct list which is a singly linked list
// It takes 1 argument, a pointer of type struct list
// It deletes the head of the list and returns the tail of the list
struct list *delete_headElement(struct list *ptr);

// Function returns nothing
// It takes 1 argument, a pointer of type struct list
// It prints the elements of the list by traversing the list
void printList(struct list *ptr);

// Function returns nothing
// It takes 1 argument, a pointer of type struct list
// It frees the memory taken up by the list elements by traversing the list
// and freeing each element
void dispose_list(struct list *ptr);

int main() {
    char ch;
    int num;
    struct list *ptr = NULL;

    while(1) { // Infinite loop to accept new input
        scanf("%c", &ch);

        switch(ch) {
            case 'a':
                scanf("%d", &num);
                getchar();
                ptr = push_back(ptr, num);
                break;
            case 'b':
                scanf("%d", &num);
                getchar();
                ptr = push_front(ptr, num);
                break;
            case 'r':
                getchar();
                ptr = delete_headElement(ptr);
                break;
            case 'p':
                getchar();
                printList(ptr);
                break;
            case 'q':
                getchar();
                dispose_list(ptr);
                return 0;
            default:
                return 0;
        }
    }
}

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