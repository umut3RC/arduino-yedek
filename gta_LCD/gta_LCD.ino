#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 13, d5 = 12, d6 = 11, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte sabit[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b11111,
  0b11111,
  0b01010,
  0b01010
};

byte ilkadim[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b11111,
  0b11111,
  0b01010,
  0b00010
};

byte sonadim[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b11111,
  0b11111,
  0b01010,
  0b01000
};

byte sag[8] = {
  0b00000,
  0b00000,
  0b01100,
  0b01100,
  0b01000,
  0b01100,
  0b01000,
  0b01000
};

  byte sagileri[8] = {
  0b00000,
  0b00000,
  0b01100,
  0b01100,
  0b01000,
  0b01100,
  0b01000,
  0b10100
};

byte sol[8] = {
  0b00000,
  0b00000,
  0b00110,
  0b00110,
  0b00010,
  0b00110,
  0b00010,
  0b00010
};

byte solileri[8] = {
  0b00000,
  0b00000,
  0b00110,
  0b00110,
  0b00010,
  0b00110,
  0b00010,
  0b00101
};

int xpozisyon=A0;
int ypozisyon=A1;

int xyon=0;
int yyon=0;

void setup() 
{
  lcd.begin(16, 2);
  lcd.createChar(0, sabit);
  lcd.createChar(1, ilkadim);
  lcd.createChar(2, sonadim);
  lcd.createChar(3, sag);
  lcd.createChar(4, sol);
  lcd.createChar(5, sagileri);
  lcd.createChar(6, solileri);

  pinMode(xpozisyon,INPUT);
  pinMode(ypozisyon,INPUT);
}

void loop() 
{
  int xyon= analogRead(xpozisyon);
  int yyon= analogRead(ypozisyon);
  
  
  
  if(yyon>1000 || yyon>1000 && xyon>255 || yyon>1000 && xyon<255) //ileri
     {
      lcd.setCursor(5,0);
      lcd.write(byte(1)); 
      delay(500);
      lcd.clear();
      delay(10);
      lcd.setCursor(5,0);
      lcd.write((byte)2);
      delay(500);
      lcd.clear();
      delay(10);
     }
     else
     {
      lcd.setCursor(5,0);
  lcd.write(byte(0));  //sabit
     }

      if(yyon<250) //geri
           {
            lcd.setCursor(5,0);
            lcd.write(byte(1)); 
            delay(500);
            lcd.clear();
            delay(10);
            lcd.setCursor(5,0);
            lcd.write((byte)2);
            delay(500);
            lcd.clear();
            delay(10);
           }
           else
           {
            lcd.setCursor(5,0);
        lcd.write(byte(0));
            }

            if(xyon<450 && xyon>50) //sağ sabit
           {
            lcd.setCursor(5,0);
            lcd.write(byte(3)); 
            delay(500);
            lcd.clear();
            
           }
           else
           {
            lcd.setCursor(5,0);
        lcd.write(byte(0));
            }

          if(xyon<50)    // sağ ileri
           {
            lcd.setCursor(5,0);
            lcd.write(byte(5)); 
            delay(500);
            lcd.clear();
            delay(10);
            lcd.setCursor(5,0);
            lcd.write((byte)3);
            delay(500);
            lcd.clear();
            delay(10);
           }
           else
           {
            lcd.setCursor(5,0);
            lcd.write(byte(0));
            }

            if(xyon>600 && xyon<900) //sol sabit
           {
            lcd.setCursor(5,0);
            lcd.write(byte(4)); 
            delay(500);
            lcd.clear();
            
           }
           else
           {
            lcd.setCursor(5,0);
        lcd.write(byte(0));
            }

          if(xyon>900)   //sol ileri
           {
            lcd.setCursor(5,0);
            lcd.write(byte(6)); 
            delay(500);
            lcd.clear();
            delay(10);
            lcd.setCursor(5,0);
            lcd.write((byte)4);
            delay(500);
            lcd.clear();
            delay(10);
           }
           else
           {
            lcd.setCursor(5,0);
            lcd.write(byte(0));
            }    
  
}
