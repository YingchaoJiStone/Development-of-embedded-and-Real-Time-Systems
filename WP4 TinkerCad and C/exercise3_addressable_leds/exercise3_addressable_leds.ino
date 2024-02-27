// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 3
// Submission code: 797534 

#include <Adafruit_NeoPixel.h> // Delare Adafruit_NeoPixel library

#define ALTRASONIC_PIN 9 // Define altrasonic pin
#define NEOPIXEL_PIN 4 // Define NeoPixel pin
#define LED_RED 6 // Define red led pin
#define BUZZER 12 // Define buzzer pin

// Create a NeoPixel object with 24 pixels, connected to pin 6, using GRB color and a frequency of 800 KHz
Adafruit_NeoPixel neopixel = Adafruit_NeoPixel(24, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup(){ // Setup function runs once at the beginning
  Serial.begin(9600); // Start serial communication
  neopixel.begin(); // Initialize the NeoPixel object
  neopixel.show(); // Turn off all NeoPixels initially
  pinMode(LED_RED, OUTPUT); // Set the LED_RED pin as an OUTPUT
  pinMode(BUZZER, OUTPUT); // Set the BUZZER pin as an OUTPUT
}

void loop() { // Loop function runs repeatedly
  
  // Read the duration from the ultrasonic sensor and convert it to distance in centimeters
  long distance = readUltrasonicDuration(ALTRASONIC_PIN, ALTRASONIC_PIN) * 0.01723;
  Serial.println(distance); // Print the distance in centimeters
  int pixel_index = map(distance, 0, 270, 0, 23);// Map the distance to the corresponding pixel index on the NeoPixel strip
  
  Serial.println(pixel_index);// Print the pixel index
  
  // Turn off pixels beyond the calculated pixel index
  for(int i = neopixel.numPixels() - 1; i >  pixel_index; i--){ // Using for loop to turn of the light according to index
  	neopixel.setPixelColor(i, neopixel.Color(0, 0, 0)); // Set NeoPixel color to null
  	neopixel.show(); // Show NeoPixel light
  }
  
  for(int i = 0; i <= pixel_index; i++){ // Using for loop to turn on the light according to index
  	neopixel.setPixelColor(i, neopixel.Color(255, 0, 0)); // Set NeoPixel color to red
  	neopixel.show(); // Show NeoPixel light
  }
  
  if(pixel_index >=23){ // When pixel_index over the miximum index
  	digitalWrite(LED_RED, HIGH); // Turn on red led
    tone(12, 1000, 500); // Turn on the buzzer
  }else{ // When pixel_index is in range
  	digitalWrite(LED_RED, LOW); // Turn off red led
    noTone(12); // Turn off the buzzer
  }
  
  delay(1000); // Delay 1 secends
  
}

long readUltrasonicDuration(int triggerPin, int echoPin){ // readUltrasonicDuration function to get distance between sensor and object
  pinMode(triggerPin, OUTPUT);// Set the trigger pin as an OUTPUT to send the ultrasonic pulse
  digitalWrite(triggerPin, LOW);// Clear the trigger by setting it to LOW for 2 microseconds
  delayMicroseconds(2);//Delay 2 microseconds. A short delay is used to ensure electrical signal stability
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH); // Sets the trigger pin to HIGH state
  delayMicroseconds(10); //Delay 10 microseconds
  digitalWrite(triggerPin, LOW);// Sets the trigger pin to Low state
  pinMode(echoPin, INPUT);// Set the echo pin as an INPUT to read the returning pulse
  return pulseIn(echoPin, HIGH); // Reads the echo pin, and returns the sound wave travel time in microseconds

}