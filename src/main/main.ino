//#include <WiFi.h>
#include <WiFiUdp.h>
//#include <SPI.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE};
IPAddress ip(192, 168, 40, 101);
unsigned int localPort = 5000;
char pcktBuffer[UDP_TX_PACKET_MAX_SIZE];
String datReq;
int packetSize;
WiFiUDP udp;

int vitesse = 8;
int PIN_BUZZER =A5;

void loop_eth(){
  packetSize = udp.parsePacket();
  if(packetSize > 0){
    udp.read(pcktBuffer, UDP_TX_PACKET_MAX_SIZE);
    String datReq(pcktBuffer);

    Serial.println("Received " + datReq);
  }
  memset(pcktBuffer, 0, UDP_TX_PACKET_MAX_SIZE);
}

void setup() {
  Serial.begin(115200);
  
  setup_wifi();
  setup_nfc();
  setup_move();
  
  pinMode(PIN_BUZZER,OUTPUT);
  udp.beginPacket(udp.remoteIP(), udp.remotePort());
  udp.print("Yo");
  udp.endPacket();
}

String response;

void loop() {
  loop_eth();
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
  
  send_message(parsing(getNfcData()));

  //waitResponseServer();

  Serial.println("Quitte le NFC");
  while(statusNFC()!=0){
    loop_nfc();
    follow(vitesse);
  }
}
