#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,13,12,11,10);

int analogpin = A0;

void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);


}

void loop() 
{
int isik = analogRead(analogpin);

if(isik>500)
   {
    lcd.setCursor(0,0);
    lcd.print("test");
   }
   else
   {
    lcd.setCursor(0,0);
    lcd.print("ldr");
   }
 

}
