
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX



void setup() 
{
  Serial.begin(9600);
  while (!Serial) 
  {
    ; 
  }
  
  Serial.println("deneme");
  mySerial.begin(9600);

}

void loop() 
{ 
  
  if (mySerial.available())
      {
        Serial.write(mySerial.read());     
      }
}
