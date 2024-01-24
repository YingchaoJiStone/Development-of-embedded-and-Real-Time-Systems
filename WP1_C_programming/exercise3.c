// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 3
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header
#include <time.h> // Declare the time library header to use time() method
#include <stdbool.h> // Declare the standard boolean library header
#define MAX_NUMBER 10 // Define Max_NUMBER

int main (int argc, char *argv[]){

    while(true){ // Using infinite while loop  until user want to end the game 

        int countGuess = 0; // Initialize countGuess is 0

        srand(time(NULL)); // Using current time as a seed to get different random number each time
        int randomNum = rand() % 100 + 1; // Using rand() method + 1 to get random number that from 1 to 100

        while(countGuess < MAX_NUMBER){ // Using while loop until guess correctly or excedds the value MAX_NUMBER

            printf("Please guess the random number between 1 to 100(You can guess up to %d times): \n", MAX_NUMBER); // Print prompt statement
            int guessNum; // Declare guessNum
            int isNumber = scanf("%d", &guessNum); // Using scanf method to store input value to guessNum.

            if(isNumber == 1 && guessNum >= 1 && guessNum <= 100){ // When the input is number and between 1 to 100

                countGuess ++; // countGuess + 1 each guess

                if(guessNum > randomNum){ // When guessNum > randomNum
                    printf("Your guess is too high.\n"); // Print high prompt
                }else if(guessNum < randomNum){ // When guessNum < randomNum
                    printf("Your guess is too low.\n"); // Print low prompt
                }else{ // When guessNum == randomNum, guess correctly
                    printf("You have guessed %d times and your guess is correct.\n", countGuess); // Print the success prompt
                    break; // Break the loop
                }

            }else { // When the input is invalid
                printf("Please input a valid number and between 1 to 100.\n"); // Print invalid prompt
                while(getchar() != '\n'); // Clear input buffer by reading and ignore the characters in the buffer
            }

            
        }

        printf("You already guess %d times, this round is over.\n", MAX_NUMBER); //Guess MAX_NUMBER but do not guess correctly, print prompt

        printf("Enter any key to start a new round or enter 'N' to end the game.\n"); //Asked for a new round or to finish
        char isEnd; // Declare isEnd to estimate if end the game
        scanf(" %c", &isEnd); // Add a space before %c to consume any leading whitespace
        if(isEnd == 'N' || isEnd == 'n'){ // If user input 'N' or 'n'
            printf("Game Over.\n"); // Game over
            break; // Break the loop to end game
        }

    }
    
    return 0; //The program is successful with return 0
}