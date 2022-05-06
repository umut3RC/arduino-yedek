/*
  LiquidCrystal Library - Custom Characters

 Demonstrates how to add custom characters on an LCD  display.
 The LiquidCrystal library works with all LCD displays that are
 compatible with the  Hitachi HD44780 driver. There are many of
 them out there, and you can usually tell them by the 16-pin interface.

 This sketch prints "I <heart> Arduino!" and a little dancing man
 to the LCD.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K potentiometer:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 * 10K poterntiometer on pin A0

 created 21 Mar 2011
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 7 Nov 2016
 by Arturo Guadalupi

 Based on Adafruit's example at
 https://github.com/adafruit/SPI_VFD/blob/master/examples/createChar/createChar.pde

 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/LiquidCrystalCustomCharacter

 Also useful:
 http://icontexto.com/charactercreator/

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 13, d5 = 12, d6 = 11, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make some custom characters:
byte sagkanat[8] = {
  0b00000,
  0b00001,
  0b00011,
  0b00111,
  0b01111,
  0b11100,
  0b11000,
  0b10000
};

byte sagorta[8] = {
  0b11000,
  0b10010,
  0b10011,
  0b11111,
  0b11111,
  0b11011,
  0b01011,
  0b00001
};

byte solorta[8] = {
  0b00011,
  0b01001,
  0b11001,
  0b11111,
  0b11111,
  0b11011,
  0b11010,
  0b10000
};

byte solkanat[8] = {
  0b00000,
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b00111,
  0b00011,
  0b00001
};
void setup() {
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);

  // create a new character
  lcd.createChar(0, sagkanat);
  // create a new character
  lcd.createChar(1,sagorta);
  // create a new character
  lcd.createChar(2,solorta);
  // create a new character
lcd.createChar(3,solkanat);

  // set the cursor to the top left
  lcd.setCursor(5,0);

  // Print a message to the lcd.
 
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
 lcd.write(byte(1));
  lcd.write((byte)2);
  lcd.write(byte(3));

   lcd.setCursor(3,1);
   lcd.print("umut ERC");

}

void loop() {

  
  }
