#include <SPI.h>
#include <WiFiST.h>
#include <WiFiClientST.h>
#include <PubSubClient.h>

SPIClass SPI_3(PC12, PC11, PC10);
WiFiClass WiFi(&SPI_3, PE0, PE1, PE8, PB13);

WiFiClient ethClient;
char ssid[] = "24HDUCODE";
char pass[] = "2018#24hcode!";
uint8_t http[1024];               // http buffer to send
int status = WL_IDLE_STATUS;


PubSubClient client("24hducode.spc5studio.com", 1883, callback, ethClient);



void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup_wifi()
{
  // Initialize the WiFi device :
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    while (true);          // don't continue
  }
 
  // attempt to connect to Wifi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    // wait 10 seconds for connection:
    delay(10000);
  }
  printWifiStatus();                        // you're connected now, so print out the status

  Serial.print("Wifi ok");

  if (client.connect("teamF")) {
    Serial.print("tentative d'envoi");
    client.publish("24hcode/teamF/284k0/device2broker","Hello from Aspicot");
    client.subscribe("24hcode/teamF/284k0/broker2device");
  }
}

void loop_wifi()
{
  client.loop();
}



void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}


