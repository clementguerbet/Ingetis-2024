#include <ESP8266WiFi.h>

const char* ssid = "never gonna give you up";
const char* password = "randompwd";

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(100);

  Serial.println();
  Serial.print("Connexion au réseau ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Connexion au WiFi établie");
  Serial.print("Addresse IP: ");
  Serial.println(WiFi.localIP());
}


void loop() {
 if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connexion WiFi active.");
  } else {
    Serial.println("Connexion WiFi perdue");
  }


  delay(1000);
}