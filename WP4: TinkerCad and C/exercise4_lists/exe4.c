// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 4
// Submission code: xxxxxx 

#include <stdio.h> // Declare standard IO header
#include <stdlib.h>// Declare standard library header

int search_number(int number, int tab[], int size); // Declare search_number function that search the number from array

void sort (int number, int tab []); // Declare sort function that sort array from small to large

void printArray(int tab[], int size); // Declare printArray function that print the array

int main(int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument) 

    if (argc != 2) { // If the length of argument is not 2
        printf("Usage: %s <Integer Number>\n", argv[0]); // Print the Usage prompt
        return 0; // Exit the program
    }

    int num = atoi(argv[1]); // Convert the argument to a integer number
    if (num == 0) { // When the return value of atoi function is 0 mean the conversion is failed
        printf("Invalid argument.\n"); // Print prompt
        printf("Usage: %s <Integer Number>\n", argv[0]); // Print Usage
        return 0; // Exit program
    }

    int test[] = {1,2,34,5,67,3,23,12,13,10}; // Initialize test array with value

    int testLength = sizeof(test) / sizeof(test[0]); // Calcute the length of test array

    int index = search_number(num, test, testLength); // Invoke search_number function to get the return value
    printf("Search result(index): %d\n", index); // Print the return found index

    sort(testLength, test); // Invoke sort function to sort array

    printArray(test, testLength); // Invoke printArray function to print array

    return 0; // Exit program successful
}

int search_number(int number, int tab[], int size){ // search_number function to search the number from array

    for (int i = 0; i < size; i++) { // Using for loop to iterate array
        if (number == tab[i]) { // If find the number
            return i; // Return the index of found number
        }
    }

    return -1; // If is not find the number from array, return -1
}

void sort (int number, int tab[]){ // sort function to sort array from small to large
    for(int i = 0; i < number - 1; i ++){ // Iterate number-1 times in first tier loop
        int minimumIndex = i; // Initialize minimum index is the unsorted first number
        for(int j = i + 1; j < number; j ++ ){ // Iterate from i+1 is because the number of index from 0 ~ i has been sorted
            if (tab[j] < tab[minimumIndex]) { // If the number of current index less than the minimum number
                minimumIndex = j; // Let the index of minimum number is current index
            }
        }
        // Swap the number in i and the minimum number
        int temp = tab[i]; // Initialize temp and store the number of index i to the temp
        tab[i] = tab[minimumIndex]; // Store the minimum number in index i
        tab[minimumIndex] = temp; // Store the temp(previous number of index i) in the index of previou minimum number
    }
}

void printArray(int tab[], int size){ // printArray function to print the array
    printf("Sorted array: "); // Print opening
    for(int i = 0; i < size; i ++){ // Using for loop to print each number of index
        printf("%d ", tab[i]); // Print the number
    }
    printf("\n"); // Line feed
}
