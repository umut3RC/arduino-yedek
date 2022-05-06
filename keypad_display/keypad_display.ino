#include <Keypad.h>

const byte satir = 4;
const byte sutun = 4;


char tus;
char tus_takimi[satir][sutun] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte satir_pinleri[satir] = {14,15,16,17};
byte sutun_pinleri[satir] = {18,19,20,21};

Keypad klavye = Keypad(makeKeymap(tus_takimi) , satir_pinleri , sutun_pinleri , satir , sutun);

int a = 13; 
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;

void setup()
{
  Serial.begin(9600);

pinMode(a, OUTPUT); 
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
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
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       delay(900);
       digitalWrite(b,LOW);
       digitalWrite(c,LOW);
       break;

       case '2':
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(d,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(b,LOW);
       digitalWrite(g,LOW);
       digitalWrite(e,LOW);
       digitalWrite(d,LOW);
        break;

        case '3':
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(b,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
        break;

        case '4':
       digitalWrite(f,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);      
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(b,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(f,LOW);
        break;

        case '5':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
        break;

        case '6':
       digitalWrite(e,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       delay(900);      
       digitalWrite(e,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
        break;

        case '7':
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(c,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(c,LOW);
       digitalWrite(b,LOW);
        break;

        case '8':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(b,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(b,LOW);
        break;

        case '9':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(b,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(b,LOW);
        break;

        case '0':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(b,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(b,LOW);
        break;

        case 'A':
       digitalWrite(a,HIGH);
       digitalWrite(b,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(g,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(b,LOW);
       digitalWrite(f,LOW);
       digitalWrite(e,LOW);
       digitalWrite(c,LOW);
       digitalWrite(g,LOW);
       break;

       case 'B':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(g,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(b,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(g,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(b,LOW);
       break;
       
       case 'C':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(d,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(e,LOW);
       digitalWrite(d,LOW);
       break;

       case 'D':
       digitalWrite(a,HIGH);
       digitalWrite(f,HIGH);
       digitalWrite(c,HIGH);
       digitalWrite(d,HIGH);
       digitalWrite(e,HIGH);
       digitalWrite(b,HIGH);
       delay(900);      
       digitalWrite(a,LOW);
       digitalWrite(f,LOW);
       digitalWrite(c,LOW);
       digitalWrite(d,LOW);
       digitalWrite(e,LOW);
       digitalWrite(b,LOW);
        break;

     }
  }

  
}
