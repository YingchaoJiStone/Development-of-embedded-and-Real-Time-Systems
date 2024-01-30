// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header
#include <string.h> // Declare string library header

int main(int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument) 

    if(argc != 2 || strcmp(argv[1], "-h") == 0){ //When arguments is incorrect or user apply -help 
        printf("Usage1: %s <decimal number>\n", argv[0]); // Print Usage1 (1 argument)
        printf("Usage2: ./dec2bin <deciaml number> | ./bin2hec\n"); //Print Usage2 (execute two programs in a pipeline)
        return 0;  //The program is successful with return 0
    }

    long decimal = atoi(argv[1]); // Convert the argument to a long type integer

    if(decimal > 0){ // If conversion is successful. decimal == 0 mean conversion is a failure
        int countBits = 0; //Initialize countBits to count the number of bits for deciaml's binary representation
        int temp = decimal; // Copy decimal to a temporary number

        while(temp > 0){ // Using while loop to devide by 2 until temp == 0
            temp >>= 1; // Using bit operation to devide 2 
            countBits ++; // Count the bits
        }

        countBits = 8 * ((countBits + 7) / 8); //Use the smallest possible datatype. Make sure countBits is a multiple of 8

        for(int i = countBits - 1; i >= 0; i--){ // Using for loop print decimal from the highest bit to the lowest bit
            int bit  = (decimal >> i) & 1; // Using bit operation to get number of i bit 
            printf("%d", bit); // Print the bit number
        }

    }else{ // If conversion is unsuccessful
        printf("The argument is invalid.\n"); // Print the prompt
        return 2; //The program is unsuccessful with return 2
    }

    return 0; //The program is successful with return 0
}