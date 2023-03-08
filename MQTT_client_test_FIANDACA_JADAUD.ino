#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Pixel_5969";
const char* password = "azerty1234";
const char* mqtt_server = "test.mosquitto.org";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() { 
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  client.setServer(mqtt_server, 1883);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT server...");
    if (client.connect("ArduinoClient")) {
      Serial.println("Connected to MQTT server");
    } else {
      Serial.print("Failed to connect to MQTT server, rc=");
      Serial.print(client.state());
      delay(1000);
    }
  }

  
}

void loop() {
  client.publish("srt/FJ", "test");
  delay(1000);
}
