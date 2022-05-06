int a = 1; // Pinleri tanımlıyoruz
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
void setup()
{
pinMode(a, OUTPUT); // Pinlerin çıkış pini olduğunu belirtiyoruz.
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
}

void loop()
{
  digitalWrite(a,HIGH);
  digitalWrite(g,LOW);
  delay(1000);
  digitalWrite(b,HIGH);
  digitalWrite(a,LOW);
  delay(1000);

 digitalWrite(c,HIGH);
 digitalWrite(b,LOW);
  delay(1000);

 digitalWrite(d,HIGH);
 digitalWrite(c,LOW);
  delay(1000);

 digitalWrite(e,HIGH);
 digitalWrite(d,LOW);
  delay(1000);

 digitalWrite(f,HIGH);
 digitalWrite(e,LOW);
  delay(1000);

 digitalWrite(g,HIGH);
 digitalWrite(f,LOW);
  delay(1000);
 
 
 }
