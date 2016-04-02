



/*
* Source: http://www.arduino.cc/playground/Main/DirectDriveLEDMatrix
*
* Modifications for 5x7 LED Matrix element
* by Stefan Wolfrum in July 2012.
* ----------------------------------------
*
* Show messages on an 5x7 led matrix,
* scrolling from right to left.
*
* Uses FrequencyTimer2 library to
* constantly run an interrupt routine
* at a specified frequency. This
* refreshes the display without the
* main loop having to do anything.
*
*/
 
#include <FrequencyTimer2.h>
#define SPACE { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0} \
}
 
#define H { \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 1, 1, 1, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1} \
}
 
#define E { \
{1, 1, 1, 1, 1}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 1, 1, 1, 0}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 1, 1, 1, 1} \
}
 
#define small_E { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 1, 1, 1, 1}, \
{1, 0, 0, 0, 1}, \
{1, 1, 1, 1, 1}, \
{1, 0, 0, 0, 0}, \
{0, 1, 1, 1, 1} \
}
 
#define L { \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 0, 0, 0, 0}, \
{1, 1, 1, 1, 1} \
}
 
#define small_L { \
{0, 1, 1, 0, 0}, \
{0, 0, 1, 0, 0}, \
{0, 0, 1, 0, 0}, \
{0, 0, 1, 0, 0}, \
{0, 0, 1, 0, 0}, \
{0, 0, 1, 0, 0}, \
{0, 0, 1, 1, 0} \
}
 
#define O { \
{0, 1, 1, 1, 0}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{0, 1, 1, 1, 0} \
}
 
#define small_O { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 1, 1, 1, 0}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{0, 1, 1, 1, 0} \
}
 
#define small_W { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{1, 0, 0, 0, 1}, \
{1, 0, 0, 0, 1}, \
{1, 0, 1, 0, 1}, \
{1, 0, 1, 0, 1}, \
{0, 1, 0, 1, 0} \
}
 
#define small_R { \
{0, 0, 0, 0, 0}, \
{0, 0, 0, 0, 0}, \
{0, 0, 1, 1, 1}, \
{0, 1, 0, 0, 0}, \
{0, 1, 0, 0, 0}, \
{0, 1, 0, 0, 0}, \
{0, 1, 0, 0, 0} \
}
 
#define small_D { \
{0, 0, 0, 0, 1}, \
{0, 0, 0, 0, 1}, \
{0, 0, 0, 0, 1}, \
{0, 1, 1, 1, 1}, \
{0, 1, 0, 0, 1}, \
{0, 1, 0, 0, 1}, \
{0, 1, 1, 1, 1} \
}
byte col = 0;
byte leds[5][7]; // columns x rows
 
// pin[xx] on led matrix connected to pins on Arduino
// (-1 is dummy to make array start at pos 1)
int pins[13]= {-1, 2, 9, 3, 11, 12, 13, 5, 6, 10, 4, 8, 7};
 
// col[xx] of leds = pin yy on led matrix
int cols[5] = {pins[13], pins[3], pins[4], pins[10], pins[6]};
 
// row[yy] of leds = pin yy on led matrix
int rows[7] = {pins[9], pins[14], pins[8], pins[12],
 pins[1], pins[7], pins[2]};
 
const int numPatterns = 12;
byte patterns[numPatterns][7][5] = {
 SPACE, H, 
 //small_E, small_L, small_L, small_O,
 //SPACE, small_W, small_O, small_R, small_L, small_D
};
 
int pattern = 0;
 
void setup()
{
  // sets the pins as output
  for (int i = 1; i <= 12; i++) {
    pinMode(pins[i], OUTPUT);
  }
 
  // set up cols and rows
  for (int i = 1; i <= 5; i++) {
    digitalWrite(cols[i - 1], LOW);
  }
 
  for (int i = 1; i <= 7; i++) {
    digitalWrite(rows[i - 1], LOW);
  }
 
  clearLeds();
 
  // Turn off toggling of pin 11
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(3000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);
 
  setPattern(pattern);
}
 
void loop()
{
  pattern = ++pattern % numPatterns;
  slidePattern(pattern, 1000);
}
 
void clearLeds()
{
  // Clear display array
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      leds[i][j] = 0;
    }
  }
}
 
void setPattern(int pattern)
{
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 7; j++) {
      leds[i][j] = patterns[pattern][j][i];
    }
  }
}
 
void slidePattern(int pattern, int del)
{                                                                                                     
  for (int newcol = 0; newcol <= 4; newcol++) {
 
    // shift the first 4 columns left
    for (int row = 0; row <= 6; row++)
      for (int col = 0; col <= 3; col++)
        leds[col][row] = leds[col+1][row];
 
    // fill the last (5th) column with the
    // 1st (2nd, 3rd, ...) column of the new pattern
    for (int row = 0; row <= 6; row++)
      leds[4][row] = patterns[pattern][row][newcol];
 
    delay(del);
  }
}
 
// Interrupt routine
void display()
{
  // Turn whole previous column off:
  digitalWrite(cols[col], LOW);
  col++;
  if (col == 5) {
    col = 0;
  }
  for (int row = 0; row < 7; row++) {
    if (leds[col][row] == 1) {
      digitalWrite(rows[row], LOW); // Turn on this led
    }
    else {
      digitalWrite(rows[row], HIGH); // Turn off this led
    }
  }
  // Turn whole column on at once (for equal lighting times):
  digitalWrite(cols[col], HIGH);
}



