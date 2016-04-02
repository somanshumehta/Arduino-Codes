/*
  matrix size is 7x5 row=7,column=5 
 Sequence LEDs starting from first column and row until all LEDS are lit
 Multiplexing is used to control 64 LEDs with 16 pins
 When the column pin goes low and a row pin goes high, the corresponding LED will light.
 */
const int columnPins[] = { 2, 3, 4, 5, 6, 7,8};    //arduino pins into LED matrix column
const int rowPins[]   = { 9,10,11,12,13};          //arduino pins into LED matrix rows
int pixel       = 0;        // 0 to 35 LEDs in the matrix
int columnLevel = 0;        // pixel value converted into LED column
int rowLevel    = 0;        // pixel value converted into LED row
void setup() {
  for (int i = 0; i < 7; i++)
  {
    pinMode(columnPins[i], OUTPUT);  // make all the LED pins outputs
    pinMode(rowPins[i], OUTPUT);
  }
}
void loop() {
  pixel = pixel + 1;
  if(pixel > 35)
     pixel = 0;                                // reset the pixel counter
  columnLevel = pixel / 5;                     // map to the number of columns
  rowLevel = pixel % 5;                        // get the fractional value
  for (int column = 0; column < 5; column++)
  {
    digitalWrite(columnPins[column], LOW);     // connect this column to Ground
    for(int row = 0; row < 7; row++)
    {
      if (columnLevel > column)
      {
        digitalWrite(rowPins[row], HIGH);  // connect all LEDs in row to +5 volts
      }
      else if (columnLevel == column && rowLevel >= row)
            {
          digitalWrite(rowPins[row], HIGH);
      }
      else
      {
        digitalWrite(columnPins[column], LOW); // turn off all LEDs in this row
      }
      delayMicroseconds(300);     // delay gives frame time of 20ms for 64 LEDs
      digitalWrite(rowPins[row], LOW);         // turn off LED
    }
    digitalWrite(columnPins[column], HIGH);   // disconnect this column from Ground

  }
}
