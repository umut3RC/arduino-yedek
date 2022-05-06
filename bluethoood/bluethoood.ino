
int durum; 

 
void setup() {
 
    Serial.begin(9600);
}
 
void loop() {
    if(Serial.available() > 0){     
      durum = Serial.read();   
    }
   
         Serial.println(durum);
         delay(250);
    
}
