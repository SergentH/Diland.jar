#include <Servo.h> 
Servo servoG;
Servo servoD;

void setup_move(){
  servoG.attach(6,900,2100);
  servoD.attach(5,900,2100);
}


void move(int vitG, int vitD){
  double cmdG = vitG*1200/200+1500;
  double cmdD = -vitD*1200/200+1500;
  servoG.write(cmdG);
  servoD.write(cmdD);
}

void rotate(int angle){
  
}





