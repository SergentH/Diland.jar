#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

EthernetClient ethClient;
PubSubClient client(ethClient);

char clientID[6] = "teamF";
char BrokerLogin[8] = "Aspicot";
char BrokerPasswd[9];
char CodeTeam[6];
char pubTopic[40] = "24hcode/teamF/XXXXX/device2broker";
char subTopic[40] = "24hcode/teamF/XXXXX/broker2device";


void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}


void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(pubTopic,"hello world");
      // ... and resubscribe
      client.subscribe(subTopic);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup_wifi() {
  
   client.setServer("24hducode.spc5studio.com",1883); 
   client.setCallback(callback);
}


void loop_wifi()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}




