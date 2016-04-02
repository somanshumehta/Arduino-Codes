/*
Curent sensing with the Arduino Motor Shield: http://arduino.cc/it/Main/ArduinoMotorShieldR3
  
 One small DC motor attached to screw terminal block A
 External power from a 4 x AA batter pack
  
 CC-BY-SA
 by Dustyn Roberts
 6/12/2012
 */
 
// declare pins used on channel A
int directionPin = 12;
int pwmPin = 3;
int brakePin = 9;
int currentPin = A0;
 
int switchPin = 2; // motor on/off switch
// connect one side of switch to power, the other to ground through a 10k resistor
// read the switch state where the switch and resistor meet into digital pin 2
// similar to this lab: http://itp.nyu.edu/physcomp/Labs/DigitalInOut
// If you turn the motors the current produced by the back emf is too less to be measured 
// constants
float volt_per_amp = 1.65; // resolution according to hardware page
 
// variables
float currentRaw; // the raw analogRead ranging from 0-1023
float currentVolts; // raw reading changed to Volts
float currentAmps; // Voltage reading changed to Amps
 
void setup() {
  pinMode(directionPin, OUTPUT);
  pinMode(pwmPin, OUTPUT); // necessary according to forum post http://arduino.cc/forum/index.php/topic,89468.0.html
  Serial.begin(9600); 
}
 
void loop() {
  // read the switch input:
  if (digitalRead(switchPin) == HIGH) {
    // if the switch is closed:
    digitalWrite(pwmPin, HIGH); // necessary according to forum post http://arduino.cc/forum/index.php/topic,89468.0.html
    digitalWrite(directionPin, HIGH);
  }
  else {
    // if the switch is open:
    digitalWrite(pwmPin, LOW); // necessary according to forum post http://arduino.cc/forum/index.php/topic,89468.0.html
    digitalWrite(directionPin, LOW);
  }
 
  currentRaw = analogRead(currentPin);
  currentVolts = currentRaw *(5.0/1024.0);
  currentAmps = currentVolts/volt_per_amp;
 
  Serial.println(currentAmps);
}
