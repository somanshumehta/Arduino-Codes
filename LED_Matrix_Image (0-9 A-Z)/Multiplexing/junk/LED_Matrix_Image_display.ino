
// the images are stored as bitmaps - each bit corresponds to an LED
// a 0 indicates the LED is off, 1 is on
// When the column pin goes low and a row pin goes high, the corresponding LED will light.
byte on[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111 };
byte off[] = {
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 ,
  B00000 };
const int columnPins[] = {  2,3,4,5,6};
const int rowPins[]    = { 7,8,9,10,11,12,13 };
void setup() 
{
  for (int i = 0; i < 5; i++)
  { pinMode(rowPins[i], OUTPUT); }  // make all the LED pins outputs
  for (int j = 0; j < 7; j++) 
    {pinMode(columnPins[j], OUTPUT);     // make all the LED pins outputs
    digitalWrite(columnPins[j], HIGH); } // disconnect column pins from Ground
 }

void loop() {
  int pulseDelay = 800 ;          // milliseconds to wait between beats
  show(on, 80);           // show the small heart image for 100 ms
  show(off, 160);            // followed by the big heart for 200ms
  delay(pulseDelay);              // show nothing between beats
}
// routine to show a frame of an image stored in the array pointed to by the
//image parameter.
// the frame is repeated for the given duration in milliseconds
void show( byte * image, unsigned long duration)
{
 unsigned long start = millis();            // begin timing the animation
 while (start + duration > millis())        // loop until the duration period
//has passed
  {
    for(int row = 0; row < 7; row++)
    {
      digitalWrite(rowPins[row], HIGH);          // connect row to +5 volts
      for(int column = 0; column < 5; column++)
      {
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1)
        {
         digitalWrite(columnPins[column], LOW);  // connect column to Gnd
         delayMicroseconds(300);                    // a small delay for each LED
         digitalWrite(columnPins[column], HIGH);    // disconnect LEDs
        }
        if(pixel ==0)
        {digitalWrite(rowPins[row], LOW); }  // disconnect column from Gnd 
      }
      
    }
  }
}
