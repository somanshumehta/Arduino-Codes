
void setup() {
#if defined(USBCON)
  ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#else
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
#endif
  delay(2); // Wait for Vref to settle
  Serial.begin(9600);
}
 
uint16_t min_reading=1023;
uint16_t max_reading=0;
uint16_t reading;
 
void loop() {
   if (millis() % 1000) {
      ADCSRA |= _BV(ADSC); // start convertion
      loop_until_bit_is_clear(ADCSRA,ADSC);
      reading  = ADCL;
      reading |= ADCH<<8;     
      min_reading = min(min_reading, reading);
      max_reading = max(max_reading, reading);
   } else {
      Serial.print  ("Vref noise: ");
      Serial.print  ((max_reading - min_reading) * 4.88);
      Serial.println(" mV");
      min_reading=1023;
      max_reading=0;
      delay(1);
   }  
}
