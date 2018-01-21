#include <Servo.h> 
Servo servoG;
Servo servoD;

int suivG = 1;
int suivD = 0;
void setup_move(){
  servoG.attach(6,900,2100);
  servoD.attach(5,900,2100);
  pinMode(suivG,INPUT);
  pinMode(suivD,INPUT);
  move(0,0);
}

void move(int vitG, int vitD){
  double cmdG = vitG*1200/200+1500;
  double cmdD = -vitD*1200/200+1500;
  servoG.write(cmdG);
  servoD.write(cmdD);
}

void stop(){
  move(0,0);
}

boolean ligneG(){
  int detG = digitalRead(suivG);
  //Serial.print("Gauche :");
  //Serial.println(detG, DEC);
  return detG;
}

boolean ligneD(){
    int detD = digitalRead(suivD);
  //Serial.print("Doite :");
  //Serial.println(detD, DEC);
  return detD;
}

void follow(int vitesse){
  //int delta = vitesse*(compensation/100);
  int vitG = vitesse;
  int vitD = vitesse;
  
  if(ligneG()){
    vitG=-vitesse*1.3;
    vitD=vitesse;
  } 
  
  if(ligneD()){
    vitG=vitesse*1.3;
    vitD=-vitesse;
  }

  if(ligneG() and ligneD()){
    vitG=0;
    vitD=0;
  }
  move(vitG,vitD);
}

void rot90(int sens){
  if(sens==0){//gauche
    move(-8,8);
    delay(1000);
    stop();
  }else{
    move(8,-8);
    delay(1000);
    stop();
  }
}






