// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status


String swipe(String enonce) {


  int NbToDo;
  int compteur = 0;

  NbToDo = enonce.toInt();
  Serial.println(NbToDo);

  while (compteur < 5)
  {
    // read the state of the pushbutton value:
    buttonState = digitalRead(BTN2);
    if (buttonState == LOW) {
      compteur++;
        tone(PIN_BUZZER, 370, 167);
        delay(187);
        tone(PIN_BUZZER, 392, 167);
      Serial.println(compteur);
    }

    delay(200);
  }
  return enonce;
}

