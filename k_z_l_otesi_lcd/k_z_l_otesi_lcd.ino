int sensorPin = A0; 
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,13,12,11,10);
void setup()
{
lcd.begin(16,2);
lcd.setCursor(0,0);
Serial.begin(9600);
}
void loop()
{
  
int deger = analogRead(sensorPin);
Serial.println(deger);
delay(500);

  if(deger<70 && deger>56)
     {
      lcd.print("mavi");
      delay(500);
      lcd.clear();
     }
     else
     {
      lcd.print("bilinmiyor");
      delay(500);
      lcd.clear();
     }
}


/*
 * analog
   mavi  105-110
   kırmızı 97-100
   yeşil  112-117
 */
