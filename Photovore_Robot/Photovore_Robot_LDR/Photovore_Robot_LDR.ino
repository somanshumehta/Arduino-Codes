



int LeftVal;
int RightVal;
int looks;
int calibrate;

void setup()  //runs once when first switched on
{
  //Declare pins as outputs
      //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  pinMode(3, OUTPUT); // PWM for channel A
  
      //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  pinMode(11, OUTPUT); //// PWM for channel A
  
 Serial.begin(9600);
}

void loop()
{    
      LeftVal  = analogRead(A0);
      RightVal = analogRead(A1);
        calibration();
      
      if(LeftVal < calibrate && RightVal <calibrate)
 
                 { lookaround();
                  looks=looks +1;
                  serialreply(); } 
      else if  (LeftVal > calibrate )
           { 
         
            serialreply();
            motor(); 
            }           
      else if( RightVal > calibrate)
           { 
         
            serialreply();
            motor();
           }
      else if (LeftVal=RightVal )
            { serialreply();
             
              motor();
            }
                   
}                  
  
  
  
  
  
  
  
   
  void calibration()
      {  calibrate = (LeftVal + RightVal)/2 ; }
  void serialreply()
      {  Serial.print(calibrate); 
         Serial.print("\t");
         Serial.print(LeftVal);
         Serial.print("\t");         
         Serial.print(RightVal);
         Serial.print("\n"); 
          
      }
  void lookaround()
      {  //Motor A 
         digitalWrite(12, LOW); //Establishes backward direction 
         digitalWrite(9, LOW);   //Disengage the Brake 
         analogWrite(3,255 );   ////Spins the motor A
   
          //Motor B 
         digitalWrite(13, HIGH); //Establishes forward direction 
         digitalWrite(8, LOW);   //Disengage the Brake 
         analogWrite(11,255 );    //Spins the motor B
      }
   void motor()
      {
        //Motor A 
   digitalWrite(12, HIGH);//Establishes forward direction to moror
   digitalWrite(9, LOW);   //Disengage the Brake 
   analogWrite(3,LeftVal );   //Spins the motor A (0-255) speed
   
   //Motor B 
   digitalWrite(13, HIGH);//Establishes forward direction to moror 
   digitalWrite(8, LOW);   //Disengage the Brake 
   analogWrite(11,RightVal );   //Spins the motor A (0-255) speed
        
      }    
  


