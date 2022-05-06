#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>
MPU6050 ivme_sensor;
int16_t ax, ay, az;
int16_t gx, gy, gz;

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

int otok=30;
int otoy=32;

int btnled=40;
int btnpilot=41;

int durum=0;
int otopilot=0;


void setup() 
{
Wire.begin();
Serial.begin(9600);
Serial.println("I2C cihazlar baslatiliyor...");
ivme_sensor.initialize();
Serial.println("Test cihazi baglantilari...");
Serial.println(ivme_sensor.testConnection() ?"MPU6050 baglanti basarili" : "MPU6050 baglanti basarisiz");

  
mtr1.attach(7);
mtr2.attach(6);
mtr3.attach(5);

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(otok,OUTPUT);
pinMode(otoy,OUTPUT);

pinMode(btnled,INPUT);
pinMode(btnpilot,INPUT);
}

void loop() 
{
int pot1 = analogRead(val1);
int pot2 = analogRead(jy1);
int pot3 = analogRead(jy2);  

int bled = digitalRead(btnled);
int boto = digitalRead(btnpilot);

pot1 = map(pot1,0,1023,0,180);
pot2 = map(pot2,0,1023,0,180);
pot3 = map(pot3,0,1023,0,180);

ivme_sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz );
ay=map(ay,-17000,17000,0,180);
ax=map(ax,-17000,17000,0,180);

if(durum==0)  
  {
    if(bled==HIGH)
      {
        durum=1;
        delay(500);
      }
  }

else if(durum==1)
   {
    if(bled==HIGH)
      {
        durum=0;
        delay(1000);
      }
   }
if(otopilot == 0)
   {
    if(boto== HIGH)
       {
        otopilot=1;
        delay(500);
       }
   }
else if(otopilot == 1)
   {

    if(boto== HIGH)
       {
        otopilot=0;
        delay(500);
       }
   }
if(durum==0 && otopilot==0)
  {
   mtr1.write(pot1);
   mtr2.write(pot2);
   mtr3.write(pot3);
   digitalWrite(otoy,LOW);
   digitalWrite(otok,HIGH);  
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(led3,LOW);
   delay(15);
  }
else if(durum==1 && otopilot==0)
    {
    mtr1.write(pot1);
    mtr2.write(pot2);
    mtr3.write(pot3);
    digitalWrite(otoy,LOW);
    digitalWrite(otok,HIGH);
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    delay(100);
    }
else if(otopilot==1)
        {
         digitalWrite(otok,LOW);
         digitalWrite(otoy,HIGH);
         mtr1.write(90);
         mtr2.write(ay);
         mtr3.write(ax);
         delay(100);
        }
 
} 
