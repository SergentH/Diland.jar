
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setup_nfc();
  setup_move();
  
}

void loop() {
  while(statusNFC()==0){ //Avance jusqu'au NFC
    follow(10);
    loop_nfc();
  }
  while(statusNFC()!=3){ //Attente de lecture
    loop_nfc();
  }
  Serial.print("Enigme : ");
  Serial.println(getNfcData());
  follow(10);
}


