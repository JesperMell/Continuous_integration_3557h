#include <module.h>

/* **************************************************************** */

boolean check_hello = false;
boolean check_goodbye = false;
AsyncWebServer server(3000);
static boolean initstate = false;

void setup()
{
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
  delay(3000);

  hello(&server);
  goodbye(&server);

  if (!initstate)
  {
    initstate = init(&server);
  }
  Serial.println(WiFi.localIP());
}

void loop()
{
}
