#include <Servo.h>
Servo mtr1;
Servo mtr2;
Servo mtr3;
Servo mtr4;

int val1=A1;
int val2=A2;
int val3=A3;

void setup() 
{
  Serial.begin(9600);
mtr1.attach(7);
mtr2.attach(6);
mtr3.attach(5);



}

void loop() 
{
int pot1 = analogRead(val1);
int pot2 = analogRead(val2);
int pot3 = analogRead(val3);

pot1 = map(pot1,0,1023,0,180);
pot2 = map(pot2,0,1023,0,180);
pot3 = map(pot3,0,1023,0,180);

mtr1.write(pot1);
mtr2.write(pot2);
mtr3.write(pot3);
delay(100);

Serial.println("1");
Serial.println(pot1);
Serial.println("2");
Serial.println(pot2);
Serial.println("3");
Serial.println(pot3);

}
