int ledPin =  11    ;

void setup() {  
          pinMode(ledPin, OUTPUT);  
}  
  
void loop() {  
  
digitalWrite(11,HIGH);
delay(50);
digitalWrite(11,LOW);
delay(50);
digitalWrite(11,HIGH);
delay(50);
digitalWrite(11,LOW);
delay(1000);
}
