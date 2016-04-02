#include <Servo.h>


Servo myservo;
int pos =0;
int  serialVal;
void setup()
{ myservo.attach(9);
  Serial.begin(9600);
}

void loop()
{
if(Serial.available())
 serialVal=Serial.read();
myservo.write(serialVal);
}



