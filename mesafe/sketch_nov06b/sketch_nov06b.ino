#include <Servo.h>
 
// Ultrasonik Sinyal pinleri
int trigPin = 2;
int echoPin = 3;
 
long duration;
int distance;
 
Servo mtrr; 
Servo mtrn; 

int radarderece;
void setup() {
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
  for(int i=20;i<=150;i++)
  { distance = calculateDistance(); 
    if(distance<=5)
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
          if(distance<=5)
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
        mtrn.write(n-10);
        delay(15);
       }
   }
else if(radarderece >90)
   {
    for(int n=90; n<=radarderece; n++)
       {
        mtrn.write(n+10);
        delay(15);
       }
    } 
else if(radarderece == 90)
   {
    mtrn.write(90); 
    delay(500);     
   }

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
