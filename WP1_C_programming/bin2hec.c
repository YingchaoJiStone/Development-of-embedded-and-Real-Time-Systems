// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: 456333 (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <string.h> // Declare string library header
#include <stdlib.h> // Declare standard library header

long convertBinToDec(char *binStr); // Declare convertBinToDec method

long convertBinToDec(char *binStr){ // The parameter is a pointer of binary string
    long decimal = 0; // Initialize decimal is 0
    while (*binStr != '\0') { // Using while loop and bit operation to convert
        if (*binStr != '0' && *binStr != '1') { // If there is not a binary char in *binStr
            printf("The argument is invalid.\n"); // Print the prompt
            exit(2); //The program is unsuccessful with return 2
        }
        // Using bit operation to calculate the decimal. 
        decimal = (decimal << 1) + (*binStr - '0'); // Life shift will time 2. Then plus (*binStr - '0') = 0 or 1. Since the char '0' and '1' is a continous number.
        binStr++; // Make binStr pointer shift to next
    }
    return decimal; // Return decimal 
}

int main(int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument) 

    char *endptr; //Declare the endptr to estimate whether the read is complete
    long decimal; //Declare the decimal with long type

    //Consider two different ways of executing program, has an argument and no argument
    if(argc == 2){ // When there are an argument when execute program
        if(strcmp(argv[1], "-h") == 0){ // When users apply -help
            printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
            printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
            return 0; //The program is successful with return 0
        }
        //== Can not use this function in this exercise ==//
        //decimal = strtol(argv[1], &endptr, 2); //Using strtol method to convert binary string argument to a integer number. Can not use this function in this exercise
        decimal = convertBinToDec(argv[1]); // Invoke convertBinToDec method to convert binary string to decimal

    }else if(argc == 1){ // When there are no argument, or user use ./dec2bin 12 | ./bin2hec to execute
        char input[65]; // Declare array input with 65 lengths
        scanf("%s", input); // Using scanf method to read the input
        decimal = convertBinToDec(input); // Invoke convertBinToDec method to convert binary string to decimal
    }else{ // When there are over 1 arguments 
        printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
        printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
        return 0; //The program is successful with return 0
    }

    //Convert decimal to hexadecimal 
    printf("%lX\n", decimal); // Convert binary to hexadecimal and print 
    

    return 0; //The program is successful with return 0
}