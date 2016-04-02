// Project 7 - Pulsating lamp  
int ledPin =11    ;  
int x;
  
void setup() {  
           
}  
  
void loop() {  
          for (int x=0; x<255; x++) 
          {  
          analogWrite(ledPin, x);  
          delay(10);  
          }  
}  
