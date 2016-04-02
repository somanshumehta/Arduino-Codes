


//     Function 			Channel A(left) 	Channel B(right)
//     Direction 			Digital 12 	        Digital 13
//     Brake 	                        Digital 9 	        Digital 8
//     Speed (PWM) 			Digital 3 	        Digital 11
//     Current Sensing 		        Analog 0 	        Analog 1


// Here is code for controlling two motors ***////

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT);  // Establishes forward/reverse direction of Channel A
  pinMode(9, OUTPUT);  //  Engage/Disengage the Brake for Channel A
  pinMode(3, OUTPUT);  //  speed control
  
  //Setup Channel B
  pinMode(13, OUTPUT); // Establishes forward/reverse direction of Channel B
  pinMode(8, OUTPUT);  // Engage/Disengage the Brake for Channel B
  pinMode(11, OUTPUT); // speed control
  
  Serial.begin(9600);
}

void loop()
{

 
  
  //Motor A 
   digitalWrite(12, HIGH); //Establishes forward direction of Channel A
   digitalWrite(9, LOW);   //Disengage the Brake for Channel A
   analogWrite(3,255);   //Spins the motor on Channel A at required (0-255) speed

   //Motor B 
   digitalWrite(13, HIGH);  //Establishes forward direction of Channel B
   digitalWrite(8, LOW);   //Disengage the Brake for Channel B
   analogWrite(11,255);    //Spins the motor on Channel A at required (0-255) speed   

  
  
 // serial.available() removed-not working   
}


