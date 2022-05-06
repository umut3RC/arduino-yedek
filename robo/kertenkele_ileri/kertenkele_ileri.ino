#include <Servo.h>
Servo mtr1; // ön
Servo mtr2; // arka
Servo mtr3; // gövde

void setup() 
{
  Serial.begin(9600);
mtr1.attach(7);
mtr2.attach(6);
mtr3.attach(5);



}

void loop() //------------------------------
{
basla:
bekle();
goto ileri;

ileri://ön -arka -gövde
hareket(90  ,90  ,145);
hareket(130 ,50  ,145);
hareket(130 ,50  ,110);
hareket(90  ,90 ,110);
hareket(90  ,90 ,75);
hareket(50  ,130 ,75);
hareket(50  ,130 ,110);
hareket(90  ,90 ,110);
goto ileri;
}

void bekle ()
{
 mtr1.write(90);
 mtr2.write(90);
 mtr3.write(110);
 delay(2000); 
}

void hareket (int on, int arka, int govde)
{
  mtr1.write(on);
  mtr2.write(arka);
  mtr3.write(govde);
  delay(500);
}
