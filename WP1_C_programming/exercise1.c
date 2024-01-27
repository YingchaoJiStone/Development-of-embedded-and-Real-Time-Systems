// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 1
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> //Include standard Input/Output header file
#include <stdbool.h> //Include standard boolean header file to use true

int main(int argc, char *argv[])// main function
{
    while (true) //Usinng while loop to continues ask for new number
    {
        printf("Please input a number between 1-5:\n"); //Print the prompt sentence
        int number;
        scanf("%d", &number); // Using scanf function to read the input number. & is for getting address of number to update it
        
        if (number >= 1 && number <= 5) //Judge if the input number between 1-5
        {
            switch (number) //Using switch to show the different cases
            {
            case 1: //When number == 1
                printf("This is number 1\n"); //Print the unique sentence when number is 1
                break; //Break the switch
            case 2://When number == 2
                printf("This is number 2\n"); //Print the unique sentence when number is 2
                break; //Break the switch
            case 3://When number == 3
                printf("This is number 3\n"); //Print the unique sentence when number is 3
                break; //Break the switch
            case 4://When number == 4
                printf("This is number 4\n"); //Print the unique sentence when number is 4
                break; //Break the switch
            case 5://When number == 5
                printf("This is number 5\n"); //Print the unique sentence when number is 5
                break; //Break the switch
            }
        }else{ //When number is not between 1-5
            printf("Exit\n"); //Print Exit
            break; //Break the while loop
        }
    }

    return 0; //The program is successful with return 0
}