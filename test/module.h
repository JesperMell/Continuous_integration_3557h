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

typedef struct
{
    boolean (*module_hello)(AsyncWebServer *);
    boolean (*module_goodbye)(AsyncWebServer *);
    void (*module_read)(char *);
    boolean (*module_init)(AsyncWebServer *);

} module_t;

/* **************************************************************** */

boolean hello(AsyncWebServer *server);
boolean goodbye(AsyncWebServer *server);
boolean read(char *str);
boolean init(AsyncWebServer *);

/* **************************************************************** */

#endif