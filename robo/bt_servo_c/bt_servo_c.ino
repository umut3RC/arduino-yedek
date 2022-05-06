/*
buton basılıyken usb tak
kod yükle
rx tx çıkar kod yükle
tx 10

 */
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial btt(10,11); // RX, TX

Servo mtr1; // ön
Servo mtr2; // arka
Servo mtr3; // gövde

void setup() 
{
mtr1.attach(7);
mtr2.attach(6);
mtr3.attach(5);
  // set the data rate for the SoftwareSerial port
  btt.begin(9600);
}

void loop()
{ 
if (btt.available()>0) 
   {
int btx = btt.read();

   if(btx == '1' )
      {
       mtr3.write(145);
       delay(15);
       }
    else if (btx == '3')
             {
              mtr3.write(75);
              delay(15);
              }
     else if (btx == '2')
              {
               mtr1.write(130);
               delay(15);
               }
      else if (btx == '4')
               {
                mtr1.write(50);
                delay(15);
                }
       else if (btx == 'k')
                {
                 mtr2.write(50);
                 delay(15);
                 }
        else if (btx == 'x')
                {
                 mtr2.write(130);
                 delay(15);
                 } 
         else if (btx == 'u')
                 {
                  mtr3.write(110);
                  delay(15);
                 }
         else if (btx == 'o')
                 {
                  mtr1.write(90);
                  mtr2.write(90);
                  delay(15);
                 }      
   } 
}
