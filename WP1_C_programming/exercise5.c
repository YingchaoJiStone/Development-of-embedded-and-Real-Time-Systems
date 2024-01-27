// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 5
// Submission code: xxxxxxx (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header
#include <time.h> // Declare time library header

int MAX = 100; // Defines the maximum number of the values in the table
int MAXNUMBER = 20; // Defines the maximum value of random numbers
// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq ); 

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );

// ------ Function definitions ----------
void create_random(int *tab){ // Create random numbers in array tab
    srand(time(NULL)); // Using current time as a seed to get different random numbers 

    for(int i = 0; i < MAX; i ++){ // Using for loop to fill the array with random numbers
        int randomNum = rand() % (MAXNUMBER + 1); // Getting a random number between 0 to MAXNUMBER
        tab[i] = randomNum; // Filling the random number in tab[i]
    }
}

void count_frequency(int *tab, int *freq ){ // Count each number of array tab and save the data in array freq
    for(int i = 0; i <= MAXNUMBER; i ++){ // Using for loop to set each value to 0 of freq array
        freq[i] = 0; // Set each value to 0 
    }
    for(int i = 0; i < MAX; i ++){ // Using for loop to traverse each value of array tab
        freq[tab[i]] ++; // Make each value of array tab as freq's index, and every time travers the same value to + 1 for this index's value in freq array
    }
}

void draw_histogram(int *freq ){ // Draw the histogram by nested loop
    for(int i = 0; i <= MAXNUMBER; i ++){ // First tier loop is for iterating array freq
        if(freq[i] > 0){ // If value of freq[i] > 0, that mean this number appear at least once
            printf("%d      ", i); // Print the number
            for(int j = 0; j < freq[i]; j ++){ // Second loop is for printing the x base on value of freq[i]
                printf("x"); // Print X
            }
            printf("\n"); // Go to next line
        }
    }
}

// ------ Main --------------------------
// The main entry point for the program
// 
// If you choose to go for the optional part
// Please modify it accordingly
int main (int argc, char *argv[]){ // Add arguments to instead MAX and MAXNUMBER

    if(argc == 3){ // If there are 3 arguments
        MAX = atoi(argv[1]);
        MAXNUMBER = atoi(argv[2]);

        int table[MAX], n ; // Declare the array table with MAX length
        int frequency[MAXNUMBER]; // Declare the array frequency with MAXNUMBER length 

        create_random(table); // Invoke the create_random method with a parameter table

        count_frequency(table, frequency); // Invoke the count_frequency method with two parameters

        draw_histogram(frequency); // Invoke the draw_histogram method with a parameter frequency

    }else{
        printf("Usage: %s <MAX> <MAXNUMBER>\n", argv[0]);
    }

    
    
    return 0; // The program is successful with return 0
}


