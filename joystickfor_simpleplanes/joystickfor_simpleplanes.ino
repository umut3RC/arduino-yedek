#include <Wire.h>

int joystick_x = A0;
int joystick_y = A1;

long lastBtn = millis();
long thresh = 100;
String msg = "";
void setup() 
{
  Serial.begin(9600);
  
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
}

void loop()
{
  int jyx = analogRead(joystick_x);
  int jyy = analogRead(joystick_y);

    //mouse center
    if (jyx > 485 && jyx <520 && jyy > 485 && jyy <520) 
        {
          if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseCenter");
            lastBtn = millis();
            delay(50);
            }
        }
        else
        {
          mouseX();
          mouseY();
        }
        delay(50);
}

void mouseX()
{
  int jyx = analogRead(joystick_x);
  int jyy = analogRead(joystick_y); 
// mouse right M
    if (jyy > 520 && jyy < 750) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseRightM");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse right L
      if (jyy > 750 && jyy < 1023) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseRightL");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse left M
      if (jyy > 250 && jyy  < 485) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseLeftM");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse left L
      if (jyy > 0 && jyy < 250) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseLeftL");
            lastBtn = millis();
            delay(50);
          }
      }
}

void mouseY()
{
  int jyx = analogRead(joystick_x);
  int jyy = analogRead(joystick_y);
// mouse down M
    if (jyx > 250 && jyx < 485) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseDownM");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse down L
      if (jyx > 0 && jyx < 250) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseDownL");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse up M
      if (jyx > 520 && jyx < 750) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseUpM");
            lastBtn = millis();
            delay(50);
          }
      }
// mouse up L
      if (jyx > 750 && jyx < 1023) 
      {
        if (millis() - lastBtn > thresh) 
          {
            Serial.println("mouseUpL");
            lastBtn = millis();
            delay(50);
          }
      }
}
