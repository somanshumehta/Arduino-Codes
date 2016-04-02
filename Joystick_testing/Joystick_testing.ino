/*Wire Colors 
Red     +5V
Black   GND
Blue    x dirn
Green   y dirn
Yellow  switch

*/



int value = 0;

void setup() 
  {
  pinMode(2, INPUT);
  Serial.begin(9600);
  }

void loop() {
  value = analogRead(0);   // blue wire from joystick to A0-x dirn
  Serial.print("X:");
  //value=map(value, 0, 1024, 0, 10); 
  Serial.print(value, DEC);

  value = analogRead(1);   // green wire from joystick to A1-y dirn
  Serial.print(" | Y:");
  //value=map(value, 0, 1024, 0, 10);
  Serial.print(value, DEC);

  value = digitalRead(2);  //// yellow wire from joystick to digital pin 7
  Serial.print(" | Z: ");
  Serial.println(value, DEC);
  delay(100);
}
//map(value, fromLow, fromHigh, toLow, toHigh)
