// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 3
// Submission code: 018451 (provided by your TA-s)

#include <stdbool.h> // Declare standard boolean header
#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header
#include <string.h> // Declare string header

// -----typedefs -------
typedef struct { /// Define struct
  char firstname[20]; // Declare firstname with 19 valid size
  char famname[20]; // Declare famname with 19 valid size
  char pers_number[13]; // yyyymmddnnnc
} PERSON; // Struct type name

// Function declaration (to be extend)
PERSON input_record(void);             // Reads a person’s record.
void write_new_file(PERSON *inrecord); // Creates a file and

// writes the first record
void printfile(void);                 // Prints out all persons in the file
void search_by_firstname(char *name); // Prints out the person if

// in list
void append_file(PERSON *inrecord); // appends a new person to the file


int main(void) { // Main function with void argument
  PERSON ppost; // Declare ppost with PERSON type
  int choice; // Declare choice with integer type

  while (true) { // Using infinite loop to choose and excute
    //  // Print options prompt 1 ~ 5
    printf("1 Create a new and delete the old file.\n");
    printf("2 Add a new person to the file.\n");
    printf("3 Search for a person in the file.\n");
    printf("4 Print out all in the file.\n");
    printf("5 Exit the program.\n");

    scanf("%d", &choice); // Scan input and store in choice
    switch (choice) { // Using switch function to choose
        case 1: // When input 1
            ppost = input_record(); // Store person data by calling input_record function
            write_new_file(&ppost); // Call write_new_file function
            break;
        case 2: // When input 2
            ppost = input_record(); // Store person data by calling input_record function
            append_file(&ppost); // Call append_file function
            break;
        case 3: // When input 3
            {
            char firstName[20]; // Declare firstName
            printf("Please input the first name to search: \n"); // Print input prompt
            scanf("%19s", firstName); // Scan input and store in firstName
            search_by_firstname(firstName); // Calling search_by_firstname function
            }
            break;
        case 4: // When input 4
            printfile();  // Calling printfile function
            break;
        case 5: // When input 5
            exit(0); // Exit program
            break;
        default:
            printf("Invalid input. Please input a number between 1 and 5.\n"); // Print invalid input prompt
            while(getchar() != '\n'); // Clear buffer when input invalid
    }
  }

  return(0); // End program successful
}

PERSON input_record(void){
    PERSON person;

    printf("Input first name:\n"); // Print prompt
    scanf("%20s", person.firstname); // Scan input for first name

    printf("Input family name:\n"); // Print prompt
    scanf("%20s", person.famname); // Scan input for family name

    printf("Input personal number:\n"); // Print prompt
    scanf("%12s", person.pers_number); // Scan input for personal number

    return person; // Return the input person
}

void write_new_file(PERSON *inrecord){
    FILE *file = fopen("exercise3.db", "wb"); // Open file or create a new file if it does not exist. "wb" mean binary write mode opens the file

    if (file == NULL) { // If the file fails to open or create
        printf("Create or open file error.\n"); // Print the prompt
        return; // End function
    }
    
    fwrite(inrecord, sizeof(PERSON), 1, file); // Write write 1 PERSON type inrecord to file
    fclose(file); // Close the file after writing
}

void append_file(PERSON *inrecord){
    FILE *file = fopen("exercise3.db", "ab"); // Open file exercise3.db in binary append mode opens the file

    if (file == NULL) { // If the file fails to open
        printf("Open file Error."); // Print the prompt
        return; // End function
    }

    fwrite(inrecord, sizeof(PERSON), 1, file); // Using fwrite function write 1 PERSON type inrecord to file
    fclose(file); // Close the file after write
}

void search_by_firstname(char *name){
    FILE *file = fopen("exercise3.db", "rb"); // Open file exercise3.db in binary read mode opens the file

    if (file == NULL) { // If the file fails to open or create
        printf("Open file error.\n"); // Print the prompt
        return; // End function
    }

    PERSON temp; // Declare temprary PERSON temp
    int countPerson = 0; // Declare countPerson is 0 to count the number of person
    int countMatch = 0;  // Declare countMatch is 0 to count the number of matching
    // Loop through the PERSON data in the file until the file ends or an error occurs. While the result of fread function is 1 mean successful read 1 PERSON.
    while (fread(&temp, sizeof(PERSON), 1, file) == 1) { // Each time fread is called, the file pointer automatically moves forward based on the number of bytes read
        countPerson ++; // countPerson + 1 whenever a person is found
        if (strcmp(temp.firstname, name) == 0) { // If the first name is equal the name
            countMatch ++;
            printf("%s %s %s\n", temp.firstname, temp.famname, temp.pers_number); // Print the person full name
        }
    }
    if (countPerson == 0) { // When no person is found
        printf("The list in file is empty.\n"); // Print empty prompt
    }else {
        if (countMatch == 0) { // When no person is matching
            printf("No person matching.\n"); // Print no matching prompt
        }
    }
    
    fclose(file); // Close file after read
}

void printfile(void){
    FILE *file = fopen("exercise3.db", "rb"); // Open file exercise3.db in binary read mode opens the file

    if (file == NULL) { // If the file fails to open or create
        printf("Open file error.\n"); // Print the prompt
        return; // End function
    }

    PERSON temp; // Declare temprary PERSON temp
    // Loop through the PERSON data in the file until the file ends or an error occurs. While the result of fread function is 1 mean successful read 1 PERSON.
    while (fread(&temp, sizeof(PERSON), 1, file) == 1) { // Each time fread is called, the file pointer automatically moves forward based on the number of bytes read
        printf("%s %s %s\n", temp.firstname, temp.famname, temp.pers_number); // Print all data of persons in file
    }

    fclose(file); // Close file after read
}


