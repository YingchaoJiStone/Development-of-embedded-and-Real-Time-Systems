// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 3
// Exercise 3
// Submission code: 021013

#define tem_pin A0 // Define tem_pin as A0, where the temperature sensor is connected

void setup() {
  pinMode(tem_pin, INPUT); // Set the temperature sensor pin as an input
  
  Serial.begin(9600); // Start serial communication at 9600 bits per second
}

void loop() {
  int temperatureValue = analogRead(TMP_PIN); // Read temperature value from the sensor
  float temperature = temperatureValue * (5.0 / 1023.0) * 1000; // Convert the value read to a voltage value
  float temperatureCelsius = (temperature - 500) / 10; // Convert the voltage value to Celsius
  
  Serial.print("Temperature: "); // Print "Temperature: " to the serial monitor
  Serial.print(temperatureCelsius); // Print the calculated temperature value to the serial monitor
  Serial.println(" C"); // Print " C" to denote Celsius and move to a new line
  
  delay(500); // Wait for half a second (500 milliseconds) before repeating the loop
}