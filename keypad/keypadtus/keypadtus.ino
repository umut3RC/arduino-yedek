#include <Keypad.h>

const byte satir = 4;
const byte sutun = 4;
int led=2;

char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte satir_pinleri[satir] = {13, 12, 11, 10};
byte sutun_pinleri[satir] = {9, 8, 7, 6};

Keypad klavye = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);

void setup()
{
  Serial.begin(9600);

  pinMode(led,OUTPUT);
}

void loop()
{
  tus = klavye.getKey();
  if (tus)
  {
    Serial.println(tus);
     switch (tus)
     {
      case '1':
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led,LOW);
     }
  }

  
}
