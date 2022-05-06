#include <IRremote.h>

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;


#define BUTON1 441
#define BUTON2 0xFF18E7


int led1 = 8;
int led2 = 9;
int led3 = 10;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() 
{

  if (irrecv.decode(&results))
  {
    if (results.value == BUTON1)
    {
      digitalWrite(led1,HIGH);
            
    }
    else
    {
      digitalWrite(led1,LOW);
    }
    }
    
    irrecv.resume();
  }
