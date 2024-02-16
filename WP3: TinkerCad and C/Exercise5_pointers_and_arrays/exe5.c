// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 3
// Exercise 5
// Submission code: 021013 (provided by your TA-s)

#include <stdio.h> // Include the standard input/output library for handling input/output operations
#include <stdlib.h> // Include the standard library for general functions including memory allocation, process control, conversions, and others
#include <time.h> // Include the time library for time functions

#define MAX 10 // Define the maximum number of array

int main() { // The main function where execution starts
    int array[MAX]; // Declare an array of integers with a maximum size of MAX
    int *ptr = array; // Declare a pointer and set it to point to the first element of the array

    srand(time(NULL)); // Seed for random number generation

    for (int i = 0; i < MAX; ++i) { // Fill the array with random integers from 1 to 99
        array[i] = rand() % 99 + 1; // Assign a random number between 1 and 99 to each element of the array
    }

    // Print the requested information
    printf("The value of the address of the array (pointer) is: %p\n", (void *)ptr); // Print the memory address of the array (pointer to the first element)
    printf("First integer in the array is (array[0]): %d\n", *ptr); // Print the first element of the array
    printf("The last integer in the array is: %d\n", array[MAX - 1]); // Print the last element of the array
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int)); // Print the size of an integer in bytes
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array)); // Print the total size of the array in bytes

    // Print each integer value and its double using a pointer
    printf("Values in the array multiplied by two:\n");
    for (int i = 0; i < MAX; ++i) { // Loop through each element of the array
        printf("%d x 2 = %d\n", *ptr, (*ptr) * 2); // Print the current value and its double
        ptr++;  // Move the pointer to the next element in the array
    }

    return 0; // Exit program successful
}