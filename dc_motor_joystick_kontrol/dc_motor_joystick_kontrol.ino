int joyx=A2;
int joyy=A1;

int dca1=9;
int dca2=8;
int dcah=6;

int dcb1=13;
int dcb2=12;
int dcbh=7;
void setup() 
{
  Serial.begin(9600);
 pinMode(joyx,INPUT);
 pinMode(joyy,INPUT);
 
pinMode(dca1,OUTPUT);
pinMode(dca2,OUTPUT);  
pinMode(dcah,OUTPUT);

pinMode(dcb1,OUTPUT);
pinMode(dcb2,OUTPUT);
pinMode(dcbh,OUTPUT);
}

void loop() 
{
int yony = analogRead(joyy);
int yonx = analogRead(joyx);

 if(yony >=800  )
   {
    analogWrite(dcah,250);

    digitalWrite(dca1,HIGH);
    digitalWrite(dca2,LOW);

    delay(500);
   }
   else if(yonx >=800  )
   {
    analogWrite(dcbh,250);

    digitalWrite(dcb1,HIGH);
    digitalWrite(dcb2,LOW);

    delay(500);
   }
   else 
   {
    digitalWrite(dcah,LOW);
    digitalWrite(dcbh,LOW);
   }

}
