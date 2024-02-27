// (C) Jessie Johnsson, Yingchao Ji, group: 10 (2024)
// Work package 6
// Exercise 1
// Submission code: 145637

#define ENCA 2
#define ENCB 3
#define PWM1 5
#define PWM2 6
 
int pos = 0; // Position in ticks
int deg = 0; // Position in degrees

int degtarget = 0; // Target position in degrees

int speed = 0; // Desired motor speed

int kp = 5; // Proportional constant for controller (tuning parameter)
int u_out = 0; // output of controller

int e = 0; // error
int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {
 
  Serial.begin(9600);
  pinMode(ENCA,INPUT_PULLUP);
  pinMode(ENCB,INPUT_PULLUP);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);  
  
  /*
  ==> TO DO TO DO TO DO
  ATTACH INTERRUPT HERE.
  */
  attachInterrupt(digitalPinToInterrupt(ENCA), ISR_readEncoder, RISING);
  //attachInterrupt(digitalPinToInterrupt(ENCB), ISR_readEncoder, CHANGE);

}

void loop() {
  // Stop the motor, but not to zero because then TinkerCad dies....
  analogWrite(PWM1, 10);
  delay(1000); // TinkerCad...bug
  analogWrite(PWM2, 10);
  
  // Check if motor rotated all the way around, and reset counter
    if (pos > 2299){
      pos = 0;
    }
    if (pos < 0){
  	  pos = 0;
    }
  
  if(deg>359){
  deg=0;
  }
  
  // Print current position
  Serial.print("The current position is: ");
  Serial.print(deg);
  Serial.print("\n");
   
  // Get input 
  degtarget = getInput()+deg;
  
  // Calculate initial error
  e = degtarget - deg;
    
  // Loop until error is zero
  while(e){
    
    // Map current position into degrees
    deg = map(pos,0,2299,0,359);
       
  	// Get necessary speed signal
  	speed = getAction(e);
    
  	// Send speed signal to motor
    // Rotating clockwise
    if(speed >= 0){
    	if (speed < 100) // motor does not react with too low inputs
      	speed = 100;
      analogWrite(PWM2, 0);
      analogWrite(PWM1, speed);
  	}
  
    // Rotating counter-clockwise
  	else{
    	if (-speed < 100) // motor does not react with too low inputs
      	speed = -100; 
      analogWrite(PWM1, 0);
      analogWrite(PWM2, -speed); 
    }
	
    // Calculate new error
  	e = degtarget - deg;
  }
}

int getInput(){
  
  int ready = 0;
  char buf[4];
  int input = -1;
  
  Serial.print("Please enter the desired position(Degree): \n");
  
  while(!ready){
    ready = Serial.readBytes(buf,4);
    input = atoi(&buf[0]);
  }
 	Serial.println(input);
  return input;
}  

int getAction(int error){
  /*
  ==> TO DO TO DO TO DO
  Calculate u_out as function of the error and the kp (tuning parameter).
  */
  u_out = kp * error;
  if (u_out > 254){ //u_out cannot be more than 255...
  	return 255;
  }
  else if (u_out < -254){ //...or less than -254
    return -255;
  }  
  else
     return u_out;
}

void ISR_readEncoder(){
  int a = digitalRead(ENCA);
  int b = digitalRead(ENCB);
  if (a > b) {
    pos++; // Assuming this direction is CW
  } else {
    pos--; // Assuming this direction is CCW
  }
  //Serial.print("Encoder position: "); 
 // Serial.println(pos); 
}
  /*
  ==> TO DO TO DO TO DO
  READ THE ENCODER SIGNAL HERE.
  Read the encoder signals and increase or decrease pos accordingly.
  */
