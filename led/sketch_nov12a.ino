int led=0;
int btn1=5;
int btn2=4;
int btn3=3;
int btn4=2;
void setup() 
{
pinMode(led,OUTPUT);
pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(btn3,INPUT);
pinMode(btn4,INPUT);

}
void loop() 
{
  if(digitalRead(btn1)==LOW)
{
  for(int i=1;i<=2;i++)
    {
      digitalWrite(led,HIGH);
      delay(500);
      digitalWrite(led,LOW);
      delay(500);
    }
}
   if(digitalRead(btn2)==LOW)
{
  for(int i=1;i<=4;i++)
    {
      digitalWrite(led,HIGH);
      delay(500); 
      digitalWrite(led,LOW);
      delay(500);
} 
}
if(digitalRead(btn3)==LOW)
{
  for(int i=1;i<=8;i++)
    {
      digitalWrite(led,HIGH);
      delay(500); 
      digitalWrite(led,LOW);
      delay(500);
}
} 
      if(digitalRead(btn4)==LOW)
      {
        for(int i=1;i<=16;i++)
          {
            digitalWrite(led,HIGH);
            delay(500); 
            digitalWrite(led,LOW);
            delay(500);
          } 
      }
}
