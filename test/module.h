#ifndef MODULE_H_
#define MODULE_H_

#include <WiFi.h>
#include <Arduino.h>
#include <ESPAsyncWebServer.h>

/* **************************************************************** */

boolean hello(AsyncWebServer *server);

boolean goodbye(AsyncWebServer *server);

/* **************************************************************** */

#endif