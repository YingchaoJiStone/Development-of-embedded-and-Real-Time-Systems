// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: 018451 (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header

int main(int argc, char *argv[]) { // Main function with arguments

    if (argc != 6) { // If the number of arguments is not 6
        printf("Arguments number error. \n"); // Print the error prompt
        printf("Usage: ./code <number>  <number> <number> <number> <number>. \n"); // Print the Usage
        return 1; // End program unsuccessful
    }

    int arg1 = atoi(argv[1]); // Convert argument 1 to integer
    int arg2 = atoi(argv[2]); // Convert argument 2 to integer
    int arg3 = atoi(argv[3]); // Convert argument 3 to integer
    int arg4 = atoi(argv[4]); // Convert argument 4 to integer
    int arg5 = atoi(argv[5]); // Convert argument 5 to integer

    if ((arg1 < 0 || arg1 > 1) || (arg2 < 0 || arg2 > 4) || // If argument 1 is between 0 and 1, or argument 2 is between 0 and 4, or
        (arg3 < 0 || arg3 > 2) || (arg4 < 0 || arg4 > 1) || // If argument 3 is between 0 and 2, or argument 4 is between 0 and 1, or
        (arg5 < 0 || arg5 > 1)) { // If argument 5 is between 0 and 1
        printf("Invalid argument range."); // Print invalid prompt
        printf("Usage: ./code <0..1>  <0..4> <0..2> <0..1> <0..1>. \n"); // Print Usage
        return 1; // End program unsuccessful
    }

    int binNum = 0; // Initialize binNum is 0

    // Using bit operation to convert each arguments to binary
    binNum = (binNum << 1) | arg1; // Convert argument 1 to binary. 1 bit 

    for (int i = 2; i >= 0; i--) { // Using for loop convert each bit of argument 2 to binary. 3 bits
        int bit = (arg2 >> i) & 1; // Extract each bit of argument 2
        binNum = (binNum << 1) | bit; // Append the bit to binNum
    }

    for (int i = 1; i >= 0; i--) { // Using for loop convert each bit of argument 3 to binary. 2 bits
        int bit = (arg3 >> i) & 1; // Extract each bit of argument 3
        binNum = (binNum << 1) | bit; // Append the bit to binNum
    }

    binNum = (binNum << 1) | arg4; // Convert argument 4 to binary. 1 bit 
    binNum = (binNum << 1) | arg5; // Convert argument 5 to binary. 1 bit 

    printf("%X\n", binNum); // Print the number in hexadecimal format

    return 0; // End program successful
}
