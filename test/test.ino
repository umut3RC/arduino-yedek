/*
buton basılıyken usb tak
kod yükle
rx tx çıkar kod yükle
tx 10

 */
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11); // RX, TX

void setup() 
{

  Serial.begin(9600);
  while (!Serial) 
  {
    ; 
  }


  Serial.println("Goodnight moon!")
  ;

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?")
  ;
}

void loop() { // run over and over
  if (mySerial.available()) 
  {
    Serial.write(mySerial.read())
    ;
  }
  if (Serial.available()) 
  {
    mySerial.write(Serial.read())
    ;
  }
}
