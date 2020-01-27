/* *******************************************************
* * ...
* Perform different actions on a singly linked list
* whose node holds two values: data and a pointer to
* the next element of the list
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
* Function declarations
* *
* push_back -- add an element in the end
* push_front -- add an element in the beginning
* delete_headElement - remove the first element of the list and leave the tail
* printList - outputs the data of each element of the list into stdout
* dispose_list -- remove all the elements by freeing up the memory
* 
* ... *
******************************************************* */

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