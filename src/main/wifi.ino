#include <SPI.h>
#include <WiFiST.h>
#include <WiFiClientST.h>
#include <PubSubClient.h>

SPIClass SPI_3(PC12, PC11, PC10);
WiFiClass WiFi(&SPI_3, PE0, PE1, PE8, PB13);

char buf[100];

void callback(char* topic, byte* payload, unsigned int length) {
  
  /*Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");*/
  memset (buf, 0, sizeof (buf));
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
    buf[i]=(char)payload[i];
  }
  Serial.println();
}


char* return_response()
{
  return buf;
}

void clear_response(){
   memset (buf, 0, sizeof (buf));
}


WiFiClient wifiClient;
char ssid[] = "24HDUCODE";
char pass[] = "2018#24hcode!";
PubSubClient client("24hducode.spc5studio.com", 1883, callback, wifiClient);

void setup_wifi()
{
  // Initialize the WiFi device :
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);          // don't continue
  }

 WiFi.begin(ssid, pass);
  // attempt to connect to Wifi network:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.print("Wifi ok :");
  Serial.println(WiFi.localIP());
  
  
  if (client.connect("teamF","Aspicot", "G9375V72")) {
    Serial.println("Connected to MQTT broker");

    /*
    if (client.publish("24hcode/teamF/284k0/device2broker","Hello from Aspicot")) {
      Serial.println("Publish ok");
    }
    else {
      Serial.println("Publish failed");
    }
    */
    
    if(client.subscribe("24hcode/teamF/284k0/broker2device")) {
      Serial.println("Subscribe ok");
    }
    else {
      Serial.println("Subscribe failed");
    }
    
  }
  else {
    Serial.println("MQTT connect failed");
    Serial.println("Will reset and try again...");
    abort();
  }
}


void send_message(const char* message)
{
  while(client.publish("24hcode/teamF/284k0/device2broker",message)==0) {
      Serial.println("Publish failed");
  }
  Serial.println("Publish Ok");
}

void waitResponseServer(){
  Serial.print("Réponce serveur : ");
  while(response!="OK"){
    loop_wifi();
    response = return_response();
  }
  Serial.println(response);
  clear_response();
  response="null";
}


void loop_wifi(){
  
  client.loop();
    
}

