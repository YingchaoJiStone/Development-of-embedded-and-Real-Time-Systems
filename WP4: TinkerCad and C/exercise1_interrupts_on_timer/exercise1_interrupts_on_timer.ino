// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 1
// Submission code: xxxxxx 

#define TEM_PIN A0 // Define temperature sensor pin
#define LED_RED 8 // Define red led pin
#define LED_YELLOW 9 // Define yellow led pin
#define LED_WHITE 10 // Define white led pin
#define LED_GREEN 11 // Define green led pin
#define LED_BLUE 12 // Define blue led pin



void setup()
{
  Serial.begin(9600); // Initialize serial communication
  pinMode(LED_RED, OUTPUT); // Set LED_RED pin as output
  pinMode(LED_YELLOW, OUTPUT); // Set LED_YELLOW pin as output
  pinMode(LED_WHITE, OUTPUT); // Set LED_WHITE pin as output
  pinMode(LED_GREEN, OUTPUT); // Set LED_GREEN pin as output
  pinMode(LED_BLUE, OUTPUT); // Set LED_BLUE pin as output
}

void loop()
{
  int temperatureValue = analogRead(TEM_PIN); // Read temperature value from the sensor
  float temperatureVoltage = temperatureValue * (5.0 / 1023.0) * 1000; // Convert the value read to a voltage value
  float temperatureCelsius = (temperatureVoltage - 500) / 10; // Convert the voltage value to Celsius
  
  Serial.println(temperatureCelsius); // Print the degree celsius
  
  if(temperatureCelsius >= 0 && temperatureCelsius <= 10){ //If temperature is between 0 - 10 degree
  	digitalWrite(LED_BLUE, HIGH); // Turn on blue light
    digitalWrite(LED_GREEN, LOW); // Turn off green light
    digitalWrite(LED_WHITE, LOW); // Turn off white light
    digitalWrite(LED_YELLOW, LOW); // Turn off yellow light
    digitalWrite(LED_RED, LOW); // Turn off red light
  }else if(temperatureCelsius >= 11 && temperatureCelsius <= 20){ //If temperature is between 11 - 20 degree
  	digitalWrite(LED_BLUE, HIGH); // Turn on blue light
    digitalWrite(LED_GREEN, HIGH); // Turn on green light
    digitalWrite(LED_WHITE, LOW); // Turn off white light
    digitalWrite(LED_YELLOW, LOW); // Turn off yellow light
    digitalWrite(LED_RED, LOW); // Turn off red light
  }else if(temperatureCelsius >= 21 && temperatureCelsius <= 30){ //If temperature is between 21 - 30 degree
  	digitalWrite(LED_BLUE, HIGH); // Turn on blue light
    digitalWrite(LED_GREEN, HIGH); // Turn on green light
    digitalWrite(LED_WHITE, HIGH); // Turn off white light
    digitalWrite(LED_YELLOW, LOW); // Turn off yellow light
    digitalWrite(LED_RED, LOW); // Turn off red light
  }else if(temperatureCelsius >= 31 && temperatureCelsius <= 40){ //If temperature is between 31 - 40 degree
  	digitalWrite(LED_BLUE, HIGH); // Turn on blue light
    digitalWrite(LED_GREEN, HIGH); // Turn on green light
    digitalWrite(LED_WHITE, HIGH); // Turn on white light
    digitalWrite(LED_YELLOW, HIGH); // Turn on yellow light
    digitalWrite(LED_RED, LOW); // Turn off red light
  }else if(temperatureCelsius >= 41 && temperatureCelsius <= 50){ //If temperature is between 41 - 50 degree
  	digitalWrite(LED_BLUE, HIGH); // Turn on blue light
    digitalWrite(LED_GREEN, HIGH); // Turn on green light
    digitalWrite(LED_WHITE, HIGH); // Turn on white light
    digitalWrite(LED_YELLOW, HIGH); // Turn on yellow light
    digitalWrite(LED_RED, HIGH); // Turn on red light
  }else{
  	digitalWrite(LED_BLUE, LOW); // Turn off blue light
    digitalWrite(LED_GREEN, LOW); // Turn off green light
    digitalWrite(LED_WHITE, LOW); // Turn off white light
    digitalWrite(LED_YELLOW, LOW); // Turn off yellow light
    digitalWrite(LED_RED, LOW); // Turn off red light
  }
  
  delay(100); // Delay 0.1 second
  
}