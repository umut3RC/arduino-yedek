#include <Wire.h>

//int joystick_x = A0;
//int joystick_y = A1;

int joystick_x_shift_ctrl = A2;
int joystick_y_q_e = A3;

int jy_btn = 2;

int keyboard_space = 3;
int keyboard_r = 4;
int keyboard_tab = 5;
int keyboard_g = 6; 

long lastBtn = millis();
long thresh = 100;

//String s_jy_x;
//String s_jy_y;

void setup() 
{
  Serial.begin(9600);
  
  //pinMode(joystick_x, INPUT);
  //pinMode(joystick_y, INPUT);
  pinMode(joystick_x_shift_ctrl, INPUT);
  pinMode(joystick_y_q_e, INPUT);
  pinMode(keyboard_space, INPUT);
  pinMode(keyboard_r, INPUT);
  pinMode(keyboard_tab, INPUT);
  pinMode(keyboard_g, INPUT);
  pinMode(jy_btn, INPUT_PULLUP);
}

void loop()
{
  //int jyx = analogRead(joystick_x);
  //int jyy = analogRead(joystick_y);
  
  int vert = analogRead(joystick_x_shift_ctrl);
  int horz = analogRead(joystick_y_q_e);

  int btnspace = digitalRead(keyboard_space);
  int btnr = digitalRead(keyboard_r);
  int btntab = digitalRead(keyboard_tab);
  int btng = digitalRead(keyboard_g);

  int btnjy = digitalRead(jy_btn);
  
  //jyx = map(jyx,0,1023,1023,0);
  //jyy = map(jyy,0,1023,768,0);
  //jyx = jyx * -1;
  
//s_jy_x = String(jyx);
//s_jy_y = String(jyy);

  if (millis() - lastBtn > thresh) 
  {
    //Serial.println(s_jy_x);
    //Serial.println(s_jy_y);
    //delay(25);
    if(btnspace == HIGH)
      {
        Serial.println("10007");
        delay(25);
      }
      if(btnjy == 0)
      {
        Serial.println("20000");
        delay(25);
      }
    if(btnr == HIGH)
      {
        Serial.println("10006");
        delay(25);
      }
    if(btntab == HIGH)
      {
        Serial.println("10005");
        delay(25);
      }
    if(btng == HIGH)
      {
        Serial.println("10004");
        delay(25);
      }
    if (vert > 450 && vert < 600 && horz> 450 && horz< 600)//stop
      {
        Serial.println("5000");
        delay(25);
      }
    else
    {
      if(horz < 450)
      {
        Serial.println("10003");//3
        delay(25);
       }
    if(horz > 600)
      {
        Serial.println("10002");//2
        delay(25);
      }
    if(vert < 450)
      {
        Serial.println("10001");
        delay(25);
      }
    if(vert > 550)
      {
        Serial.println("10000");
        delay(25);
      }
    }
    lastBtn = millis();
    delay(25);
  }
}
