#include <Servo.h>

Servo monServo;
int angle = 1500;
char reception;

void setup()
{
  monServo.writeMicroseconds(angle);  
  monServo.attach(9);
  Serial.begin(9600);
}


void loop()
{
  monServo.writeMicroseconds(angle);
  if(Serial.available()>0){
    reception=Serial.read();
    switch(reception){
      case 'a':
      angle = angle +10;
      break;
      case 'z':
      angle = angle - 10;
      break;
      case 'e':
      angle = angle + 1;
      break;
      case 'r':
      angle = angle - 1;
      break;
    }
  }
}
