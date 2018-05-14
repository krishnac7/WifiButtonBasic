
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "YOUR SSID";
const char* password = "YOUR PASSWORD";
const char* mqtt_server = "iot.eclipse.org";
WiFiClient espClient;
PubSubClient client(espClient);
void setup_wifi() {
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  
}

void reconnect() { 
  // Loop until we're reconnected
  while (!client.connected()) {
    String clientId = "ESP8266Client";
//    clientId += String(77, HEX);
    if (client.connect(clientId.c_str())) {
      client.publish("project_KlicK", "clicker01 triggered"); //(mqtt topic,message) 
      Serial.println("Published click trigger");
    } else {
      delay(500);
    }
  }
}
void setup() {
  setup_wifi();
  client.setServer(mqtt_server, 1883);
 
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
ESP.deepSleep(0); 
  }
