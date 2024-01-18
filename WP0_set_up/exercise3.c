// (C) Jessie Johnsson, Lian ShiLian Shi, Yingchao Ji, group: 10 (2024)
// Work package 0
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)
#include <stdio.h> //Include the standard Input/Output library header file
#include <string.h> //Include the string header file for using associate functions, e.g. strcam()

// Main function in the program, no program arguments supported
void main (int argc, char *argv[]) { // The main function. argc is the number of command line arguments. argv is an array of command line arguments
    if(argc < 2 || argc > 2){ // When argc < 2 mean only have name of executable file be inputed, no argument be inputed. When argc > 2 mean grater than 1 argument be inputed 
        printf("Error: Argument error.\n"); // Print the error message
        printf("Usage: %s <argument>\n", argv[0]); // Print the information about the -h
    }else if(strcmp(argv[1], "-h") == 0){ // Using strcmp to compare the argv[1] and '-h', if it is equal
        printf("Usage: %s <argument>\n", argv[0]); // Print the information about the -h
    }else{
        // Print a string to the console
        printf(" Hello World! - I'm %s!\n", argv[1]); // Print the greeting with the name(argv[1])
    }
    
}