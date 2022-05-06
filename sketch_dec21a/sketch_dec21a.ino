/*
  Demo of Arduino communication with Java
  Based on the work of Farrell Farbod www.farellf.com

  Additions by Gord Payne - 2018
  Arduino circuit:
10K Potentiometer outer leads connected to +5V and Gnd, middle to A1
Momentary Contact Button to digital pin 7, 10K resistor to GND
                  Other side to +5V
I2C LED 16x2 display SDA to A4, SCL to A5
*/
#include <Wire.h>


int btn1 = 2;

int btnVal;
long lastBtn = millis();
long thresh = 100;
String msg = "";
void setup() {

  Serial.begin(9600);
  pinMode(btn1, INPUT);


}

// the loop routine runs over and over again forever:
void loop() {
  btnVal = digitalRead(btn1);

  if (btnVal) {
    if (millis() - lastBtn > thresh) {
      Serial.println("Hi");

      lastBtn = millis();

      delay(50);
    }
  }
  else if (Serial.available() > 0) {

    char inVal = Serial.read();
    if (inVal == '1') 
    {

    } else {
      Serial.print("gettingMsg");
      getMessage();

    }
  } else {

    Serial.println(digitalRead(btn1));
  }
  delay(50);        // delay in between reads for stability
}

void getMessage() {
  if (Serial.available() > 0) {
    msg = Serial.readString();
  }

  Serial.print(msg);


  msg = "";
}
