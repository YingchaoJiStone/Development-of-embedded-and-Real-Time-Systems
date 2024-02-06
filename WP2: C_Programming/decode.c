// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 4
// Submission code: xxxxxx (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <string.h> // Declare string library header

int main(int argc, char *argv[]) { // Main function with arguments

    if (argc != 2) { // If the number of arguments is not 2
        printf("Arguments number error. \n"); // Print the error prompt
        printf("Usage: ./decode <hexadecimal number>. \n"); // Print the Usage
        return 1; // End program unsuccessful
    } 

    int decNum = 0; // Initialize decNum is 0
    char *hexaNum = argv[1]; // Initialize hexaNum point argv[1]
    for (int i = strlen(hexaNum) - 1; i >= 0; i --) { // Iterater each charater of argument
        char currentChar = hexaNum[i]; // Initialize currentChar point hexaNum[i]
        int value; // Declare value to calculate the value of each bit 
        if (currentChar >= 'A' && currentChar <= 'F'){ // If the character is between A to F
            value = 10 + currentChar - 'A'; // Calculate the value by - 'A'
        }else if(currentChar >= '0' && currentChar <= '9'){ // If the character is between 0 to 10
            value = currentChar - '0'; // Calculate the value by - '0'
        } else { // When the charater is not a hexadecimal 
            printf("Invalid argument."); // Print invalid prompt
            printf("Usage: ./decode <hexadecimal number>. \n"); // Print the Usage
            return 1; // End program unsuccessful
        }

        int weight = 1; // Initialize a weight 1. When bit is 0 the weight is 1 
        for (int j = strlen(hexaNum) - 1; j > i; j --) { // Using for loop to calculate the weight. one j represent one power
            weight *= 16; // 16^n   n is round of loop
        }

        decNum += weight * value; // Calculate the decimal number by add each weight of bit
    }

    int dec1 = (decNum >> 7) & 1; // Using bit operation to get the value of bit 7, one bit
    int dec2 = (decNum >> 4) & 7; // Using bit operation to get the value of bit 4, 5, 6, three bits. 7 is the biggest number of three bit
    int dec3 = (decNum >> 2) & 3; // Using bit operation to get the value of bit 2, 3, two bits. 3 is the biggest number of two bit 
    int dec4 = (decNum >> 1) & 1; // Using bit operation to get the value of bit 1, one bit
    int dec5 = decNum & 1; // Using bit operation to get the value of bit 0, one bit

    // Print the result as a table
    printf("Name            Value\n");
    printf("-----------------------------\n");
    printf("engine_on         %d\n", dec1);
    printf("gear_pos          %d\n", dec2);
    printf("key_pos           %d\n", dec3);
    printf("brake1            %d\n", dec4);
    printf("brake2            %d\n", dec5);

    return 0; // End program successful
}