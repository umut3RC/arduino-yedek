#include <Servo.h>
 
// Ultrasonik Sinyal pinleri
int trigPin = 2;
int echoPin = 3;
 
long duration;
int distance;
 
Servo mtrr; 
Servo mtrn; 

int radarderece;

int pwm=5;
int a1=6;
int a2=7;

void setup() 
{
pinMode(pwm,OUTPUT);
pinMode(a1,OUTPUT);
pinMode(a2,OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  Serial.begin(9600);
  mtrr.attach(13); 
  mtrn.attach(12);
}
void loop() 
{
  
  
 goto radar;
  
radar:  
  analogWrite(pwm,0);
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);

  for(int i=20;i<=150;i++)
  { distance = calculateDistance(); 
    if(distance<=25)
            {
              
              goto hedef;
            }
    else
    {
    mtrr.write(i); 
    delay(30); 
    
    Serial.print(i); Serial.print(","); 
    Serial.print(distance); 
    Serial.print(".");
    radarderece=i;
    }
                        
  } 
    for(int i=150;i>20;i--)
        {  distance = calculateDistance(); 
          if(distance<=25)
            {
              
              goto hedef;
            }
              else
              {
              mtrr.write(i); 
              delay(30); 
              
              Serial.print(i); Serial.print(","); 
              Serial.print(distance); 
              Serial.print(".");
              radarderece=i;
              }
          
         }
         goto radar;
hedef:

distance = calculateDistance(); 
    Serial.print("----"); 
    Serial.print(radarderece); 
    Serial.print("----");
    delay(2000);
goto nisan;

nisan:
if(radarderece <90)
   {
    for(int n=90; n>=radarderece; n--)
       {
        mtrn.write(n);
        delay(15);
       }
   }
else if(radarderece >90)
   {
    for(int n=90; n<=radarderece; n++)
       {
        mtrn.write(n);
        delay(15);
       }
    } 
else if(radarderece == 90)
   {
    mtrn.write(90); 
    delay(15);     
   }  
    delay(500);   
goto saldiri;

saldiri:
analogWrite(pwm,1023);
digitalWrite(a1,HIGH);
digitalWrite(a2,LOW);
delay(6000);
goto radar;

}

 
int calculateDistance()
{ 
   
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); 
  distance= duration*0.034/2;
  return distance;
}
