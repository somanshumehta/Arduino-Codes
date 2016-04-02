//     Function 			Channel A 	Channel B
//     Direction 			Digital 12 	Digital 13
//     Speed (PWM) 			Digital 3 	Digital 11
//     Brake 	                        Digital 9 	Digital 8
//     Current Sensing 		        Analog 0 	Analog 1
////****Do not connect any sensors at A0 and A1 as they are reserved for current sensing****// 

// Here is code for controlling two motors ***////

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(3, OUTPUT);
  
  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  pinMode(11, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{

  //if(Serial.available() ) 
  // {
   //Motor A 
   digitalWrite(12, HIGH); //Establishes forward direction of Channel A
   digitalWrite(9, LOW);   //Disengage the Brake for Channel A
   analogWrite(3,255 );   //Spins the motor on Channel A at required (0-255) speed
   analogRead(A0);      //Current sensing for channel A
   //Motor B 
   digitalWrite(13, HIGH);  //Establishes forward direction of Channel B
   digitalWrite(8, LOW);   //Disengage the Brake for Channel B
   analogWrite(11,255 );    //Spins the motor on Channel A at required (0-255) speed
   analogRead(A1);      //Current sensing for channel B
   digitalWrite(7,HIGH);
  
  
  // } 
}

//Serial.read()
