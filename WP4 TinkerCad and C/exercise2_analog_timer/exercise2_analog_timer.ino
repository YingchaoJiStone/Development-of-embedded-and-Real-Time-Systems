// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 4
// Exercise 2
// Submission code: 797534 

#include <Servo.h>   // inculde the lib to control servo motors

Servo servo_9;  // create  a servo object to control servo on pin
volatile int seconds = 0; // declear a volatile int 'seconds' to store the seconds passed

void setupTimer2() {
  cli(); // disable global interrupts to ensure no interrupt occurs during timer setup

  TCCR2A = (1 << WGM21); // configure timer2 for CTC mode
  TCCR2B = (1 << CS22) | (1 << CS21); // set prescaler for timer2 to 1024(64+8 = 1024)
  OCR2A = 156; // set compare match register to 156, timer will cleat on this count
  TIMSK2 |= (1 << OCIE2A); // enable timer2 compare matchA interrupt

  sei(); // enable global interrupt after setting up the  timer
}

ISR(TIMER2_COMPA_vect) {
  static unsigned long tickCounter = 62500 / (OCR2A + 1); // Initialize tickCounter to the interval value
  
  tickCounter--; // Decrement the tickCounter at each interrupt

  if (tickCounter == 0) {
    tickCounter = 62500 / (OCR2A + 1); // Reset tickCounter to the interval value
    
    seconds = (seconds + 1) % 60;  // increment seconds and wrap around every 60
    Serial.println(seconds);   // Print the number of seconds to the serial monitor.
    int angle = map(seconds, 0, 59, 0, 180);  // map the seconds to angle between 0 and 180 degrees
    servo_9.write(angle);  // Set the servo to the corresponding angle.
  }
}

void setup() {
  servo_9.attach(9);  // attach the servo motor to pin 9
  servo_9.write(0);  // initialize the servo to 0 degrees
  Serial.begin(9600); // strat serial communcatiation at 9600
  setupTimer2(); //  call the function for generating interrupts
}

void loop() {
 // the main loop does nothing for this program
}
