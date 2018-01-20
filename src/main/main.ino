
int vitesse = 8;
int buzzer =5;

void setup() {
  Serial.begin(115200);
  
  setup_wifi();
  setup_nfc();
  setup_move();
  
  pinMode(buzzer,OUTPUT);
  
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

  //analogWrite(buzzer,300);
  //delay(100);// Attendre 10ms
  //analogWrite(buzzer,0);
  
  Serial.print("Enigme : ");
  Serial.println(getNfcData());
  loop_wifi();
  response = return_response();
  Serial.println(response);
  
  Serial.println("Quitte le NFC");
  while(statusNFC()!=0){
    loop_nfc();
    follow(vitesse);
  }
}
