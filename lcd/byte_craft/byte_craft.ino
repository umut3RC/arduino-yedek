/*
|============================|
|BYTE-CRAFT         By       |
|                    umut3RC |
|UMTER STUDIOS               |
|============================|
*/
#include <LiquidCrystal.h>
LiquidCrystal ekran(12,11,9,8,7,6);
int btn1 = 22;
int btn2 = 24;
int btn3 = 26;
int btn4 = 28;
int btn5 = 30;
//kontrol
int durum=0;//konum
int yon=0;//yön

// özel karakter
byte oyuncusag[8] = {
  0b00000,
  0b11100,
  0b11010,
  0b11110,
  0b01100,
  0b01110,
  0b01100,
  0b01100
};
byte oyuncusol[8] = {
  0b00000,
  0b00111,
  0b01011,
  0b01111,
  0b00110,
  0b01110,
  0b00110,
  0b00110
};
byte block1[8] = { // küp
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};
byte block2[8] = { // basamak
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b01110
};
byte block3[8] = {  // direk
  0b00000,
  0b00000,
  0b00000,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100
};
byte block4[8] = { // kapı
  0b00000,
  0b00000,
  0b00000,
  0b01110,
  0b01010,
  0b01110,
  0b01110,
  0b01110
};
void setup() 
{
Serial.begin(9600);
ekran.begin(16,2);
ekran.createChar(0, oyuncusag);
ekran.createChar(1, oyuncusol);
ekran.createChar(2, block1);
ekran.createChar(3, block2);
ekran.createChar(4, block3);
ekran.createChar(5, block4); // ekran.write(byte(buraya sayı"0-6"));

pinMode(btn1,INPUT);
pinMode(btn2,INPUT);
pinMode(btn3,INPUT);
pinMode(btn4,INPUT);
pinMode(btn5,INPUT);



}

void loop()//------------------- 
{
int bd1 = digitalRead(btn1);//sağ
int bd2 = digitalRead(btn2);//sol
int bd3 = digitalRead(btn3);//block koyma
int bd4 = digitalRead(btn4);//block kırma
int bd5 = digitalRead(btn5);//menu-play

giris:
 if(durum==0)
   {    
    menu();
   }   
if(durum==0 && bd5==HIGH)
         {
          durum=1;
          goto logo;       
         }

logo:
  if(durum == 1)
     {
      durum=2;
    marka(2000);
    goto basla;
     }
     
basla:

  if(durum == 2)
     {
      ekran.setCursor(0,1);
      ekran.write(byte(0));
      durum=3;
      yon=1;
      goto basla;
     }
     else if(durum==3 && bd1==HIGH)
        {
         ekran.clear();
         ekran.setCursor(1,1);
         ekran.write(byte(0));
         durum=4;
         yon=1;      
         delay(500);
        }
      else if(durum==4 && bd1==HIGH)
        {
         ekran.setCursor(1,1);
         ekran.print(" ");
         ekran.setCursor(2,1);
         ekran.write(byte(0));
         durum=5;
         yon=1;
         delay(500);
        }
     else if(durum==5 && bd1==HIGH)
       {
       ekran.setCursor(2,1);
         ekran.print(" ");
       ekran.setCursor(3,1);
       ekran.write(byte(0));
       durum=6;
       yon=1;       
       delay(500);
       }
       else if(durum==6 && bd1==HIGH)
        {
         ekran.setCursor(3,1);
         ekran.print(" ");
         ekran.setCursor(4,1);
         ekran.write(byte(0));
         durum=7;
         yon=1;
         delay(500);
        }
      else if(durum==7 && bd1==HIGH)
        {
         ekran.setCursor(4,1);
         ekran.print(" ");
         ekran.setCursor(5,1);
         ekran.write(byte(0));
         durum=8;
         yon=1;
         delay(500);
        }
     else if(durum==8 && bd1==HIGH)
       {
       ekran.setCursor(5,1);
         ekran.print(" ");
       ekran.setCursor(6,1);
       ekran.write(byte(0));
       durum=9;
       yon=1;
       delay(500);
       }
       else if(durum==9 && bd1==HIGH)
        {
         ekran.setCursor(6,1);
         ekran.print(" ");
         ekran.setCursor(7,1);
         ekran.write(byte(0));
         durum=10;
         yon=1;
         delay(500);
        }
      else if(durum==10 && bd1==HIGH)
        {
         ekran.setCursor(7,1);
         ekran.print(" ");
         ekran.setCursor(8,1);
         ekran.write(byte(0));
         durum=11;
         yon=1;
         delay(500);
        }
     else if(durum==11 && bd1==HIGH)
       {
       ekran.setCursor(8,1);
         ekran.print(" ");
       ekran.setCursor(9,1);
       ekran.write(byte(0));
       durum=12;
       yon=1;
       delay(500);
       }
       else if(durum==12 && bd1==HIGH)
        {
         ekran.setCursor(9,1);
         ekran.print(" ");
         ekran.setCursor(10,1);
         ekran.write(byte(0));
         durum=13;
         yon=1;
         delay(500);
        }
      else if(durum==13 && bd1==HIGH)
        {
         ekran.setCursor(10,1);
         ekran.print(" ");
         ekran.setCursor(11,1);
         ekran.write(byte(0));
         durum=14;
         yon=1;
         delay(500);
        }
     else if(durum==14 && bd1==HIGH)
       {
       ekran.setCursor(11,1);
         ekran.print(" ");
       ekran.setCursor(12,1);
       ekran.write(byte(0));
       durum=15;
       yon=1;
       delay(500);
       }
       else if(durum==15 && bd1==HIGH)
        {
         ekran.setCursor(12,1);
         ekran.print(" ");
         ekran.setCursor(13,1);
         ekran.write(byte(0));
         durum=16;
         yon=1;
         delay(500);
        }
      else if(durum==16 && bd1==HIGH)
        {
         ekran.setCursor(13,1);
         ekran.print(" ");
         ekran.setCursor(14,1);
         ekran.write(byte(0));
         durum=17;
         yon=1;
         delay(500);
        }
     else if(durum==17 && bd1==HIGH)
       {
      ekran.setCursor(14,1);
         ekran.print(" ");
       ekran.setCursor(15,1);
       ekran.write(byte(0));
       durum=18;
       yon=1;
       delay(500);
       }/*sağ yön       
 ---------------------------
 sol yön
*/ 
if(durum==2 && bd2==HIGH)
        {
         ekran.setCursor(1,1);
       ekran.print(" ");
         ekran.setCursor(0,1);
         ekran.write(byte(1));
         durum=2;
         yon=0;
         delay(500);
        }
if(durum==3 && bd2==HIGH)
        {
         ekran.setCursor(2,1);
       ekran.print(" ");
         ekran.setCursor(1,1);
         ekran.write(byte(1));
         durum=2;
         yon=0;
         delay(500);
         ekran.clear();
         delay(15);
        }
      if(durum==4 && bd2==HIGH)
        {
         ekran.setCursor(1,1);
       ekran.print(" ");
         ekran.setCursor(0,1);
         ekran.write(byte(1));
         durum=3;
         yon=0;
         delay(500);
        }
     if(durum==5 && bd2==HIGH)
       {
       ekran.setCursor(2,1);
       ekran.print(" ");
       ekran.setCursor(1,1);
       ekran.write(byte(1));
       durum=4; 
       yon=0;      
       delay(500);
       }
       if(durum==6 && bd2==HIGH)
        {
         ekran.setCursor(3,1);
       ekran.print(" ");
         ekran.setCursor(2,1);
         ekran.write(byte(1));
         durum=5;
         yon=0;
         delay(500);
        }
      if(durum==7 && bd2==HIGH)
        {
         ekran.setCursor(4,1);
       ekran.print(" ");
         ekran.setCursor(3,1);
         ekran.write(byte(1));
         durum=6;
         yon=0;
         delay(500);
        }
     if(durum==8 && bd2==HIGH)
       {
       ekran.setCursor(5,1);
       ekran.print(" ");
       ekran.setCursor(4,1);
       ekran.write(byte(1));
       durum=7;
       yon=0;
       delay(500);
       }
       if(durum==9 && bd2==HIGH)
        {
         ekran.setCursor(6,1);
       ekran.print(" ");
         ekran.setCursor(5,1);
         ekran.write(byte(1));
         durum=8;
         yon=0;
         delay(500);
        }
      if(durum==10 && bd2==HIGH)
        {
         ekran.setCursor(7,1);
       ekran.print(" ");
         ekran.setCursor(6,1);
         ekran.write(byte(1));
         durum=9;
         yon=0;
         delay(500);
        }
     if(durum==11 && bd2==HIGH)
       {
       ekran.setCursor(8,1);
       ekran.print(" ");
       ekran.setCursor(7,1);
       ekran.write(byte(1));
       durum=10;
       yon=0;
       delay(500);
       }
       if(durum==12 && bd2==HIGH)
        {
         ekran.setCursor(9,1);
       ekran.print(" ");
         ekran.setCursor(8,1);
         ekran.write(byte(1));
         durum=11;
         yon=0;
         delay(500);
        }
      if(durum==13 && bd2==HIGH)
        {
         ekran.setCursor(10,1);
       ekran.print(" ");
         ekran.setCursor(9,1);
         ekran.write(byte(1));
         durum=12;
         yon=0;
         delay(500);
        }
     if(durum==14 && bd2==HIGH)
       {
       ekran.setCursor(11,1);
       ekran.print(" ");
       ekran.setCursor(10,1);
       ekran.write(byte(1));
       durum=13;
       yon=0;
       delay(500);
       }
       if(durum==15 && bd2==HIGH)
        {
         ekran.setCursor(12,1);
         ekran.print(" ");
         ekran.setCursor(11,1);
         ekran.write(byte(1));
         durum=14;
         yon=0;
         delay(500);
        }
      if(durum==16 && bd2==HIGH)
        {
         ekran.setCursor(13,1);
       ekran.print(" ");
         ekran.setCursor(12,1);
         ekran.write(byte(1));
         durum=15;
         yon=0;
         delay(500);
        }
     if(durum==17 && bd2==HIGH)
       {
       ekran.setCursor(14,1);
       ekran.print(" ");
       ekran.setCursor(13,1);
       ekran.write(byte(1));
       durum=16;
       yon=0;
       delay(500);
       } 
       if(durum==18 && bd2==HIGH)
       {
       ekran.setCursor(15,1);
       ekran.print(" ");
       ekran.setCursor(14,1);
       ekran.write(byte(1));
       durum=17;
       yon=0;
       delay(500);     
       }
//----------------0 yönlü block koyma 00000000000000000000000000000000
if(durum==4 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(0,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==5 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(1,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==6 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(2,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==7 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(3,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==8 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(4,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==9 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(5,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==10 && yon==0  && bd3==HIGH) // block koyma
   {
    ekran.setCursor(6,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==11 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(7,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==12 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(8,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==13 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(9,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==14 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(10,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==15 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(11,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==16 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(12,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==17 && yon==0 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(13,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==18 && yon==0 && bd3==1 ) // block koyma
   {
    ekran.setCursor(14,1);
    ekran.write(byte(2));
    delay(15);
   }
//--------------1yönlü block koyma 11111111111111111111111111

if(durum==5 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(3,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==6 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(4,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==7 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(5,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==8 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(6,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==9 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(7,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==10 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(8,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==11 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(9,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==12 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(10,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==13 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(11,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==14 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(12,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==15 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(13,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==16 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(14,1);
    ekran.write(byte(2));
    delay(15);
   }
if(durum==17 && yon==1 && bd3==HIGH) // block koyma
   {
    ekran.setCursor(15,1);
    ekran.write(byte(2));
    delay(15);
   }
//-----------------------------0 yönlü block kırma 0000000000000000000000
if(durum==4 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(0,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==5 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(1,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==6 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(2,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==7 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(3,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==8 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(4,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==9 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(5,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==10 && yon==0  && bd4==HIGH) // block kırma
   {
    ekran.setCursor(6,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==11 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(7,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==12 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(8,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==13 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(9,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==14 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(10,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==15 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(11,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==16 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(12,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==17 && yon==0 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(13,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==18 && yon==0 && bd4==1 ) // block kırma
   {
    ekran.setCursor(14,1);
    ekran.print(" ");
    delay(15);
   }
//------------------------------------1yönlü block kırma 11111111111111111

if(durum==5 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(3,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==6 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(4,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==7 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(5,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==8 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(6,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==9 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(7,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==10 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(8,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==11 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(9,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==12 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(10,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==13 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(11,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==14 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(12,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==15 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(13,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==16 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(14,1);
    ekran.print(" ");
    delay(15);
   }
if(durum==17 && yon==1 && bd4==HIGH) // block kırma
   {
    ekran.setCursor(15,1);
    ekran.print(" ");
    delay(15);
   }
   
}
       
//------------------------------------------------------------------------------------------
void marka(int gecikme)
{
  ekran.setCursor(0,0);
  ekran.print("* UMTER");
  ekran.setCursor(15,0);
  ekran.print("*");
  ekran.setCursor(0,1);
  ekran.print("* STUDIOS OPT.");
  ekran.setCursor(15,1);
  ekran.print("*");
  delay(gecikme);
  ekran.clear();
  delay(15);
ekran.setCursor(0,0);
ekran.print("* U M T E R");
ekran.setCursor(15,0);
ekran.print("*");
ekran.setCursor(0,1);
ekran.print("* S T U D I O S");
ekran.setCursor(15,1);
ekran.print("*");
delay(1000);
ekran.clear();
delay(15);
   ekran.setCursor(0,0);
  ekran.print("* UMTER");
  ekran.setCursor(15,0);
  ekran.print("*");
  ekran.setCursor(0,1);
  ekran.print("* STUDIOS OPT.");
  ekran.setCursor(15,1);
  ekran.print("*");
  delay(gecikme);
  ekran.clear(); 
  delay(15);

}

void menu()
{
    ekran.setCursor(0,0);
    ekran.write(byte(0));
    ekran.setCursor(3,0);
    ekran.print("BYTE-CRAFT");
    ekran.setCursor(15,0);
    ekran.write(byte(1));
    ekran.setCursor(5,1);
    ekran.print("-OYNA-");
    delay(100);
    ekran.clear();
    delay(15);
}
void yedek()
{

}
