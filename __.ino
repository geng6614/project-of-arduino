#define upPin 0
#define downPin 0
#define leftPin 0
#define rightPin 0
#define FH2startPin 0


#define InterruptPin 0


int state[100];
int i=0;
unsigned long time = 0;

void setup() {
  // put your setup code here, to run once:
time=micros();
}

void loop() {
  // put your main code here, to run repeatedly:

}


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
