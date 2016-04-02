/*

 *
 * Digital Pin layout ARDUINO
 * =============================
 *  2     IRQ 0    - to TSL235R
 *
 * PIN 1 - GND
 * PIN 2 - VDD - 5V
 * PIN 3 - SIGNAL
 *
 */
//  Most Arduino boards have two external interrupts: numbers 0 (on digital pin 2) and 1 (on digital pin 3).
//  Arduino attachinterrupt Pin3 conflicts with PWM function for Arduino Motor Shield. A new Challenge!!!!!!!! 
volatile unsigned long cnt1 = 0;
volatile unsigned long cnt2 = 0;
unsigned long oldcnt1 = 0;
unsigned long oldcnt2 = 0;
unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long last1;
unsigned long last2;

void irq1()
{
  cnt1++;
}
void irq2()
{
  cnt2++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(115200);
  Serial.println("START");
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  attachInterrupt(0, irq1, RISING);
  attachInterrupt(1, irq1, RISING);
}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{
  if (millis() - last1 > 1000 && millis()-last2 > 1000)
  {
    last1 = millis();
    last1 = millis();
    t1 = cnt1;
    t2 = cnt2;
    unsigned long hz1 = t1 - oldcnt1;
    unsigned long hz2 = t2 - oldcnt2;
    Serial.print(hz1);
    Serial.print("\t");
    Serial.print(hz2);
    Serial.print("\n");
    //Serial.print((hz1+50)/100);  // +50 == rounding last digit
    //Serial.println(" mW/m2");
    //Serial.print((hz2+50)/100);  // +50 == rounding last digit
    oldcnt1 = t1;
    oldcnt2 = t2;
  }
}
// END OF FILE
