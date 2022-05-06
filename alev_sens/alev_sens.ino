#include <Servo.h>
Servo motor;

int buzzer = 2; 
int alev=7;
int led=8;


void setup() 
{
  
  motor.attach(11);
  pinMode(led,OUTPUT);
  pinMode(alev,INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() 
{
   
  if(digitalRead(alev)==LOW)
  {
    
  for (int i = 0; i < 80; i++) 
  {  
    digitalWrite(buzzer, HIGH);
    digitalWrite(buzzer, LOW); 
    delay(1);
  }
    delay(50);
    
  for (int j = 0; j < 100; j++) 
  { 
    digitalWrite(buzzer, HIGH);
    delay(2); 
    digitalWrite(buzzer, LOW);
    delay(2);
  }
  delay(100);
}
 if(digitalRead(alev)==LOW)
{
  motor.write(90);
    digitalWrite(led,HIGH);
    delay(250);
    digitalWrite(led,LOW);
    delay(250);
}
else
{
  digitalWrite(buzzer,HIGH);
  digitalWrite(led,LOW);
  motor.write(180);
}
}
