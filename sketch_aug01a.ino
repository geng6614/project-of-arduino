/*
 * 本程序中所有的方向均以Mega为正的方向
 * 即有mega的一条楞为方向
 * 
*/
int QianHou,ZuoYou;   //这两个值用来辅助判定姿态
#define BigAngle -10
#define SmallAngle 10//调整这两个数值来控制摆动幅度
#define SetServo1 105
#define SetServo2 97
#define SetServo3 83
#define SetServo4 79

#define a 0



#include <Servo.h>

Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4;

int steps[100];
unsigned long time = 0;
    

void setup() {
  Serial.begin(9600);

//初始化四个舵机，设置控制舵机的GPIO
  myservo1.attach(4);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(7);



  //初始化光敏电阻模块的GPIO
  pinMode(21,INPUT);
  pinMode(22,INPUT);
  pinMode(23,INPUT);
  pinMode(24,INPUT);
  pinMode(25,INPUT);
  pinMode(26,INPUT);
  pinMode(27,INPUT);
  pinMode(28,INPUT);
  pinMode(29,INPUT);
  pinMode(30,INPUT);
  pinMode(31,INPUT);
  pinMode(32,INPUT);


   myservo1.write(SetServo1);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4);
  
}
//四项偏移函数，通过倾斜和延时达到小球滚动的目的，具体数值需根据实验中的数据来改变调整

void S_qian(){
//QianHou+=1;
  myservo1.write(SetServo1+BigAngle/2);
    myservo2.write(SetServo2+SmallAngle/2);
    myservo3.write(SetServo3+SmallAngle/2);
    myservo4.write(SetServo4+BigAngle/2);
    delay(10);
  
  }

  void S_hou(){
   // QianHou-=1;
myservo1.write(SetServo1+SmallAngle/2);
    myservo2.write(SetServo2+BigAngle/2);
    myservo3.write(SetServo3+BigAngle/2);
    myservo4.write(SetServo4+SmallAngle/2);
delay(10);
    
    }

    void S_zuo(){
      //ZuoYou+=1;
      myservo1.write(SetServo1+BigAngle/2);
    myservo2.write(SetServo2+BigAngle/2);
    myservo3.write(SetServo3+SmallAngle/2);
    myservo4.write(SetServo4+SmallAngle/2);
delay(10);
      
      }

      void S_you(){
       // ZuoYou-=1;
myservo1.write(SetServo1+SmallAngle/2);
    myservo2.write(SetServo2+SmallAngle/2);
    myservo3.write(SetServo3+BigAngle/2);
    myservo4.write(SetServo4+BigAngle/2);
delay(10);
        
        }

void qian() {//向前偏移函数
  QianHou+=1;
    //提高1，4舵机
#if a
    myservo1.write((SetServo1+SmallAngle)/2);
    myservo2.write((SetServo2-BigAngle)/2);
    myservo3.write((SetServo3-BigAngle)/2);
    myservo4.write((SetServo4+SmallAngle)/2);
    delay(3);
  #endif  
    myservo1.write(SetServo1+SmallAngle);
    myservo2.write(SetServo2+BigAngle);
    myservo3.write(SetServo3+BigAngle);
    myservo4.write(SetServo4+SmallAngle);
    delay(12);  //delay函数用于控制平板倾斜的作用效果

    //回复“水平状态”
    myservo1.write(SetServo1);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4);// tell servo to go to position in variable 'pos'
    //delay(50); // waits 15ms for the servo to reach the position

    /*
    myservo1.write(100);
    myservo2.write(80);
    myservo3.write(80);
    myservo4.write(100);// tell servo to go to position in variable 'pos'
    delay(300);  

    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);// tell servo to go to position in variable 'pos'
    delay(300);  */
 
 }

void hou(){//向后偏移函数
  QianHou-=1;

  #if a
    myservo1.write(SetServo1+BigAngle/2);
    myservo2.write(SetServo2+SmallAngle/2);
    myservo3.write(SetServo3+SmallAngle/2);
    myservo4.write(SetServo4+BigAngle/2);
delay(3);
#endif

  //提高2，3舵机
    myservo1.write(SetServo1+BigAngle);
    myservo2.write(SetServo2+SmallAngle);
    myservo3.write(SetServo3+SmallAngle);
    myservo4.write(SetServo4+BigAngle);// tell servo to go to position in variable 'pos'
    delay(12);  

    //回复“水平状态”
    myservo1.write(SetServo1);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4);// tell servo to go to position in variable 'pos'
    //delay(50); // waits 15ms for the servo to reach the position

    /*
    myservo1.write(80);
    myservo2.write(100);
    myservo3.write(100);
    myservo4.write(80);// tell servo to go to position in variable 'pos'
    delay(300);  

    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);// tell servo to go to position in variable 'pos'
    delay(300);  */
  }


void zuo(){//向左偏移函数
ZuoYou+=1;

#if a
     myservo1.write(SetServo1+BigAngle/2);
    myservo2.write(SetServo2+BigAngle/2);
    myservo3.write(SetServo3+SmallAngle/2);
    myservo4.write(SetServo4+SmallAngle/2);
delay(3);

#endif
  
      //提高1，2舵机
    myservo1.write(SetServo1+BigAngle);
    myservo2.write(SetServo2+BigAngle);
    myservo3.write(SetServo3+SmallAngle);
    myservo4.write(SetServo4+SmallAngle);// tell servo to go to position in variable 'pos'
    delay(12);  

    //回复“水平状态”
    myservo1.write(SetServo1);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4);// tell servo to go to position in variable 'pos'
   // delay(50); // waits 15ms for the servo to reach the position

    /*
    myservo1.write(80);
    myservo2.write(80);
    myservo3.write(100);
    myservo4.write(100);// tell servo to go to position in variable 'pos'
    delay(300);  

    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);// tell servo to go to position in variable 'pos'
    delay(300);  */
  
  }


  void you(){//向右偏移函数
ZuoYou-=1;
#if a
    myservo1.write(SetServo1+SmallAngle/2);
    myservo2.write(SetServo2+SmallAngle/2);
    myservo3.write(SetServo3+BigAngle/2);
    myservo4.write(SetServo4+BigAngle/2);
delay(3);

#endif

    //提高3，4舵机
    myservo1.write(SetServo1+SmallAngle);
    myservo2.write(SetServo2+SmallAngle);
    myservo3.write(SetServo3+BigAngle);
    myservo4.write(SetServo4+BigAngle);// tell servo to go to position in variable 'pos'
    delay(12);  
 
    //回复“水平状态”
    myservo1.write(SetServo1);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4);// tell servo to go to position in variable 'pos'
  //  delay(50); // waits 15ms for the servo to reach the position

    /*
    myservo1.write(100);
    myservo2.write(100);
    myservo3.write(80);
    myservo4.write(80);// tell servo to go to position in variable 'pos'
    delay(300);  

    myservo1.write(90);
    myservo2.write(90);
    myservo3.write(90);
    myservo4.write(90);// tell servo to go to position in variable 'pos'
    delay(300);  */
    
    }




void balance_2(){//先针对基本部分第一题得到一函数
  #if 1
  if(digitalRead(23==1))you();
  if((digitalRead(24) == 1))zuo();
   if((digitalRead(29) == 1))hou();
   if((digitalRead(30) == 1))qian();
#endif

  
  #if 0
  //遮蔽激光即运行上面四种微调函数
  if((digitalRead(23) == 1)&&(ZuoYou<-5))S_you();
  if((digitalRead(23) == 1)&&(ZuoYou>=-5))you();
  if((digitalRead(24) == 1)&&(ZuoYou>5))S_zuo();
  if((digitalRead(24) == 1)&&(ZuoYou<=5))zuo();
  if((digitalRead(29) == 1)&&(QianHou<-5))S_hou();
  if((digitalRead(29) == 1)&&(QianHou>=-5))hou();
  if((digitalRead(30) == 1)&&(QianHou>5))S_qian();
  if((digitalRead(30) == 1)&&(QianHou<=5))qian();
  
  #endif
  if((digitalRead(23) == 1)&&(digitalRead(29) == 1))


  
  {
#if a
myservo1.write(SetServo1);
    myservo2.write(SetServo2+SmallAngle/2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4+BigAngle/2);
delay(3);
#endif
       myservo1.write(SetServo1);
       myservo2.write(SetServo2+SmallAngle);
       myservo3.write(SetServo3);
       myservo4.write(SetServo4+BigAngle);
    delay(12);
    }

    if((digitalRead(24) == 1)&&(digitalRead(29) == 1))
    {
#if a
myservo1.write(SetServo1+BigAngle/2);
    myservo2.write(SetServo2);
    myservo3.write(SetServo3+SmallAngle/2);
    myservo4.write(SetServo4);
delay(3);
#endif
        myservo1.write(SetServo1+BigAngle);
        myservo2.write(SetServo2);
        myservo3.write(SetServo3+SmallAngle);
        myservo4.write(SetServo4);
      delay(12);
      }
       if((digitalRead(23) == 1)&&(digitalRead(30) == 1))
    {
#if a
myservo1.write(SetServo1+SmallAngle/2);
myservo2.write(SetServo2);
    myservo3.write(SetServo3+BigAngle/2);
    myservo4.write(SetServo4);
delay(3);
 #endif     
        myservo1.write(SetServo1+SmallAngle);
        myservo2.write(SetServo2);
        myservo3.write(SetServo3+BigAngle);
        myservo4.write(SetServo4);
      delay(12);
      }
       if((digitalRead(24) == 1)&&(digitalRead(30) == 1))
    {
#if a
myservo1.write(SetServo1);
    myservo2.write(SetServo2+BigAngle/2);
    myservo3.write(SetServo3);
    myservo4.write(SetServo4+SmallAngle/2);
delay(3);
#endif
        myservo1.write(SetServo1);
        myservo2.write(SetServo2+BigAngle);
        myservo3.write(SetServo3);
        myservo4.write(SetServo4+SmallAngle);
      delay(12);
      }

}
#if 0     //预处理时记得调整此项
    void balance(){//balance函数不一定非要只有一个，根据不同要求，我们可以定义多个平衡时间不一样的balance系列函数
  
  
  }//用于保持平衡


  void left(){//向左过线
  
    //先给一个倾斜
    balance();//缓冲过程，不知是否必要！
    //将第一步做的倾斜回正

    }

  void right(){
    
    
    }//向右过线

    void up(){
      
      
      }//向上过线


  void down(){
    
    
    }//向下过线


    void JB2(){//基本要求（2）
      
      right();
      down();
      right();
      balance();
      
      }
      void JB3(){//基本要求（3）
        
        right();
        right();
        balance();
        right();
        down();
        right();
        balance();
        
        }

        void JB4(){//基本要求（4）

          right();
          down();
          down();
          down();
          right();
          right();
          right();
          down();
          balance();
          
          }

          void FH1(){//发挥部分（1）
            
            right();
            right();
            //balance();
            right();
            down();
            down();
            right();
            down();
            down();
            
            }

            void FH2(){//发挥部分（2）
              
              //记得拉高控制器的电平变化模式，修改代码！！INPUT_PULLUP以稳定电平值

              if(digitalRead(FH2startPin)==0){//将不同数字放到数组中，已达到使仪器按照步骤执行走路程序的目的
                //读到0的时候为按下状态
                for(i=0;i<=100;i++)
                {
                  if(state[i] == 1)up();
                  if(state[i] == 2)down();
                  if(state[i] == 3)left();
                  if(state[i] == 4)right;
                  }
                }
              
              if(digitalRead(FH2startPin)==1){
                
                //读到1的时候为未按下状态
                 //读取到高电平时为开关联通状态
                 if(digitalRead(upPin==1))state[i]=1;
                 if(digitalRead(downPin==1))state[i]=2;
                 if(digitalRead(leftPin==1))state[i]=3;
                 if(digitalRead(rightPin==1))state[i]=4;
        
                
                }
                  i++;
              }

              void FH3(){//发挥部分（3）
                
                right();
                for(i=0;i<3;i++)//绕圈
                {
                down();
                right();
                right();
                up();
                up();
                left();
                left();
                down();
                }
                down();
                right();
                right();
                down();
                right();
                balance;
                }


              void FH4(){//发挥部分（4）
                
                //预留
                }


                void Interrupt()
                {
                  if ((micros() - time) > 100); //防止中断程序导致硬件部分问题
                  
                  }
  
  
}


#endif


void loop(){//测试时我用了if（0）；
  if(0)//需要改加限定条件
  qian();
  
  if(0)
  hou();
  
  if(0)
  zuo();

  if(0)
  you();

  if(1)
  balance_2();
  Serial.print(digitalRead(21));
  }

