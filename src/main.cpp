// main.cpp

#include "header.h"

extern const char *ssid = "ENTER SSID";
extern const char *password = "ENTER PASSWORD";
extern const int pin = 13;

boolean check = false;
AsyncWebServer server(3000);

void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  pinMode(pin, OUTPUT);
  server.begin();

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println(WiFi.localIP());

  check = hello();

  check = goodbye();

  void loop()
  {
  }