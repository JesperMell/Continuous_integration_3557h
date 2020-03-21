#include <module.h>

char ssid[MAXSIZE] = {};
char password[MAXSIZE] = {};
static boolean state = false;

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

void read(char *str)
{
  int i = 0;
  while (i < MAXSIZE)
  {
    if (Serial.available())
    {
      char tmp = Serial.read();
      if (isAlphaNumeric(tmp) || tmp == ' ')
      {
        str[i] = tmp;
        Serial.print(tmp);
        i++;
      }
      else if (tmp == '\b')
      {
        Serial.print("\t Start over: ");

        i = 0;
      }
      else if (tmp == '\n')
      {
        break;
      }
    }
  }
}

bool init(AsyncWebServer *server)
{

  Serial.print("\nEnter ssid: ");
  read(ssid);

  Serial.print("\nEnter password: ");
  read(password);

  WiFi.begin(ssid, password);
  server->begin();
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("\nConnecting to WiFi...");
    state = false;
  }
  state = true;
  return state;
}