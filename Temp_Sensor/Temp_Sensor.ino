/*
  AnalogReadSerial
 Reads an analog input on pin 0, prints the result to the serial monitor 
 
 This example code is in the public domain.
 */
float temp;
void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  temp = (5.0 * analogRead(A0) * 100.0) / 1024;;
  Serial.println(temp);
}

/*---------LM635 PINOUTS-------------
1-VCC +5V
2-OUTPUT
3-GND

The LM35 is a common TO-92 temperature sensor. It is often used 
with the equation

temp = (5.0 * analogRead(tempPin) * 100.0) / 1024;


*/
