#include <module.h>

/* **************************************************************** */

const char *ssid = "PrivacyMi";
const char *password = "test12345";
extern const int pin = 13;
boolean check_hello = false;
boolean check_goodbye = false;

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

  check_hello = hello(&server);
  if (check_hello == true)
  {
    Serial.println("Turning on the LED");
  }

  check_goodbye = goodbye(&server);
  if (check_goodbye == true)
  {
    Serial.println("Turning off the LED");
  }
}

void loop()
{
}