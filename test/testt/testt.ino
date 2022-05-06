#include <Servo.h>
Servo mtr1;
Servo mtr2;
Servo mtr3;
Servo mtr4;
int val1=A0;
int val2=A1;

int pott1=0;
int pott2=0;

void setup()
{
Serial.begin(9600);

  mtr1.attach(8);
  mtr2.attach(9);
  mtr3.attach(10);
  mtr4.attach(11);
}
void loop()
{
int pot1 = analogRead(val1);
int pot2 = analogRead(val2);

pot1 = map(pot1,0,1023,0,180);
pot2 = map(pot2,0,1023,0,180);

pott1= 180-pot1; 
pott2= 180-pot2;

dur:

mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(3000);

goto git;

git:

mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(500 );
mtr1.write(115);
mtr2.write(75);
mtr3.write(115);
mtr4.write(70);
delay(500);
mtr1.write(115);
mtr2.write(75);
mtr3.write(115);
mtr4.write(70);
delay(500);
mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(500);
mtr1.write(75);
mtr2.write(110);
mtr3.write(80);
mtr4.write(110);
delay(500);

goto git;

}
void yedek()
{
  /*


dur:

mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(2000);

goto git;

git:

mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(500);
mtr1.write(115);
mtr2.write(75);
mtr3.write(110);
mtr4.write(70);
delay(500);
mtr1.write(115);
mtr2.write(75);
mtr3.write(110);
mtr4.write(70);
delay(500);
mtr1.write(90);
mtr2.write(90);
mtr3.write(90);
mtr4.write(90);
delay(500);
mtr1.write(75);
mtr2.write(110);
mtr3.write(70);
mtr4.write(110);
delay(500);

goto git;
*/
}
