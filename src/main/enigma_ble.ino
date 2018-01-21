String ble(String ble){
   move(8,8);//move to middle
   delay(2000);
   stop();
  bool buttonLow = true;
  while(buttonLow) {
    int speed =40;
    int speedRotate=8;
    int delayRotate=1000;
    int potValue = analogRead(A0);
    
    if(potValue < 10){
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
        rotate90L(speedRotate,delayRotate);
        buttonLow = false;
      } 
    }
    else if (potValue >=10 && potValue <20){
      digitalWrite(A2, LOW);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, LOW);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
       move(70,70);
       buttonLow = false;
      } 
    }
    else if (potValue >=20 && potValue <30){
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, HIGH);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
         rotate90R(speedRotate,delayRotate);
         buttonLow = false;
      } 
    }
    else{   
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
        move(-10,-10);
      }       
    }
  }
}
void rotate90R(int speedRotate, int delayRotate){
  move(speedRotate,-speedRotate);
  delay(delayRotate);
}
void rotate90L(int speedRotate, int delayRotate){
  move(-speedRotate,speedRotate);
  delay(delayRotate);
}


