#ifndef MODULE_H_
#define MODULE_H_
#define MAXSIZE 100

#include <WiFi.h>
#include <Arduino.h>
#include <ESPAsyncWebServer.h>

const int pin = 13;
/* ************************main functions****************************** */

boolean hello(AsyncWebServer *server);

boolean goodbye(AsyncWebServer *server);

void read(char *str);
bool init(AsyncWebServer *);

/* **********************for testing****************************** */

typedef struct
{
    boolean (*module_hello)(AsyncWebServer *);
    boolean (*module_goodbye)(AsyncWebServer *);
    void (*module_read)(char *);
    boolean (*module_init)(AsyncWebServer *);

} module_t;

#endif