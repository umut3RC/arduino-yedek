
int analogPin = A1;
float gerilimDeger = 0;
float sensorDeger = 0;
float sicaklikDeger = 0;
int trig=7;
int echo=2;


long duration, mesafe;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
         
}
 
void loop() 
{
 
 sensorDeger = analogRead(analogPin); 
 Serial.print("Sensör Değeri:  ");
 Serial.println(sensorDeger);
 gerilimDeger = sensorDeger/1,0742;
 Serial.print("Gerilim Değeri: ");
 Serial.println(gerilimDeger); 
 sicaklikDeger = (gerilimDeger / 10.0) / 9,31;
 Serial.print("Sıcaklık Değeri: ");
 Serial.println(sicaklikDeger);
 Serial.println("----------");
 delay(2000);
               digitalWrite(trig, LOW);
              delayMicroseconds(2);
              digitalWrite(trig, HIGH);
              delayMicroseconds(10);
              digitalWrite(trig, LOW);
              duration = pulseIn(echo, HIGH);
              mesafe = (duration*.0343)/2;
              Serial.print(mesafe);
              Serial.println(" cm");
              delay(2000);

}
