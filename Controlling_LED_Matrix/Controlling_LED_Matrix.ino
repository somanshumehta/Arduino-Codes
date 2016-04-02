/*
  matrixMpx sketch
 Sequence LEDs starting from first column and row until all LEDS are lit
 Multiplexing is used to control 64 LEDs with 16 pins
 When the column pin goes low and a row pin goes high, the corresponding LED will light.
 */
const int columnPins[] = { 13,3,4,11,10,6};
const int rowPins[]   = { 9,14,8,12,5,1,7,2};
int column  ;
int row  ;
void setup() 
  {
      //column pins
    pinMode(13,OUTPUT);  
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);  
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);  
    pinMode(6,OUTPUT);
      //row pins
    pinMode(9,OUTPUT);  
    pinMode(14,OUTPUT);
    pinMode(8,OUTPUT);  
    pinMode(12,OUTPUT);
    pinMode(5,OUTPUT);  
    pinMode(1,OUTPUT);
    pinMode(7, OUTPUT);  
    pinMode(2, OUTPUT);
    
  }
void loop() 
{
  
  for (column = 0; column < 6; column++)
    { 
      digitalWrite(columnPins[column], LOW);     // connect this column to Ground 
      
        for(row = 0; row < 8; row++)
          { digitalWrite(rowPins[row], HIGH);  }  // connect all LEDs in row to +5 volts
    }
} 

   

  
