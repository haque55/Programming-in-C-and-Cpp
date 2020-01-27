#include<stdio.h>
#include<stdlib.h>

int listSize = 0; // Global variable to hold the size of the list

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
// It takes 3 arguments, a pointer of type struct list and 2 integers
// The first integer is the position where we want to place the second integer
// in the list
// It places the new element inside the list by traversing the list until
// we arrive at the position
// It links the previous element to the new element and links the field next of
// the new element to the element that was in the position before
struct list *push(struct list *ptr, int position, int value);

// Function returns a pointer of type struct list which is a singly linked list
// It takes 1 argument, a pointer of type struct list
// It deletes the head of the list and returns the tail of the list
struct list *delete_headElement(struct list *ptr);

// Function returns a pointer of type struct list which is a singly linked list
// It takes 1 argument, a pointer of type struct list
// It reverses the order of the list by traversing the list and changing the 
// field next of each element to link to the previous element on the list
struct list *reverse_order(struct list *ptr);

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
    int pos, num;
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
            case 'i':getchar();
                scanf("%d%d", &pos, &num);
                getchar();
                ptr = push(ptr, pos, num);
                break;
            case 'r':
                getchar();
                ptr = delete_headElement(ptr);
                break;
            case 'R':
                getchar();
                ptr = reverse_order(ptr);
                break;
            case 'p':
                getchar();
                printList(ptr);
                break;
            case 'q':
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
    if (ptr == NULL) {
        listSize++;
        return newElement; // Return only the new element as it is the only one
    }
    
    // Traverse the list until we reach the end
    while (((*cursor).next) != NULL) {
        cursor = (*cursor).next; // Move to the next element
    }
    (*cursor).next = newElement; // Point the last element to newElement
    listSize++;
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

    listSize++;
    // Return newElement as the new first element of the structure
    return newElement; 
}

struct list *push(struct list *ptr, int position, int value) {
    struct list *cursor, *prevElement, *newElement;
    int i = 0;
    cursor = ptr; // Cursor starts at the beginning of the list
    newElement = (struct list *) malloc(sizeof(struct list));

    if(newElement == NULL) { // Check if malloc was successful
        return ptr;
    }

    (*newElement).data = value;
    (*newElement).next = ptr;

    if(position < 0 || position >= listSize) {
        printf("Invalid position!\n");
        return ptr; // Return list if we are trying to access an invalid pos
    }

    // Check if list is empty
    if(ptr == NULL) {
        // In case list is empty the only position available to place newElement
        // in is position 0
        if(position != 0) {
            return ptr;
        } else {
            ptr = newElement; // Only element is newElement in list
            listSize++;
            return ptr;
        }
    } else {
        // When list is not empty and position is 0
        // The case is the same as pushing newElement in front of the list
        if(position == 0) {
            return push_front(ptr, value);
        }
        while (i < position) { // Traverse the list until we arrive at position
            prevElement = cursor; // Store cursor as previous element
            cursor = (*cursor).next; // Move cursor to the following element
            i++;
        }
        // Link next field of newElement to cursor
        (*newElement).next = cursor; 
        // Link next field of previous element to newElement
        (*prevElement).next = newElement;
        listSize++;
    }
    return ptr;
}

struct list *delete_headElement(struct list *ptr) {
    if(ptr == NULL) { // Check if list is empty
        return ptr; // Return list as there is nothing to delete
    }
    struct list *temp = ptr;
    ptr = (*ptr).next; // ptr links to the next element in the list 
    free(temp);
    listSize--;
    return ptr; // Return the tail of the list
}

struct list *reverse_order(struct list *ptr) {
    struct list *cursor, *prevElement = NULL, *nextElement= NULL;
    int i = 0;
    cursor = ptr;
    if(listSize == 0 || listSize == 1) {
        return ptr; // Return the list that we have as the reverse is the same
    } else {
        while(i < listSize) {
            if(i == 0) { // Check if we are at the first element
                prevElement = cursor;
                cursor = (*cursor).next;
                // First element becomes the last element in reverse order list
                (*prevElement).next = NULL; 
            } else if (i == (listSize - 1)) { // Check if we are at last element
                ptr = cursor;
                (*ptr).next = prevElement;
                // Return last element which is new head of reversed list
                return ptr; 
            } else {
                nextElement = (*cursor).next; // Store next field of cursor
                (*cursor).next = prevElement; // Reverse next field of cursor
                // Move to the following element
                prevElement = cursor; 
                cursor = nextElement;
            }
            i++;
        }
    }
    return ptr;
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