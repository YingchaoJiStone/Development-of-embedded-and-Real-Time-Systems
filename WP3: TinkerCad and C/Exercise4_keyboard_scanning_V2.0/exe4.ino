// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 3
// Exercise 4
// Submission code: 021013

#include <Keypad.h> // Include the Keypad library to interface with the 4x4 keypad

#define ROW 4 // Define the number of rows in the keypad
#define COL 4 // Define the number of columns in the keypad

// Define the keys on the 4x4 keypad
char keys[ROW][COL] = {
  	{'1','2','3','A'}, // Row 1 keys
  	{'4','5','6','B'}, // Row 2 keys
    {'7','8','9','C'}, // Row 3 keys
    {'*','0','#','D'}, // Row 4 keys
};

// Specify the Arduino pins connected to the keypad rows
byte rowPin[ROW] = {11,10,9,8};
// Specify the Arduino pins connected to the keypad columns
byte colPin[COL] = {7,6,5,4};

// Initialize the keypad by passing the key map, row pins, column pins, and dimensions of the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPin, colPin, ROW, COL);

void setup(){
  Serial.begin(9600); // Start serial communication at 9600 bps
}

void loop(){
  char key = keypad.getKey(); // Get the key that is pressed
  if(key != NO_KEY){ // If a key is pressed (i.e., key is not NO_KEY which indicates no key pressed)
    Serial.println(key); // Print the value of the key that was pressed
    delay(1000); // Wait for 100 milliseconds to debounce and prevent multiple readings
  }
}