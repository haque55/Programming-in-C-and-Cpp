/* *******************************************************
* * ...
* *
* Perform different actions on a stack of char pointers which represents a
* sentence made up of words
* It pushes char pointers onto the stack, checks if the sentence is palindromic
* by words and empties the stack
* *
* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - *
* Function declarations
* *
* push - Pushes an element onto the stack
* checkPalindrome - Checks if the sentence, pushed word by word in the stack
*                   is palindromic by words
* empty - Empties the whole stack
* *
* ... *
******************************************************* */

struct stack {
    unsigned int count;
    char *array[50]; // Container of 50 char pointers
};

// Function returns nothing
// It pushes the words onto the Stack up to a limit in case that we try to push
// a new element that increases the stack size more than the amount allowed
void push(struct stack *Stack, char *ptrWord);

// Function returns nothing, takes a struct stack pointer and an int pointer
// It checks if the sentence, separated into words, that is put in the Stack
// is palindromic by words
// The int pointer is used to count the number of successful comparisons between
// words of the sentence
void checkPalindrome(struct stack *Stack, int *counter);

// Function returns nothing
// It empties the Stack by popping each element from the stack
void empty(struct stack *Stack);