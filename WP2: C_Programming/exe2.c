// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 1
// Exercise 2
// Submission code: 018451 (provided by your TA-s)

#include <stdio.h> // Declare standard IO header
#include <stdlib.h> // Declare standard library header
#include <time.h> // Declare time header to get the current time as a seed
#include <alloca.h> // Dclare alloca header for allocating memory

// #### Constants #####
#define MAX 5 // Define the constant MAX is 5

// ##### typedefs ####
typedef struct q { // Define struct type q to combine multiple different type as a node
  int number; // Value of node
  struct q *next; // The next node
  struct q *prev; // The previous node
} REGTYPE; // Struct type name

// ##### Function declarations #####
REGTYPE *random_list(void); // Declare random_list function with return a pointer of REGTYPE type 
REGTYPE *add_first(REGTYPE *temp, int data); // Declare add_first function with two parameters and return a pointer of REGTYPE type
void print_list(int nr, REGTYPE *act_post); // Declare print_list function with two parameters

// ###### Main program #######
int main(int argc, char *argv[]) { // Invoke the random_list and add_first functions in main function 
  int nr = 0; // Initialize nr = 0 to represent the index of linked list
  REGTYPE *act_post, *head = NULL; // Declare *act_post for printing and initialize *head to store the first position of list
  srand(time(0)); // Random seed

  head = random_list(); // Invoke random_list function to create a linked list and store the top node to head
  act_post = head; // Using act_post as a temporary pointer to avoid changing head's pointer value
  print_list(nr, act_post); // Invoke print_list function

  head = add_first(head, rand() % 101); // Invoke add_first function to add a new node with a random number
  nr = 0; // Reset nr = 0
  act_post = head; // Make act_post point to the new top node
  printf("--- After adding --- \n"); // Print boundary
  print_list(nr, act_post); // Invoke print_list function

  // --- Free the allocated memory ---
  while ((act_post = head) != NULL) { // When act_post is NULL over the loop
    head = act_post->next; // Make head point to the next node
    free(act_post); // Free the memory of current node
  }

  return 0; // Exit program successful
}

// ==== End of main ======================================
REGTYPE *random_list(void) { // random_list function with return a pointer of REGTYPE type 
  int nr, i = 0; // Declare nr and initialize i = 0
  REGTYPE *top = NULL, *old = NULL, *item = NULL; // Initialize *top, *old and *item

  for (i = 0; i < MAX; i++) { // Using for loop to create and add node
    nr = rand() % 101; // Create a random number between 0 to 100
    item = (REGTYPE*)malloc(sizeof(REGTYPE)); // Dinamic allocate a memory to store data of REGTYPE type
    item->number = nr; // Set number of item to nr
    item->prev = NULL; // Set prev of item to NULL
    item->next = NULL; // Set next of item to NULL
    if (top == NULL) { // When top is NULL mean this is the first node of list
        top = item; // Set top pointer to item pointer
    }else { // When the top is not the first node of list
        old = top; // Set old pointer to top pointer
        old->prev = item; // Set prev of old to new item pointer
        top = item; // Set top pointer to new item pointer
        top->next = old; // Set next of top to old pointer
    }
  }

  return (top); // Return the top node pointer
}

//==========================================================
REGTYPE *add_first(REGTYPE *temp, int data) { // add_first function with two parameters and return a pointer of REGTYPE type
    REGTYPE *top = (REGTYPE*)malloc(sizeof(REGTYPE)); // Dinamic allocate a memory to store data of REGTYPE type
    top->number = data; // Set number of top to data
    top->next = temp; // Set next of top to temp pointer
    top->prev = NULL; // Set prev of top to null
 
    temp->prev = top; // Set prev of temp to top pointer

    return top; // Return top pointer 
}

void print_list(int nr, REGTYPE *act_post){ // print_list function with two parameters
    while (act_post != NULL) { // Using while loop until the next node is null
        printf("Post nr %d : %d\n", nr++, act_post->number); // Print the position and number
        act_post = act_post->next; // Make act_post point to the next node
    }
}
