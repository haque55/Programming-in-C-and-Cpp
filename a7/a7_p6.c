#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct person {
    char name[30];
    int age;
};

// Function takes 2 person structs and returns an integer
// It compares the name field of the 2 structs and returns a value produced
// by strcmp between the 2 strings if they are different or it 
// returns the difference between the structs ages if struct names match
int compareName(const struct person a, const struct person b);

// Function takes 2 person structs and returns an integer
// It compares the age field of the 2 structs and returns a value produced
// by the difference of ages if they are different or it
// returns the result of strcmp between the structs names if ages are equal
int compareAge(const struct person a, const struct person b);

// Function bubblesort returns nothing
// It takes an array of struct persons, an int that is the number of elements 
// inside the array and a function pointer that is used to compare elements
// It sorts the array by name or age depending on the function comp
// provided
void bubblesort(struct person *arr, int persons,
                int (*comp)(const struct person a, const struct person b));

// Function takes an array of struct persons and an int that is the number of 
// elements in the array
// It prints the elements of the array with format "{name, age}; "
void printPersons(struct person *arr, int persons);

int main() {
    int i, persons;
    struct person *arr;

    scanf("%d", &persons);

    // Dynamically allocate memory for an array of person structures
    arr = (struct person *) malloc(sizeof(struct person) * persons);

    if(arr == NULL)
        exit(1);

    // Loop for input
    for(i = 0; i < persons; i++) {
        getchar();
        fgets((arr[i]).name, sizeof((arr[i]).name),stdin);
        arr[i].name[strlen(arr[i].name)-1] = '\0'; // Place null-terminator
        scanf("%d", &((arr[i]).age));
    }

    // Sort by name and print on stdout
    bubblesort(arr, persons, compareName);
    printPersons(arr, persons);

    // Sort by age and print on stdout
    bubblesort(arr, persons, compareAge);
    printPersons(arr, persons);

    free(arr);
    return 0;
}

int compareName(const struct person a, const struct person b) {
    int comparison = strcmp(a.name, b.name);
    // Check if name field is equal
    if(comparison == 0){ // Return value based on age difference
        return a.age - b.age;
    } else {
        // Return comparison as it can be either positive or negative
        // matching our swap mechanism
        return comparison;
    }
}

int compareAge(const struct person a, const struct person b) {
    // Check if age field is equal
    if(a.age == b.age){ // Return value based on comparison of name field
        return strcmp(a.name, b.name);
    } else {
        // Return age difference as it can be either positive or negative
        // matching our swap mechanism
        return a.age - b.age; 
    }
}

void bubblesort(struct person *arr, int persons,
                int (*comp)(const struct person a, const struct person b)) {
    int i;

    bool swapped = true;
    while(swapped){ // Iterate until we can not swap our element anymore
        swapped = false;
        for(i = 1; i < persons; i++){
            // Swap if return value of comparison is bigger than 0
            if(comp(arr[i-1], arr[i]) > 0){
                // Declare temporary struct to act as a third swap variable
                struct person temp = arr[i-1];
                arr[i-1] = arr[i];
                arr[i] = temp;
                // Change swapped to true to check following element
                swapped = true; 
            }
        }
    }
}

void printPersons(struct person *arr, int persons) {
    // Loop through the array and print each elements' name and age field
    // in a format "{name, age}; "
    for(int i = 0; i < persons; i++){
        printf("{%s, %d}; ", arr[i].name, arr[i].age);
    }
    printf("\n");
    return;
}