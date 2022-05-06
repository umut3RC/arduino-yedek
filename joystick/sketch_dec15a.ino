int ledsag=1;
int ledon=2;
int ledsol=3;
int ledarka=4;
int ledorta=5;
int btn1=6;
int btn2=7;
int btn3=8;
int btn4=9;
int pmy=A1;
int pmx=A2;
int btnj=10;

int yyon=0;
int xyon=0;

void setup() 
{
 pinMode(ledsag,OUTPUT);
 pinMode(ledon,OUTPUT);
 pinMode(ledsol,OUTPUT);
 pinMode(ledarka,OUTPUT);
 pinMode(ledorta,OUTPUT);
 pinMode(btn1,INPUT);
 pinMode(btn2,INPUT);
 pinMode(btn3,INPUT);
 pinMode(btnj,INPUT);
  pinMode(pmy,INPUT);
   pinMode(pmy,INPUT);
}

void loop() 
{
  yyon=analogRead(pmy);
  xyon=analogRead(pmx);
  

  if(yyon<10)
    {
      digitalWrite(ledsag,HIGH);
      digitalWrite(ledorta,HIGH);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }
    else
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }

    if(yyon>1000)
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,HIGH);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,HIGH);
      
    }
    else
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }
    
    if(xyon<10)
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,HIGH);
      digitalWrite(ledon,HIGH);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }
    else
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }

    if(xyon>1000)
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,HIGH);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,HIGH);
      digitalWrite(ledsol,LOW);
      
    }
    else
    {
      digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
      
    }

     

    if(digitalRead(btn1)==HIGH)
      {
        digitalWrite(ledorta,HIGH);
      }
      else
      {
        digitalWrite(ledorta,LOW);
      }

      if(digitalRead(btn2)==HIGH)
      {
        digitalWrite(ledon,HIGH);
        digitalWrite(ledsag,HIGH);
        digitalWrite(ledsol,HIGH);
      }
      else
      {
        digitalWrite(ledon,LOW);
        digitalWrite(ledsag,LOW);
        digitalWrite(ledsol,LOW);
      }

            if(digitalRead(btn3)==HIGH)
      {
        digitalWrite(ledon,LOW);
        digitalWrite(ledsag,HIGH);
        digitalWrite(ledsol,HIGH);
        digitalWrite(ledorta,HIGH);
        digitalWrite(ledarka,HIGH);
        delay(250);
        digitalWrite(ledon,HIGH);
        digitalWrite(ledsag,LOW);
        digitalWrite(ledsol,LOW);
        digitalWrite(ledorta,HIGH);
        digitalWrite(ledarka,HIGH);
        delay(250);
        
       
      }
      else
      {
        digitalWrite(ledon,LOW);
        digitalWrite(ledorta,LOW);
        digitalWrite(ledarka,LOW);
        digitalWrite(ledsag,LOW);
        digitalWrite(ledsol,LOW);
      }

      if(digitalRead(btn4)==HIGH)
        {
          digitalWrite(ledsag,HIGH);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,HIGH);
      digitalWrite(ledarka,HIGH);
      digitalWrite(ledsol,HIGH);
        }
        else
        {
           digitalWrite(ledsag,LOW);
      digitalWrite(ledorta,LOW);
      digitalWrite(ledon,LOW);
      digitalWrite(ledarka,LOW);
      digitalWrite(ledsol,LOW);
        }
}
