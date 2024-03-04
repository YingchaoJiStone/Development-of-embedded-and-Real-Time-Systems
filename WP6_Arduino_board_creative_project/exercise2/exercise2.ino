// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 6
// Exercise 2
// Submission code: 145637

#define ALTRASONIC_PIN 7 // Define ALTRASONIC pin
#define BUZZER 9 // Define BUZZER pin
#define LEDS_NUM 4 // Define number of leds

int ledPins[] = {5, 4, 3, 2}; // Initialize ledPins array to store the led pins
unsigned long previousTime = 0; // Initialize previousTime is  0
int intervalTime = 100; // Initialize intervalTime is 0.1 second

void setup(){
  Serial.begin(9600); // Start serial communication
  pinMode(BUZZER, OUTPUT); // Set the BUZZER pin as an OUTPUT
  for(int i = 0; i < LEDS_NUM; i ++){ // Loop 4 times
    pinMode(ledPins[i], OUTPUT); // Set leds pin as output
  }
}

void loop(){
  
  // Read the duration from the ultrasonic sensor and convert it to distance in centimeters
  long distance = readUltrasonicDuration(ALTRASONIC_PIN, ALTRASONIC_PIN) * 0.01723;
  Serial.println(distance); // Print the distance in centimeters
  
  int num = map(distance, 30, 200, 4, 0); // Mapping distance to number of leds
  if(distance < 30){ // When distance less than 30cm
  	num = -1; // Set num is -1 to blink led
  }
  if(distance > 200){ // If distance greater than 200cm
  	num = 0; // Set num is 0 to turn off all leds
  }
    
  Serial.println(num); // Print num

  turnOnLeds(num); // Invoke turnOnLeds function to turn on leds base on num
  
  makeTone(distance); // Invoke makeTone function to tone base on distance
  
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

void turnOnLeds(int num){
  if(num >= 0){ // When num > 0
  	// Turn on the leds base on num
    for(int i = 0; i < num; i ++){ // Loop num times
      digitalWrite(ledPins[i], HIGH); // Turn on the led
    }
    //Turn off the remaining leds
    for(int i = LEDS_NUM - 1; i >= num; i --){ // loop (total number - turn on number) times
      digitalWrite(ledPins[i], LOW); // Turn off the led
    }
  }else{
    unsigned long currentTime = millis(); // Get currentTime as millisecond
    if(currentTime - previousTime >= intervalTime){ // If time pass intervalTime
      previousTime = currentTime; // Set previousTime is currentTIme
      if(digitalRead(ledPins[3]) == LOW){ // If leds are low, turn on them
          for(int i = 0; i < 4; i ++){ // Loop num times
            digitalWrite(ledPins[i], HIGH); // Turn on the led
          }
      }else{ // If leds are high, turn off them to implement blink
          for(int i = 0; i < 4; i ++){ // Loop num times
            digitalWrite(ledPins[i], LOW); // Turn on the led
          }
      }
    }
    
  }
  
}

void makeTone(long distance){
	if(distance >= 25 && distance <= 200){ // When distance is between 25cm to 200cm
  	tone(BUZZER, 1000, 100); // Buzzer tone with frequency: 1000HZ and duration: 100 milliseconds
  	delay(distance * 4); // Delay base on  distance to implement the shorter distance, the faster the sound
  }
}