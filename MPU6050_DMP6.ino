#define OUTPUT_READABLE_YAWPITCHROLL
//  #define INTERRUPT_PIN 2


#include <Arduino.h>
#include <U8g2lib.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#include "Wire.h"


#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif



MPU6050 mpu;
U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);




bool dmpReady = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];



Quaternion q;
VectorFloat gravity;
float ypr[3]; 
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };
volatile bool mpuInterrupt = false;



/*
void dmpDataReady() {
    mpuInterrupt = true;
}
*/




void setup() {
        u8g2.begin();
        u8g2.enableUTF8Print();

        
        Wire.begin();
        Wire.setClock(400000);
        mpu.initialize();  
       // pinMode(INTERRUPT_PIN, INPUT);
        devStatus = mpu.dmpInitialize();
        mpu.setXGyroOffset(220);
        mpu.setYGyroOffset(76);
        mpu.setZGyroOffset(-85);
        mpu.setZAccelOffset(1788);
        mpu.setDMPEnabled(true);
  //      attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();
     //   dmpReady = true;
        packetSize = mpu.dmpGetFIFOPacketSize();
}

void loop() {
      //   mpuInterrupt = false;
         mpuIntStatus = mpu.getIntStatus();
         fifoCount = mpu.getFIFOCount();
         while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
         mpu.getFIFOBytes(fifoBuffer, packetSize);
         fifoCount -= packetSize;




            u8g2.setFont(u8g2_font_unifont_t_chinese1);
            u8g2.setFontDirection(0);
            
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            u8g2.clearBuffer();
            u8g2.setCursor(0, 15);u8g2.print(ypr[0] * 180/M_PI);
           //04 u8g2.setCursor(0, 30);u8g2.print(ypr[1] * 180/M_PI);
           // u8g2.setCursor(0, 45);u8g2.print(ypr[2] * 180/M_PI);
            u8g2.sendBuffer();
        
}
