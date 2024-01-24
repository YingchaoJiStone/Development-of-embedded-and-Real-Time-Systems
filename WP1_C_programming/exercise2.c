// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 2
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> //Declare standard IO header
#include <stdlib.h> //Declare standard library header
#include <stdbool.h> //Declare standard boolean header
#include <string.h> //Declare string header

int main (int argc, char *argv[]){ //Main function with argc(length of arguments) and argv(a pointer to an array of command line argument string) 

    if(argc == 2){ //When argument is 2

        int shiftNum = atoi(argv[1]); //Initialize shiftNum by converting the argument from string to integer
    
        while(true){ //Infinite loop for input by input
            char input[30]; //Declare input with 30 length
            scanf("%s", input); //Using scanf method to get input 
            for(int i = 0; i < strlen(input); i++){ //Loop each character to converte

                if(input[i] >= 'A' && input[i] <= 'Z'){ //When the character is upper case letter
                    input[i] = 'A' + (input[i] - 'A' + shiftNum) % 26; //Converting character by adding shifNum. %26 is for avoid the shift number greater than 26
                }else if(input[i] >= 'a' && input[i] <= 'z'){ //When the character is lower case letter
                    input[i] = 'a' + (input[i] - 'a' + shiftNum) % 26; //Converting character by adding shifNum. %26 is for avoid the shift number greater than 26
                }
            }
            
            printf("%s\n", input); //Print the encryped character
        }

    }else { //If argument is not 2
        printf("Usage: %s <Shift number>\n", argv[0]); //Print the Usage information
    }
    
    return 0; //The program is successful with return 0
}
