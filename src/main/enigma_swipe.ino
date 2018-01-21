const int buttonPin = 2;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup_swipe()
{
  pinMode(buttonPin, INPUT);

}

String swipe(String enonce) {
  String retourner = "";
  retourner.concat(enonce);

  setup_swipe();

  int NbToDo;
  int compteur = 0;

  NbToDo = enonce.toInt();
  Serial.println(NbToDo);

  while (compteur < 6)
  {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) {
      compteur++;
      Serial.println(compteur);
    }
  }
  return retourner;
}

