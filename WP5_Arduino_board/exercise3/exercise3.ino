// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 5
// Exercise 3
// Submission code: 893764

#include <DHT.h>

#define TMP_PIN A0         // Define temperature sensor analog pin A0
#define DHTTYPE DHT11      // Define the temperature sensor type

DHT dht(TMP_PIN, DHTTYPE); // Instantiate DHT

#define LIGHT_PIN A2       // Define light sensor analog Pin A2
#define GREEN_LED 12       // Pin for deviation with normal temperature (GREEN LED)
#define RED_LED 10         // Pin for deviation with higher temperature (RED LED)
#define BLUE_LED 8       // Pin for deviation with lower temperature (BLUE LED)

void setup() {
  Serial.begin(9600);// Initialize serial communication for printing
  dht.begin(); // Initialize DHT sensor
  pinMode(GREEN_LED, OUTPUT); // Set GREEN_LED pin as output
  pinMode(RED_LED, OUTPUT); // Set RED_LED pin as output
  pinMode(BLUE_LED, OUTPUT); // Set BLUE_LED pin as output
  pinMode(A2,INPUT); // Set LIGHT_PIN as input
}

void loop() {
  float temperatureCelsius = dht.readTemperature(); // Using method of DHT library to get the temperature degree
  
  int lightValue = analogRead(LIGHT_PIN); // Read light intensity value from the sensor
  float lightIntensity = map(lightValue, 0, 400, 0, 100); // Map the read value to a 0-100%
  
  // Print celsius temperature 
  Serial.print("Temperature: ");
  Serial.print(temperatureCelsius);
  Serial.println("C");
  // Print light intensity
  Serial.print("Light Intensity: ");
  Serial.print(lightIntensity);
  Serial.println("%");
  
  if(lightIntensity == 0){ // When light intensity is 0
    if(temperatureCelsius < -12){ // When temperature less than -12C
    	normalLight(); // Show normal light
    }else if(temperatureCelsius >= -12){ // When temperature >= -12
      	higherLight(); // Show higher light
    }
  }else if(lightIntensity >= 1 && lightIntensity <= 20){ // When light intensity >= 1% and <= 20%
    if(temperatureCelsius < -12){ // When temperature < -12C
    	lowerLight(); // Show lower light
    }else if(temperatureCelsius > 0){ // When temperature > 0C
    	higherLight(); // Show higher light
    }else{ // When temperature from 12C ~ 0C
    	normalLight(); // Show normal light
    }
  }else if(lightIntensity >= 21 && lightIntensity <= 60){ // When light intensity >= 21% and <= 60%
  	if(temperatureCelsius < 0){ // When temperature < 0C
    	lowerLight(); // Show lower light
    }else if(temperatureCelsius > 20){ // When temperature > 20C
    	higherLight(); // Show higher light
    }else{ // When temperature from 0C ~ 20C
    	normalLight(); // Show normal light
    }
  }else if(lightIntensity >= 61 && lightIntensity <= 100){ // When light intensity >= 61% and <= 100%
  	if(temperatureCelsius >= 21){ // When temperature >= 21C
    	normalLight(); // Show normal light
    }else if(temperatureCelsius < 21){ // When temperature < 21C
      	lowerLight(); // Show lower light
    }
  }

  delay(500); // Delay 0.5 seconds
}

void normalLight(){ // Show normal light function
	digitalWrite(GREEN_LED, HIGH); // Turn on green led
    digitalWrite(RED_LED, LOW); // Turn off red led
    digitalWrite(BLUE_LED, LOW); // Turn off blue led
}

void higherLight(){ // Show higher light function
	digitalWrite(RED_LED, HIGH); // Turn on red led
    digitalWrite(GREEN_LED, LOW); // Turn off green led
    digitalWrite(BLUE_LED, LOW); // Turn off blue led
}

void lowerLight(){ // Show lower light function
	digitalWrite(BLUE_LED, HIGH); // Turn on blue led
    digitalWrite(RED_LED, LOW); // Turn off red led
    digitalWrite(GREEN_LED, LOW); // Turn off green led
}