void victory(){
  /* Never returning function ? */
  while(1){
    Serial.println("We are the champions... my frieeends, but will keep on fighting 'till the end...");
  digitalWrite(A2, HIGH);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, HIGH);
   tone(PIN_BUZZER, 182, 167);
   delay(107);
   digitalWrite(A1, LOW);
    tone(PIN_BUZZER, 370, 167);
     delay(15);
     digitalWrite(A2, LOW);
    tone(PIN_BUZZER, 404, 167);
     delay(200);
    tone(PIN_BUZZER, 340, 167);
    digitalWrite(A3, LOW);
     delay(107);
    tone(PIN_BUZZER, 172, 167);
  }
}
