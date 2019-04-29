#include <SoftwareSerial.h>
 
SoftwareSerial serial2(6,7);//SoftwareSerial serial2(RX,TX);两机RX与TX应交叉相连
 
void setup() {
  serial2.begin(115200);//使用AT模式时把波特率调成38400.
}
 
void loop() {
  if(serial2.available())
    if （serial2.read() == 233）//此时是左转
    {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);
      }
      if （serial2.read() == 666）//此时是右转
    {
      digitalWrite(8,LOW);
      digitalWrite(9,HIGH);
      }
}
