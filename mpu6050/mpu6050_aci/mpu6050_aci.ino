#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

MPU6050 ivme_sensor;
int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() 
{
Wire.begin();
Serial.begin(9600);
Serial.println("I2C cihazlar baslatiliyor...");
ivme_sensor.initialize();
Serial.println("Test cihazi baglantilari...");
Serial.println(ivme_sensor.testConnection() ?"MPU6050 baglanti basarili" : "MPU6050 baglanti basarisiz");

}

void loop() 
{
ivme_sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz );
ay=map(ay,-17000,17000,0,180);
Serial.println(ay);
Serial.println("\t");
delay(100);

}
