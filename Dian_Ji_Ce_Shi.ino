void setup()
{
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}
 
void loop() {
  static int i = 0;
while(i == 0)
{

  i++;
  digitalWrite(8,1);
  digitalWrite(9,0);
  digitalWrite(10,1);
  digitalWrite(11,0);
  delay(2333);
    digitalWrite(8,0);
  digitalWrite(9,0);
  digitalWrite(10,0);
  digitalWrite(11,0);
  
}
}
