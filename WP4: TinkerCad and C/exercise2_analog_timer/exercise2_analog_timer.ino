// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 2
// Submission code: xxxxxx 

#include <Servo.h> // Declare Servo library

int pos = 0; // Initialize position is 0

int seconds = 0; // Initialize seconds is 0

Servo servoSec; // Declare seconds servo
Servo servoMin; // Declare minutes servoSec

void setup()
{
  Serial.begin(9600); // Start Serial communication
  servoSec.attach(5, 500, 2500); // Define servoSec pin is 5 and range is from 500 to 2500
  servoMin.attach(10, 500, 2500); // Define servoMin pin is 10 and range is from 500 to 2500
}

void loop()
{
  // sweep the servo from 0 to 180 degrees in steps
  // of 1 degrees
  for (pos = 0; pos <= 180; pos += 6) {
    
    servoMin.write((seconds / 60) * 6); // Set servoMin to go to position
    
    servoSec.write(pos); // Set servoSec to go to position in variable 'pos'
    
    printTime(seconds); // Invoke printTime function to print time
    
    seconds++; // seconds + 1
    
    delay(1000); // Wait for 1(s)
  }
  for (pos = 174; pos >= 6; pos -= 6) {

    servoSec.write(pos); // Set servoSec to go to position in variable 'pos'
    
    printTime(seconds); // Invoke printTime function to print time
    
    seconds++; // seconds + 1

    delay(1000); // Wait for 1(s)
  }
}

void printTime(int seconds){
	Serial.print(seconds / 60); // Print minutes
    Serial.print("m "); // Print minutes unit
    Serial.print(seconds % 60); // Print seconds
    Serial.println("s"); // Print seconds unit
}