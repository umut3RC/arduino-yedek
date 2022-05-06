int dir1=7;
int dir2=2;
int pwm1=6;
int pwm2=3;
int solsensor=8;
int sagsensor=11;

void setup() 
{
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(pwm1,OUTPUT);
  pinMode(pwm2,OUTPUT);
  pinMode(solsensor,INPUT);
  pinMode(sagsensor,INPUT);

}

void loop() 
{
  digitalWrite(pwm1,HIGH);
  digitalWrite(pwm2,LOW);

  if(digitalRead(sagsensor)==HIGH)
     {
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      delay(500);
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,LOW);
      delay(750);
     }
  if(digitalRead(solsensor)==HIGH)
     {
      digitalWrite(dir1,LOW);
      digitalWrite(dir2,HIGH);
      delay(500);
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,HIGH);
      delay(750);
     }    
}     
