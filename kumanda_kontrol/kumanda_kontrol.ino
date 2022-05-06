
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
#include <Servo.h>
Servo mtr;

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;
#define ileri 0xFB40BF//numaranın başına 0x koy
#define sag 0xFBA05F
#define sol 0xFBE01F
#define geri 0XFB50AF
#define ok 0xFB609F
#define bir 0xFBE817

int pwm=13;
int dca1=12;
int dca2=11;



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
mtr.attach(7);

pinMode(pwm,OUTPUT);
pinMode(dca1,OUTPUT);
pinMode(dca2,OUTPUT);
}

void loop() 
{  
  if (irrecv.decode(&results)) 
  {
    if(results.value == ileri)
    {
     digitalWrite(pwm,HIGH);
     digitalWrite(dca1,HIGH);
     digitalWrite(dca2,LOW);
     delay(50);
    } 
else   if(results.value == geri)
    {
     digitalWrite(pwm,HIGH);
     digitalWrite(dca1,LOW);
     digitalWrite(dca2,HIGH);
     delay(50);
    } 
else    if(results.value == ok)
    {
     digitalWrite(pwm,LOW);
     digitalWrite(dca1,LOW);
     digitalWrite(dca2,LOW);
     delay(50);
    } 

    if(results.value == sag)
    {
     mtr.write(0);
     delay(15);
    }
    if(results.value == sol)
    {
     mtr.write(180);
     delay(15);
    }
    if(results.value == bir)
    {
     mtr.write(90);
     delay(15);
    }
    irrecv.resume();
  }
  delay(100);
}
