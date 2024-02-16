// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 3
// Exercise 3
// Submission code: 021013

// Define the number of rows and columns of the keypad
#define ROW_num 4
#define COL_num 4

// Define the Arduino pins connected to the keypad rows
int row_pin[ROW_num] = {11, 10, 9, 8};
// Define the Arduino pins connected to the keypad columns
int col_pin[COL_num] = {7, 6, 5, 4};

// Variable to store the key pressed
char key;

void setup(){
  Serial.begin(9600); // Start serial communication at 9600 bps

  // Configure row pins as input with internal pull-up resistor
  for (int i = 0; i < ROW_num; i++){
    pinMode(row_pin[i], INPUT_PULLUP);
  }
                                                                                                                                                                                    
  // Configure column pins as output and set them high
  for(int i = 0; i < COL_num; i++){
    pinMode(col_pin[i], OUTPUT);
    digitalWrite(col_pin[i], HIGH);
  }
  
}
  
// Function to read the pressed key from the keypad
char readKeypad(){
  // Define the layout of the keys on the keypad
  char keys[ROW_num][COL_num] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'},
  };
  
  // Scan each column by setting it low and check each row for a key press
  for (int j = 0; j < COL_num; j++){
    digitalWrite(col_pin[j], LOW); // Set the current column pin low
    for(int i = 0; i < ROW_num; i++){ // Check each row
      if(!digitalRead(row_pin[i])){ // If a key is pressed (row pin reads low because of the pull-up resistor)
        digitalWrite(col_pin[j], HIGH); // Set the column pin back high
        return keys[i][j]; // Return the key pressed
      }
    }
    digitalWrite(col_pin[j], HIGH); // Set the column pin back high if no key is pressed in this column
  }
  return NULL; // Return NULL if no key is pressed
}

void loop(){
  key = readKeypad(); // Read the pressed key
  if(key){ // If a key is pressed
    Serial.println(key); // Print the value of the pressed key
  	delay(1000); // Delay to debounce and prevent multiple reads for a single press
  }
}