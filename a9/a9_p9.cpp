#include <iostream>
#include <climits>

// Function returns nothing, takes integer pointer and an integer
// Integer pointer points to an integer array and the integer following it is 
// the size of the array
// Function subtracts the biggest value of the array from each element of the 
// array
void subtract_max(int *arr, int size);

// Function returns nothing, takes integer pointer
// Integer pointer points to an integer array
// Function deallocates by using delete the memory of our array
void deallocate(int *arr);

int main(int argc, char **argv) {
    int n, *arr;

    std::cin >> n;
    arr = new int[n];

    // Here should be the dynamically allocated memory failure check
    // But we haven't been introduced to catching errors thrown (std::bad_alloc)

    // Loop for accepting input
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];

    // Output the values of the array before calling subtract_max()
    std::cout << "Before calling subtract_max() on integer array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    subtract_max(arr, n);

    // Output the values of the array after calling subtract_max()
    std::cout << "After calling subtract_max() on integer array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    deallocate(arr); // Deallocate the dynamically allocated memory of the array

    return 0;
}

void subtract_max(int *arr, int size) {
    int max = INT_MIN;
    // Traverse the array and find the biggest integer
    for (int i = 0; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    // Traverse the array and subtract max from each integer
    for (int i = 0; i < size; i++)
        arr[i] = arr[i] - max;
}

void deallocate(int *arr) {
    // Deallocate dynamically allocated memory
    delete arr;
}