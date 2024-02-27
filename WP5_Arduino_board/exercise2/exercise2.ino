// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 5
// Exercise 2
// Submission code: 893764

#include <DHT.h> // Declare DHT library header

#define TMP_PIN A0        // Define temperature sensor analog pin A0
#define DHTTYPE DHT11     // Define the temperature sensor type

DHT dht(TMP_PIN, DHTTYPE);  // Instantiate DHT 

int ledPins[] = {12, 11, 10, 9, 8};   // Array to hold the pin numbers for the LEDs.

void setup()
{
  Serial.begin(9600); // Initialize serial communication
  dht.begin(); // // Initialize DHT sensor
  for(int i = 0; i < 5; i++){ // Loop 5 times
    pinMode(ledPins[i], OUTPUT); // Set leds pin as OUTPUT
  }
}

void loop()
{
  float temp = dht.readTemperature();  // Using method of DHT library to get the temperature degree
  
  Serial.println(temp); // Print the degree celsius

  int LedOn = 0;  // count the number of lights are turn on

  // close all leds
  for (int i = 0; i < 5; i++) { // Loop 5 times
    digitalWrite(ledPins[i], LOW); // Turn off the leds
  }

  if (temp >= 0 && temp < 10) { //If temperature is between 0 - 10 degree
    LedOn = 1;
  } else if (temp >= 10 && temp < 20) { //If temperature is between 11 - 20 degree
    LedOn = 2;
  } else if (temp >= 20 && temp < 30) { //If temperature is between 21 - 30 degree
    LedOn = 3;
  } else if (temp >= 30 && temp < 40) { //If temperature is between 31 - 40 degree
    LedOn = 4;
  } else if (temp >= 40 ) { // If temperature is greater than or equal 40 degree
    LedOn = 5;
  }
  // Light on corresponing the Leda
  for (int i = 0; i < LedOn; i++) { // Loop 5 times
    digitalWrite(ledPins[i], HIGH); // Turn on the leds
  }
  
  delay(500); // Delay 0.1 second
  
}