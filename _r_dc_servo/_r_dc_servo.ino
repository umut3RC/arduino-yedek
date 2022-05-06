/*
ileri ECA 6CA
geri  ECC 6CC
sağ   ECB 6CB
sol   ECD 6CD
OK    ECE 6CE
dur   EF5 6F5
1 EC1 6C1
0 EC0 6C0

*/

#include <IRremote.h>

int RECV_PIN = 8;

IRrecv irrecv(RECV_PIN);
#include <Servo.h>
decode_results results;
#define ileri 0x6CA //numaranın başına 0x koy
#define dur 0x6CB
#define geri 0X6CC
int pwm=7;
int dca1=6;
int dca2=5;

int pot=A0;
Servo mtr;
void setup()
{
  mtr.attach(9);
  Serial.begin(9600);
  irrecv.enableIRIn(); 

pinMode(pwm,OUTPUT);
pinMode(dca1,OUTPUT);
pinMode(dca2,OUTPUT);
}

void loop() 
{
int val = analogRead(pot);
  
  if (irrecv.decode(&results)) 
  {
    if(results.value == ileri)
    {
mtr.write(50);
delay(15);
    } 
else   if(results.value == geri)
    {
mtr.write(90);
delay(15);
    } 
else    if(results.value == dur)
    {
mtr.write(130);
delay(15);
    } 
    irrecv.resume();
  }
  delay(100);
}
