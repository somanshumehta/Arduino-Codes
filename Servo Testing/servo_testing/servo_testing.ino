#include <Servo.h> 

Servo myservo;

void setup() 
{ 
  myservo.attach(5);
  myservo.write(0);  // set servo to mid-point
} 

void loop() {} 
