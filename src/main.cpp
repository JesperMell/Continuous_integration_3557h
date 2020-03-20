#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "ENTER SSID";
const char *password = "ENTER PASSWORD";
const int pin = 13;

AsyncWebServer server(3000);

void setup()
{
  Serial.begin(9600);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println(WiFi.localIP());

  digitalWrite(pin, HIGH);

  server.on("/turn_on", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning on the light");
    Serial.println("Turning on the LED");
    digitalWrite(pin, HIGH);
  });

  server.on("/goodbye", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning off the light");
    Serial.println("Turning off the LED");
    digitalWrite(pin, LOW);
  });

  server.begin();
  pinMode(pin, OUTPUT);
}

void loop() {}
