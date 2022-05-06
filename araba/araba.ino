#include <Servo.h>

Servo motor;
int potmetre=A0;
int sagfar=22;
int solfar=23;
int sagsin=24;
int solsin=30;
int btnfar=6;
int btnsagsin=5;
int btnsolsin=7;
int trig=12;
int echo=11;
long duration, mesafe;

void setup() 
{
  Serial.begin (9600);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
 motor.attach(13);
 pinMode(btnfar,INPUT);
 pinMode(btnsagsin,INPUT);
 pinMode(btnsolsin,INPUT);
 
 pinMode(sagfar,OUTPUT);  
 pinMode(sagsin,OUTPUT);  
 pinMode(solfar,OUTPUT);  
 pinMode(solsin,OUTPUT); 
 
 pinMode(potmetre,INPUT);


  
}
void loop()
{
if(digitalRead(btnfar)==HIGH)
    {
      digitalWrite(sagfar,HIGH);
      digitalWrite(solfar,HIGH);
     
    }
    else
    {
      digitalWrite(sagfar,LOW);
      digitalWrite(solfar,LOW);
    }

if(digitalRead(btnsagsin)==HIGH)
    {
      digitalWrite(sagsin,HIGH);
      delay(500);
      digitalWrite(sagsin,LOW);
       delay(500);
    }
    else
    {
      digitalWrite(sagsin,LOW);
    }
        if(digitalRead(btnsolsin)==HIGH)
          {
            digitalWrite(solsin,HIGH);
            delay(500);
            digitalWrite(solsin,LOW);
             delay(500);
          }
          else
          {
            digitalWrite(solsin,LOW);
          }

  
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration = pulseIn(echo, HIGH);
mesafe = (duration*.0343)/2;
Serial.print(mesafe);
Serial.println(" cm");
delay(250);

 if(mesafe<10)
   {
    digitalWrite(sagsin,HIGH);
    digitalWrite(solsin,HIGH);
   
   }
   else
   {
    digitalWrite(sagsin,LOW);
    digitalWrite(solsin,LOW);
   }
  
  
    
int pot = analogRead(potmetre);
     pot=map(pot,0,1023,0,180);
    motor.write(pot);
    delay(15);

   
}
