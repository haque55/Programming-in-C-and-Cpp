#include <stdio.h>
#include <stdlib.h>

int listSize = 0;

struct list {
    char data;
    struct list *prev;
    struct list *next;
};

// Function returns a pointer of type struct list which is a doubly linked list
// It takes 2 arguments, a pointer of type struct list and a char
// The char is the value which will be added at the front of the list
// It pushes the list forward by adding a new element to the list
struct list *push_front(struct list *ptr, char charValue);

// Function returns a pointer of type struct list which is a doubly linked list
// It takes 2 arguments, a pointer of type struct list and a char
// It traverses the list and deletes all the elements of the list that match the
// character
struct list *delete_chars(struct list *ptr, char charValue);

// Function returns nothing
// It takes 1 argument, a pointer of type struct list
// It prints the elements of the list by traversing the list
void printList(struct list *ptr);

// Function returns nothing
// It takes 1 argument, a pointer of type struct list
// It prints the elements of the list by traversing until the end and returning
// back and printing each element along the way back
void printReverseList(struct list *ptr);

// Function returns nothing
// It takes 1 argument, a pointer of type struct list
// It frees the memory taken up by the list elements by traversing the list
// and freeing each element
void dispose_list(struct list *ptr);

int main() {
    int choice;
    char data;
    struct list *ptr = NULL;

    while(1) { // Infinite loop to accept new input
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                scanf("%c", &data);
                ptr = push_front(ptr, data);
                break;
            case 2:
                scanf("%c", &data);
                ptr = delete_chars(ptr, data);
                break;
            case 3:
                printList(ptr);
                break;
            case 4:
                printReverseList(ptr);
                break;
            case 5:
                dispose_list(ptr);
                return 0;
            default:
                return 0;
        }
    }
}

struct list *push_front(struct list *ptr, char charValue) {
    struct list *newElement;
    newElement = (struct list *) malloc(sizeof(struct list));
    if (newElement == NULL) { // Check if malloc was successful
        return ptr;
    }

    // Assign value NULL to prev field and value to data field
    (*newElement).data = charValue;
    (*newElement).prev = NULL;

    // Check if there is no other element on the list
    if(ptr == NULL) {
        // Then newElement is the only element so set next field to NULL
        (*newElement).next = NULL;
    } else {
        // Else next field points to ptr (beginning of the list)
        (*newElement).next = ptr;
        (*ptr).prev = newElement; // ptr prev points to newElement added
    }
    listSize++;
    // Return newElement as the new first element of the structure
    return newElement; 
}

struct list *delete_chars(struct list *ptr, char charValue) {
    struct list *cursor = ptr;
    struct list *temp;
    int count = 0;

    if(ptr == NULL) {
        return ptr;
    }
    
    while(cursor != NULL) { // Traverse until we arrive at the end of the list
        // Check if data field of element is the same as charValue
        if((*cursor).data == charValue) { 
            count++; // Rise count since we found a match
            temp = cursor;
            if(temp == ptr) { // Check if we are at the beginning of the list
                // Check if there is another element after cursor
                if((*cursor).next != NULL) {
                    // Go to next element and remove connection with the deleted
                    // element that contained the char
                    cursor = (*cursor).next;
                    ptr = (*ptr).next;
                    (*ptr).prev = NULL;
                    free(temp);
                } else {
                    free(temp); // Delete element
                    ptr = NULL;
                    return ptr; // As there is no other element
                }
            } else if ((*cursor).next != NULL) { // If there is another element
                // Connect element before and after our cursor and remove
                // element at cursor by freeing temp
                (*(*cursor).prev).next = (*cursor).next;
                (*(*cursor).next).prev = (*cursor).prev;
                cursor = (*cursor).next;
                free(temp);
            } else { // If we are at the end of the list
                // Set previous element to point to NULL
                (*(*cursor).prev).next = NULL; 
                // Move onto "next" field that is empty to end loop
                cursor = (*cursor).next; 
                free(temp);
            }
        } else cursor = (*cursor).next;
    }

    if(count == 0) // Check if there no match at all
        printf("The element is not in the list!\n");

    return ptr;
}

void printList(struct list *ptr) {
    struct list *cursor = ptr;
    while(cursor != NULL) { // Traverse until we arrive at the end of the list
        printf("%c ", (*cursor).data);
        cursor = (*cursor).next; // Move onto the next element
    }
    printf("\n");
}

void printReverseList(struct list *ptr) {
    struct list *cursor;
    cursor = ptr;
    
    // Traverse the list until we reach the end
    while (((*cursor).next) != NULL) {
        cursor = (*cursor).next; // Move to the next element
    }

    while(cursor != NULL) { // Traverse backwards and print each element
        printf("%c ", (*cursor).data);
        cursor = (*cursor).prev; // Move to the previous element
    }
    printf("\n");
}

void dispose_list(struct list *ptr) {
    struct list *nextElement;
    while(ptr != NULL) { // Traverse until we arrive at the end of the list
        nextElement = (*ptr).next; // Save next field of current element
        free(ptr); // Delete current element
        ptr = nextElement; // Link to the following element using the save
    }
}