String ble(String ble){
   move(8,8);//move to middle
   delay(1100);
   stop();
  bool buttonLow = true;
  while(buttonLow) {
    int speed =40;
    int speedRotate=8;
    int delayRotate=1000;
    int potValue = analogRead(A0);
    
    if(potValue < 30){
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
        rot90(0);
        move(8,8);
        buttonLow = false;
      } 
    }
    else if (potValue >=30 && potValue <60){
      digitalWrite(A2, LOW);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, LOW);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
       move(8,8);
       buttonLow = false;
      } 
    }
    else if (potValue >=60 && potValue <90){
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, HIGH);
      if(digitalRead(BTN1) == LOW ||digitalRead(BTN2) == LOW){
         rot90(1);
         move(8,8);
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
  return ble;
}


