// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 1
// Submission code: 018451 (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdbool.h> // Declare standard boolean header

enum DIRECTION {N, O, S, W}; // Define enum type DIRECTION to represent four direction

typedef struct { // Define struct type POBOT to combine multible variables of different type
    int xpos; // Represent the position of robot in horizontal
    int ypos; // Represent the position of robot in vertical
    enum DIRECTION dir; // Represent the direction of rebot by using enum type
} ROBOT; // Struct type name

void move(ROBOT *robot); // Declare the void move function with a pointer parameter

void turn(ROBOT *robot); // Declare the void turn function with a pointer parameter

void move(ROBOT *robot){ // The void move function with a pointer parameter
    switch (robot->dir) { // Using switch to move one step on current direction. Using pointer -> to access dir in the ROBOT struct

        case N: // When dir is north
            (robot->ypos)++; // + 1 on Y-axis mean move one step to the north
            break;
        case O: // When dir is east
            (robot->xpos)++; // + 1 on X-axis mean move one step to the east
            break;
        case S: // When dir is south
            (robot->ypos)--; // - 1 on Y-axis mean move one step to the south
            break;
        case W: // When dir is west
            (robot->xpos)--; // - 1 on X-axis mean move one step to the east
            break;
    }
}

void turn(ROBOT *robot){ // The void turn function with a pointer parameter
    robot->dir = ((robot->dir) + 1) % 4; // dir + 1 mean turn 90 degrees clockwise. % 4 make the dir always from 0 to 3  
}

int main(int argc, char *argv[]){ // Invoke the turn and move functions in main function
    
    char exitChar; // Declare exitChar for exiting system
    while (true) { // Using infinit loop to repeat
        ROBOT robot = {0, 0, N}; // Initialize a robot with position x: 0, y: 0 and direction: North
        char command[50]; // Declare char[] command with 50 size to store instructions

        printf("Input starting position(x, y coordinates, ranging between 0-99): \n"); // Print the prompt for asking starting position
        scanf("%d %d", &robot.xpos, &robot.ypos); // Using scanf to store input data: x position and y position
        
        printf("Input charaters 'm'(move) and 't'(turn): \n"); // Print prompt for asking move and turn
        scanf("%s", command); // Using scanf to store the instructions

        for (int i = 0; command[i] != '\0'; i ++) { // Iterate the command to excute instruction one by one
            if (command[i] == 'm') { // If the instruction is move
                move(&robot); // Invoke move function with a pointer parameter 
            }
            if (command[i] == 't') { // If the instruction is turn
                turn(&robot); // Invoke turn function with a pointer parameter
            }
        }

        printf("The new position of the robot is %d %d.\n", robot.xpos, robot.ypos); // Print the end position of robot
        
        printf("Input 'N' to exit or input other to continue: "); // Asking continue or exit
        scanf(" %c", &exitChar); // Store input to exitChar, skip leading whitespace
        if (exitChar == 'N' || exitChar == 'n') { // If input is 'N' or 'n'
            return 0; // Exit program
        }else { // If input is other
            while(getchar() != '\n'); // Clear buffer to avoid affect next round
        }
    }
    

    return 0; // Exit program successful with return 0
}