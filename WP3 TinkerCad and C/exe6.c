// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 3
// Exercise 6
// Submission code: 021013 (provided by your TA-s)

#include <stdio.h> // Include the standard input/output header for IO operations
#include <string.h> // Include the string manipulation functions header

void copyString(char *dest,char *src); // Declare a function to copy a string from src to dest

int main(){ // The main function where execution starts
    char str[21]; // Declare an array to hold the input string, with space for 20 characters plus the null terminator
    char copydest[21]; // Declare an array to hold the copied string using copyString function
    char dest[21]; // Declare an array to hold the copied string using strcpy function

    
    // printf("Enter a string : ");
    fgets(str,sizeof(str),stdin); // Read a line of text from stdin (standard input) and store it in str

    str[strcspn(str, "\n")] = '\0'; // Replace the newline character with a null terminator to remove the newline

    strcpy(dest,str); // Use the standard library function strcpy to copy the string from str to dest
    copyString(copydest,str); // Use the custom function copyString to copy the string from str to copydest

    printf("Using library function strcpy(..) : %s\n",dest); // Print the copied string using strcpy
    printf("Using own function void copyString(…) : %s\n",copydest); // Print the copied string using the custom copyString function

    return 0 ; // Return 0 to indicate successful execution
}

void copyString(char *dest,char *src){ // Define the copyString function
    while(*src != '\0'){ // Loop until the null terminator is encountered in the source string
        *dest = *src; // Copy the current character from source to destination
        src++; // Increment the source pointer to point to the next character
        dest++; // Increment the destination pointer to point to the next position
    }
    *dest = '\0'; // Append the null terminator to the end of the destination string
}