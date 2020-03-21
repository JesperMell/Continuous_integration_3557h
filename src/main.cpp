#include <module.h>

/* **************************************************************** */

boolean check_hello = false;
boolean check_goodbye = false;
AsyncWebServer server(3000);
static boolean initstate = false;
static boolean ledstate = false;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  delay(3000);
  if (!initstate)
  {
    initstate = init(&server);
  }
  Serial.println(WiFi.localIP());
}

void loop()
{
  check_hello = hello(&server);
  if ((check_hello == true) && (ledstate == false))
  {
    ledstate = true;
    Serial.println("Turning on the LED");
  }

  check_goodbye = goodbye(&server);
  if ((check_goodbye == true) && (ledstate == true))
  {
    ledstate = false;
    Serial.println("Turning off the LED");
  }
  delay(500);
}
