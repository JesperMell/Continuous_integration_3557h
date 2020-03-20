#include <module.h>

extern const int pin;

boolean hello(AsyncWebServer *server)
{
  server->on("/hello", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning on the light");
    
    digitalWrite(pin, HIGH);
  });
  boolean check_hello = digitalRead(pin);
  return check_hello;
}

boolean goodbye(AsyncWebServer *server)
{
  server->on("/goodbye", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", "Turning off the light");
    digitalWrite(pin, LOW);
  });
  boolean check_goodbye = !digitalRead(pin);
  return check_goodbye;
}