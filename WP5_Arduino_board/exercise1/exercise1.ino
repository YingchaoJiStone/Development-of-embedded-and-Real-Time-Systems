// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 5
// Exercise 1
// Submission code: 893764

// Define pins of led1, led2 and button
#define led1Pin 12
#define led2Pin 6
#define buttonPin 4

unsigned long previousTime = 0; // Initialize previous time is 0
int intervalTime = 1000; // Define the interval time is 1 second

int buttonState = 0; // Initialize buttonState is 0


void setup(){
  
  Serial.begin(9600); // Initialize serial for print button state
  
  pinMode(led1Pin, OUTPUT); // Set LED 1 pin as output
  pinMode(led2Pin, OUTPUT); // Set LED 2 pin as output
  pinMode(buttonPin, INPUT); // Set button pin as input
  
}

void loop(){
  
  unsigned long currentTime = millis(); // Get the current time in milliseconds
  if(currentTime - previousTime >= intervalTime){ // When the elapsed time is more than 1 second
    previousTime = currentTime; // Set previousTime to current time
    // Flicker the LED 1
    if(digitalRead(led1Pin) == LOW){ // If led 1 is off
    	digitalWrite(led1Pin, HIGH); // Make the led 1 on
    }else{ // If led 1 is on
    	digitalWrite(led1Pin, LOW); // Make the led 1 is off
    }
  }
  
  buttonState = digitalRead(buttonPin); // Using digitalRead function to read button state
  
  if(buttonState == HIGH){ // If button state is 1
 	digitalWrite(led2Pin, HIGH); // Turn on the led 2
    Serial.println(buttonState); // Print button state
  }else{ // If button state is 0
  	digitalWrite(led2Pin, LOW);// Turn off the led 2
    Serial.println(buttonState); // Print button state
  }
  
  
}