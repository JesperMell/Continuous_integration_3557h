#ifndef MODULE_H_
#define MODULE_H_

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef bool boolean;

class AsyncWebServer
{
protected:
public:
    AsyncWebServer(uint16_t port)
    {
    }

    void begin();
    void end();
};

/* **************************************************************** */

bool hello(AsyncWebServer *server);

bool goodbye(AsyncWebServer *server);

/* **************************************************************** */

#endif