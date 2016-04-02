/*
 HC-SR04 Ultasonic distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 4
 
 Micro Servo Motor
 Red     Vcc
 Black   Gnd
 Blue    signal, Arduino pin 5
 
 Motor Pins used via motor shield
 Left  Ch Arduino pin - 12,9,3
 Right Ch Arduino pin - 13,8,11
 
 */

#include <Servo.h>   
#define echoPin 7   // Echo Pin
#define trigPin 4   // Trigger Pin
#define LEDPin 13   // Onboard LED
 
Servo myservo;  // create servo object to control a servo 
                
int pos ;                 // variable to store the servo position 
int maximumRange = 15;   // Maximum range needed i cms
int minimumRange = 0;    // Minimum range needed
long duration ;          // Duration used to calculate distance
long distance ;
long distance_left ;
long distance_right ;
 
void setup() 
{ 
 myservo.attach(5);  // attaches the servo on pin 9 to the servo object 
 
  pinMode(4, OUTPUT);    //trigPin
  pinMode(7, INPUT);     //echoPin
  pinMode(12, OUTPUT);   // Dirn pin for Ch A
  pinMode(9, OUTPUT);    // Brake pin for Ch A
  pinMode(3, OUTPUT);    // speed control
  pinMode(13, OUTPUT);   // Dirn pin for Ch B
  pinMode(8, OUTPUT);    // Brake pin for Ch B
  pinMode(11, OUTPUT);   // speed control
 
} 
 
void loop() 


{ 
  myservo.write(90); 
  for(pos = 90; pos < 120; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                   // in steps of 1 degree 
    myservo.write(pos);               // tell servo to go to position in variable 'pos' 
    distance = distance_right ;
    delay(15);                        // waits 15ms for the servo to reach the position 
  } 
  for(pos = 120; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    distance = distance_left  ;
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  if( distance_right > distance_left)
  {
    //Left Motor
  }
  
  else
  {
      //Right Motor
  
  
  }
  
} 


void calc_distance()
{
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 distance = duration/58.2;    //Calculate the distance (in cm) based on the speed of sound.
  
} 
