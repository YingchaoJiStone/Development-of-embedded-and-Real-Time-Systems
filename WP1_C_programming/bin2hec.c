// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <string.h> // Declare string library header
#include <stdlib.h> // Declare standard library header

int main(int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument) 

    char *endptr; //Declare the endptr to estimate whether the read is complete
    int binary; //Declare the binary to store the binary number

    //Consider two different ways of executing program, has an argument and no argument
    if(argc == 2){ // When there are an argument when execute program
        if(strcmp(argv[1], "-h") == 0){ // When users apply -help
            printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
            printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
            return 0; //The program is successful with return 0
        }

        binary = strtol(argv[1], &endptr, 2); //Using strtol method to convert argument to a binary number

    }else if(argc == 1){ // When there are no argument, or user use ./dec2bin 12 | ./bin2hec to execute
        char input[65]; // Declare array input with 65 lengths
        scanf("%s", input); // Using scanf method to read the input
        binary = strtol(input, &endptr, 2); //Using strtol method to convert input to a binary number
    }else{ // When there are over 1 arguments 
        printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
        printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); // Print Usage2 (execute two programs in a pipeline)
        return 0; //The program is successful with return 0
    }

    //Convert bunary to hexadecimal 
    if(*endptr == '\0'){ // When reading is complete mean conversion is successful
        printf("%x\n", binary); // Convert binary to hexadecimal and print 
    }else{ // When conversion is unsuccessful mean argument is invalid
        printf("The argument is invalid.\n"); // Print the prompt
        return 2; //The program is unsuccessful with return 2
    }

    return 0; //The program is successful with return 0
}