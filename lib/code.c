// code.cpp

#include "C:/Users/helena/Documents/PlatformIO/inlämningsuppgifter/Continuous_integration_3557h/lib/header.h"

boolean hello()
{
  server.on("/turn_on", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning on the light");
    Serial.println("Turning on the LED");
    digitalWrite(pin, HIGH);
  });
  boolean check = digitalRead(pin);
  return check;
}

boolean goodbye()
{
  server.on("/goodbye", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning off the light");
    Serial.println("Turning off the LED");
    digitalWrite(pin, LOW);
  });
  boolean check = !digitalRead(pin);
  return check;
}
