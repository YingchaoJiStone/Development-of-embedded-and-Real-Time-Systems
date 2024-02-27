// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 1
// Submission code: 797534 

#define TMP A5    // Define TMP as the analog pin A5 used for temperature sensor input.

int pinLed[] = {13,12,11,8,5};   // Array to hold the pin numbers for the LEDs.
int temperature[] = {0,10,20,30,40};  // appears to be temperature thresholds.
int LedNum = sizeof(pinLed)/sizeof(pinLed[0]);   // Calculate the number of LEDs.

//unsigned long perviousMillis = 0 ;
//const long interval = 1000;

// Setup configuration for the microcontroller.
void setup() {

  for(int i = 0 ; i < LedNum; i ++){
    pinMode(pinLed[i],OUTPUT); // setup each pinmode for Leds
  }

  pinMode(TMP,INPUT);   // Set the temperature sensor pin as input.
    
  cli();  // Disable global interrupts for setup.

  //set timer1 interrupt at 1Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  
  sei();//allow interrupts

  //Timer1.initialize(1000000);
  //Timer1.attachInterrupt(timerISR);

  Serial.begin(9600);   // Start serial communication at 9600 baud rate.

}

void loop() {}   // Main program loop does nothing, functionality is interrupt driven.

int readTemperture(){   // Function to read temperature from sensor and convert it to Celsius.
  int temValue = analogRead(TMP);  // Read the analog value from temperature sensor.
  float temVoltage = temValue * 5.0/1023.0 * 1000;  // Convert that value to millivolts.
  float tem = (temVoltage -500) / 10;   // Convert millivolts to Celsius.
  return (int)tem;   //Return the temperature as an integer.
}

// Function to turn on LEDs according to the temperature.
void readTemAndLedOn(int temp) {
  int LedOn = 0;  // count the number of lights are turn on

  // close all leds
  for (int i = 0; i < LedNum; i++) {
    digitalWrite(pinLed[i], LOW); // Turn off the leds
  }

  // according the temperture's value to light on Leds
  if (temp >= 0 && temp <= 10) { //If temperature is between 0 - 10 degree
    LedOn = 1; // One led needs to be turned on
  } else if (temp >= 11 && temp <= 20) { //If temperature is between 11 - 20 degree
    LedOn = 2;// Two leds need to be turned on
  } else if (temp >= 21 && temp <= 30) { //If temperature is between 21 - 30 degree
    LedOn = 3;// Three leds need to be turned on
  } else if (temp >= 31 && temp <= 40) { //If temperature is between 31 - 40 degree
    LedOn = 4;// Four leds need to be turned on
  } else if (temp >= 40 ) { //If temperature is greater than and equal 40 degree
    LedOn = 5;// Five leds need to be turned on
  }

  // Light on corresponing the Leda
  for (int i = 0; i < LedOn; i++) {
    digitalWrite(pinLed[i], HIGH); // Turn on the leds
  }
}
// Interrupt Service Routine for Timer1 Compare Match A.
  ISR(TIMER1_COMPA_vect){
  int  temperture = readTemperture(); // Read the current temperature.
  readTemAndLedOn(temperture);  // Update the LEDs based on the temperature.
}

