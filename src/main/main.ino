
int vitesse = 8;
int PIN_BUZZER =A5;
int BTN1 = A1;
int BTN2 = 2;

void setup() {
  Serial.begin(115200);
  
  setup_wifi();
  setup_nfc();
  setup_move();
  setup_magnetometre();
  
  tone(PIN_BUZZER, 370, 167);
  delay(187);
  tone(PIN_BUZZER, 392, 167);
  
  pinMode(PIN_BUZZER,OUTPUT);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN1, INPUT_PULLUP);
  
  while(digitalRead(BTN2) != LOW);
  send_message("A1:Hello 24h du code!");
}

String response;

void loop() {
  
  Serial.println("Avance jusqu'au NFC");
  while(statusNFC()==0){ //Avance jusqu'au NFC
    follow(vitesse);
    loop_nfc();
  }
  stop();
  Serial.println("Lecture NFC");
  while(statusNFC()!=3){ //Attente de lecture
    loop_nfc();
  }

  tone(PIN_BUZZER, 370, 167);
    delay(187);
  tone(PIN_BUZZER, 262, 167);
  
  Serial.print("Enigme : ");
  Serial.println(getNfcData());
  
  send_message(parsing(getNfcData()));
  
  tone(PIN_BUZZER, 392, 167);
  delay(187);
  tone(PIN_BUZZER, 466, 167);
  
  //waitResponseServer();

  Serial.println("Quitte le NFC");
  while(statusNFC()!=0){
    loop_nfc();
    follow(vitesse);
  }
}


