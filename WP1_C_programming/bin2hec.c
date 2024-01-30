// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: 456333 (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <string.h> // Declare string library header
#include <stdlib.h> // Declare standard library header

long convertBinToDec(char *binStr);

long convertBinToDec(char *binStr){
    int decimal = 0;
    while (*binStr != '\0') {
        if (*binStr != '0' && *binStr != '1') {
            printf("The argument is invalid.\n"); // Print the prompt
            exit(2); //The program is unsuccessful with return 2
        }
        decimal = (decimal << 1) + (*binStr - '0');
        binStr++;
    }
    return decimal;
}

int main(int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument) 

    char *endptr; //Declare the endptr to estimate whether the read is complete
    int decimal; //Declare the decimal

    //Consider two different ways of executing program, has an argument and no argument
    if(argc == 2){ // When there are an argument when execute program
        if(strcmp(argv[1], "-h") == 0){ // When users apply -help
            printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
            printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
            return 0; //The program is successful with return 0
        }
        //== Can not use this function in this exercise ==//
        //decimal = strtol(argv[1], &endptr, 2); //Using strtol method to convert binary string argument to a integer number. Can not use this function in this exercise
        decimal = convertBinToDec(argv[1]);

    }else if(argc == 1){ // When there are no argument, or user use ./dec2bin 12 | ./bin2hec to execute
        char input[65]; // Declare array input with 65 lengths
        scanf("%s", input); // Using scanf method to read the input
        decimal = convertBinToDec(input);
    }else{ // When there are over 1 arguments 
        printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
        printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
        return 0; //The program is successful with return 0
    }

    //Convert decimal to hexadecimal 
    printf("%X\n", decimal); // Convert binary to hexadecimal and print 
    

    return 0; //The program is successful with return 0
}