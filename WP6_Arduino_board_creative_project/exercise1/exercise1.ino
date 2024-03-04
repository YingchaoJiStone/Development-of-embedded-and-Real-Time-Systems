// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 6
// Exercise 1
// Submission code: 145637

#define ENCA 2   //define the pin for ENCA
#define ENCB 3    //define the pin for ENCB
#define PWM1 5    //define the pin for  PWM1
#define PWM2 6    //define the pin for   PWM2

//initiaize varaibles for the encoder postion and motor control

int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

// controller parmeters
int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {
 
  Serial.begin(9600); // start serila communication
 
  pinMode(ENCA,INPUT_PULLUP);  //set ENCA as input with pull-up resistors
  pinMode(ENCB,INPUT_PULLUP);  //set ENCB  as input with pull-up resistors
  
  pinMode(PWM1,OUTPUT);  //set PWM1 pins as output
  pinMode(PWM2,OUTPUT);  //set PWM2 pins as output
  // Attach an interrupt to ENCA pin to read encoder position on state change
  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);
  
 // start the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM2, 10);  // read pwm2
  delay(1000); // TinkerCad...bug
  analogWrite(PWM1, 10);  // read pwm1
}

void loop() {
  
  
  // Check if motor rotated all the way around, and reset counter
    if (pos > 2299  ){   // if pos is great 2299
      pos = 0;  // pos equal 0
    }
    
  if(pos <-2299){  // if pos is less than -2299
  pos = 0;          // pos equal 0
  }
  if(deg>359 || deg <-359){   //reset degree count after a full rotation
  deg = 0;        // degree  equal 0
  }
  
  // Print current position
  Serial.print("The current position is: ");
  Serial.print(deg);  // output degree
  Serial.print("\n");
   
  // Get input 
  degtarget = getInput()+deg;
  
  // Calculate initial error
  e = degtarget - deg;
    
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    deg = map(pos,0,2299,0,360);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;    // speed will equal 100
      analogWrite(PWM2, 0);    // read PWM2 as 0
      analogWrite(PWM1, speed);  // read PWM1  with speed
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100;    // speed equal -100
      analogWrite(PWM1, 0);  //  read pwm1 as 0
      analogWrite(PWM2, -speed);   //read pwm2 as -speed
    }
	
    // Calculate new error
  	e = degtarget - deg;
  }
  
   if (e == 0) { // if error is 0
    //stop the motor from continously rotating
  	analogWrite(PWM1, 10);
    delay(200);
    analogWrite(PWM2, 10);	
  }

}

int getInput(){  // Function to read target position from serial input
  
  int ready = 0;  // flag to check if input is ready
  char buf[4];   // buffer to store input characters
  int input = -1;  // vaiable to store the converted input value
  
  Serial.print("Please enter the desired position(Degree): \n");
  
  while(!ready){  // loop until input is received
    ready = Serial.readBytes(buf,4);  // read up to 4 bytes from serila input into buffer
    input = atoi(&buf[0]);   // convert the input string to an integer
  }
 	Serial.println(input);  // print out the input
  return input;   // return input
}  
// Function to calculate the action (motor speed) based on the error between target and current position.
int getAction(int error){

  u_out = kp * error;  // Calculate controller output
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;    // return the value
  }
  else if (u_out < -254){ //...or less than -254
    return -255;    // return the value
  }  
  else
     return u_out;   // return the value
}
// Interrupt Service Routine to read the encoder signals and update position
void ISR_readEncoder(){
  int a = digitalRead(ENCA);  // Read the current state of encoder pin a
  int b = digitalRead(ENCB);   // Read the current state of encoder pin b
  if (a > b) {    // if a sihnals is great b
    pos++; //  increment this direction  CW
  } else {
    pos--; // decrement  this direction  CCW
  }
  
}