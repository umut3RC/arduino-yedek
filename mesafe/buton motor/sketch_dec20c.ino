#include <Servo.h> 

Servo myservo;

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 1;     // the number of the pushbutton pin
      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  { 
  myservo.attach(3);
  myservo.write(170);  // set servo to mid-point
  { 
} 
} 
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    myservo.writeMicroseconds(15); 
     myservo.write(90); 
    delay(500);
     myservo.writeMicroseconds(15); 
     myservo.write(180); 
    delay(500);
    myservo.writeMicroseconds(15); 
     myservo.write(90); 
    delay(500);
   
    

  } else {
  myservo.write(180);  // set servo to mid-point

  }
}
