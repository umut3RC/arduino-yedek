#include <LiquidCrystal.h>
#include <Servo.h>
Servo motor;
LiquidCrystal lcd(11,10,4,5,6,7);

int xpozisyon=A0;
int ypozisyon=A1;
int sw=3;

int ad1=22;
int ad2=23;
int ad3=24;
int ad4=25;

int veri;  

byte usttire[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
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

pinMode(sw,INPUT_PULLUP);  
pinMode(xpozisyon,INPUT);
pinMode(ypozisyon,INPUT);
lcd.begin(16,2);

pinMode(ad1,OUTPUT); 
pinMode(ad2,OUTPUT); 
pinMode(ad3,OUTPUT); 
pinMode(ad4,OUTPUT); 

lcd.createChar(0, usttire);
lcd.createChar(1, sabitust);
lcd.createChar(2, sabitalt);
lcd.createChar(3, ust);  
lcd.createChar(4, alt);
lcd.createChar(5, bosust);
lcd.createChar(6, bosalt);
lcd.setCursor(12,1);
lcd.print("km/s");
}

void loop() 
{
 int xyon=analogRead(xpozisyon);
 int yyon=analogRead(ypozisyon);
 int btn= digitalRead(sw);


 
 if(xyon<400)
   {

    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.print("_");
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(8,0);
    lcd.write(byte(0));
    lcd.setCursor(9,0);
    lcd.print(")");
   
   }
  

   if(xyon<400)
     {
      
    digitalWrite(ad1,HIGH);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,LOW);
      delay(5);
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,HIGH);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,LOW);
      delay(5);
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,HIGH);
      digitalWrite(ad4,LOW);
      delay(5);
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,HIGH);
      delay(5);
    
     }
 else
   {
    digitalWrite(ad1,LOW);
    digitalWrite(ad2,LOW);
    digitalWrite(ad3,LOW);
    digitalWrite(ad4,LOW);
   }
     
   if(xyon>600)
   {
    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.write(byte(0));
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(8,0);
    lcd.print("_");
    lcd.setCursor(9,0);
    lcd.print(")");
    
    }
    else
    {
    lcd.setCursor(5,0);
    lcd.print("(");
    lcd.setCursor(6,0);
    lcd.print("-");
    lcd.setCursor(7,0);
    lcd.print("o");
    lcd.setCursor(7,0);
    lcd.setCursor(8,0);
    lcd.print("-");
    lcd.setCursor(9,0);
    lcd.print(")");
    }

    if(xyon>600)
      {
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,HIGH);
      delay(5);
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,HIGH);
      digitalWrite(ad4,LOW);
      delay(5);
      digitalWrite(ad1,LOW);
      digitalWrite(ad2,HIGH);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,LOW);
      delay(5);
      digitalWrite(ad1,HIGH);
      digitalWrite(ad2,LOW);
      digitalWrite(ad3,LOW);
      digitalWrite(ad4,LOW);
      delay(5);
      }
     
  if(yyon<400)
      {
        motor.write(150);
        delay(15);
        lcd.setCursor(0,0);
        lcd.write(byte(5));
        lcd.setCursor(0,1);
        lcd.write(byte(4));
        delay(500);
      }

      if(yyon>600)
      {
        motor.write(50);
        delay(15);
        lcd.setCursor(0,0);
        lcd.write(byte(3));
        lcd.setCursor(0,1);
        lcd.write(byte(6));
        delay(500);
      }
      else
      {
         motor.write(100);
         lcd.setCursor(0,0);
         lcd.write(byte(1));
         lcd.setCursor(0,1);
         lcd.write(byte(2));
      }
    if(btn==LOW)
      {
        
        lcd.setCursor(12,0);
        lcd.print(millis() / 1000);
        delay(500);
      }

if(Serial.available()>0)
  {         //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read();           //Seri haberleşmeden gelen veriyi okuyoruz.
  }
  if(veri == 's')
  {                  //Seri haberleşmeden k harfi geldiğinde bu kısım çalışır.
    Serial.println("test");
    delay(500);
  }

}
