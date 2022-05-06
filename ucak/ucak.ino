#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;
LiquidCrystal lcd(11,10,4,5,6,7);

int xpozisyon=A0;
int ypozisyon=A1;

byte sagkanat[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b01111,
  0b00000,
  0b00000,
  0b00000
};

byte sagkanatalt[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00011,
  0b00110,
  0b01100,
  0b11000
};

byte sagkanatust[8] = {
  0b11000,
  0b01100,
  0b00110,
  0b00011,
  0b00001,
  0b00000,
  0b00000,
  0b00000
};

byte solkanat[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11110,
  0b00000,
  0b00000,
  0b00000
};

byte solkanatalt[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b01100,
  0b00110,
  0b00011
};


byte solkanatust[8] = {
  0b00011,
  0b00110,
  0b01100,
  0b11000,
  0b10000,
  0b00000,
  0b00000,
  0b00000
};

byte sabitust[8] = {
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11001,
  0b10011
  
};

byte sabitalt[8] = {
  0b10011,
  0b11001,
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000
};

byte ust[8] = {
  0b11001,
  0b10011,
  0b11011,
  0b10001,
  0b11000,
  0b10000,
  0b11000,
  0b10000
};

byte alt[8] = {
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10001,
  0b11011,
  0b10011,
  0b11001
};

byte bosust[8] = {
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000
};

byte bosalt[8] = {
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000,
  0b10000,
  0b11000
};


void setup() 
{
Serial.begin(9600);
motor.attach(13);

pinMode(xpozisyon,INPUT);
pinMode(ypozisyon,INPUT);
lcd.begin(16,2);

lcd.createChar(0, sagkanat);
lcd.createChar(1, sagkanatust);
lcd.createChar(2, sagkanatalt);
lcd.createChar(3, solkanat);
lcd.createChar(4, solkanatust);
lcd.createChar(5, solkanatalt);
lcd.createChar(6, sabitust);
lcd.createChar(7, sabitalt);
lcd.createChar(8, ust);  //sınır
lcd.createChar(9, alt);
lcd.createChar(10, bosust);
lcd.createChar(11, bosalt);
}

void loop() 
{
 int xyon=analogRead(xpozisyon);
 int yyon=analogRead(ypozisyon);

 if(xyon<400)
   {
    motor.write(110);
    delay(15);
    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.write(byte(2));
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(8,0);
    lcd.write(byte(4));
    lcd.setCursor(9,0);
    lcd.print(")");
    delay(500);
    }
    

    if(xyon>600)
   {
    motor.write(90);
    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.write(byte(1));
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(8,0);
    lcd.write(byte(5));
    lcd.setCursor(9,0);
    lcd.print(")");
    delay(500);
    }
    else
    {
    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.write(byte(0));
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(7,0);
    lcd.setCursor(8,0);
    lcd.write(byte(3));
    lcd.setCursor(9,0);
    lcd.print(")");
    }

    if(yyon<400)
      {
        lcd.setCursor(0,0);
        lcd.write(byte(12));
        lcd.setCursor(0,1);
        lcd.write(byte(11));
        delay(500);
      }

      if(yyon>600)
      {
        lcd.setCursor(0,0);
        lcd.write(byte(10));
        lcd.setCursor(0,1);
        lcd.write(byte(9));
        delay(500);
      }
      else
      {
         lcd.setCursor(0,0);
         lcd.write(byte(6));
         lcd.setCursor(0,1);
         lcd.write(byte(10));
      }
    
  
}
