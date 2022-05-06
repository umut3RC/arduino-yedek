
int anahtar=13;
int led[]={1,2,3,4};


void setup() 
{
 for(int i=0;i<3;i++)
{
pinMode(led[i],OUTPUT);
}
pinMode(anahtar,INPUT);
}

void loop() 
{
 if(digitalRead(anahtar)==LOW) 
{
for(int a=1;a<=8;a++)
{
for(int i=0;i<=3;i++)
{
digitalWrite(led[i],HIGH);
}
delay(0500);
for(int i=0;i<=3;i++)
{
digitalWrite(led[i],LOW);
}
delay(0500);

}

}

}
