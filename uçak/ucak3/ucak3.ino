#include <Servo.h>
Servo mtr1;
Servo mtr2;
Servo mtr3;

int val1=A0;
int jy1=A1;
int jy2=A2;

int led1=8;
int led2=9;
int led3=10;

int btn=2;
int durum=0;

void setup() 
{
mtr1.attach(7);
mtr2.attach(6);
mtr3.attach(5);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(btn,INPUT);
}

void loop() 
{
int pot1 = analogRead(val1);
int pot2 = analogRead(jy1);
int pot3 = analogRead(jy2);  

pot1 = map(pot1,0,1023,0,180);
pot2 = map(pot2,0,1023,0,180);
pot3 = map(pot3,0,1023,0,180);

if(durum==0)  
  {
    if(digitalRead(btn)==HIGH)
      {
        durum=1;
        delay(1000);
      }
  }

if(durum==1)
   {
    if(digitalRead(btn)==HIGH)
      {
        durum=0;
        delay(1000);
      }
   }
if(durum==0)
  {
   mtr1.write(pot1);
   mtr2.write(pot2);
   mtr3.write(pot3);
   digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
   delay(15);
  }
  if(durum==1)
    {
mtr1.write(pot1);
mtr2.write(pot2);
mtr3.write(pot3);
digitalWrite(led1,HIGH);
digitalWrite(led2,HIGH);
digitalWrite(led3,HIGH);
delay(100);

    }
} 
