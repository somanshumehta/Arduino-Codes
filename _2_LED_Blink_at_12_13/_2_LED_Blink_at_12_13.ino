void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(12, OUTPUT); 
  pinMode(13, OUTPUT);  
}

void loop() {
  digitalWrite(13, HIGH);   // set the LED on
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // set the LED off
  delay(500);              // wait for a second
  digitalWrite(12, HIGH);   // set the LED on
  delay(500);              // wait for a second
  digitalWrite(12, LOW);    // set the LED off



}
