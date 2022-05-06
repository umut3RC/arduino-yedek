#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,13,12,11,10);
int sensor=4;

void setup() 
{
 Serial.begin(9600);
 pinMode(sensor,INPUT);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
}

void loop() 
{
  Serial.println(digitalRead(sensor));
  delay(500);

   if(digitalRead(sensor)==HIGH)
      {
        lcd.print("hareket");
        delay(1000);
        lcd.clear();
      }
      
      else
      {
        lcd.print("sabit");
        delay(1000);
        lcd.clear();
      }

}
