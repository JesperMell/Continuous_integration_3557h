#include <unity.h>
#include <module.h>

static AsyncWebServer server(3000);
static bool state = false;
static module_t *moduleptr;
/**********************************Setup and teardown********************************* */

void setUp()
{

    //posibly reset fake varables();
}

void tearDown()
{
}

#ifdef WITH_HARDWARE
#else
boolean hello(AsyncWebServer *server)
{
}
boolean goodbye(AsyncWebServer *server) {}
boolean read(char *str) {}
boolean init(AsyncWebServer *) {}
#endif

/* ************************Fake functions without hardware**************************************** */
boolean fake_hello(AsyncWebServer *server)
{
    state = false;
    return state;
}

boolean fake_goodbye(AsyncWebServer *server)
{
    state = false;
    return state;
}
void fake_read(char *str) {}
bool fake_init(AsyncWebServer *server)
{
    state = true;
    return state;
}

/* **********************Fake functions with hardware aka spy functions*********************************** */
bool spy_hello(AsyncWebServer *server)
{
    hello(server);
    return state;
}

bool spy_goodbye(AsyncWebServer *server)
{
    goodbye(server);
    return state;
}
void spy_read(char *str)
{
    read(str);
}
bool spy_init(AsyncWebServer *server)
{

    return state;
}

/* ******************************Test cases********************************** */

void test_hello(void)
{
    TEST_ASSERT_EQUAL_INT(0, moduleptr->module_hello(&server));
}

void test_goodbye(void)
{
    TEST_ASSERT_EQUAL_INT(0, moduleptr->module_goodbye(&server));
}

/* *******************************Running code********************************* */
#ifdef WITH_HARDWARE
void loop()
{
}
void setup()
{
    delay(2000);
#else
int main()
{
#endif

    module_t mod = {
#ifdef WITH_HARDWARE
        //redirect to spy functions (with hardware available)
        .module_hello = spy_hello,
        .module_goodbye = spy_goodbye,
        .module_read = spy_read,
        .module_init = spy_init

#else
        //redirect to fake functions (no hardware available)
        .module_hello = fake_hello,
        .module_goodbye = fake_goodbye,
        .module_read = fake_read,
        .module_init = fake_init
#endif
    };

    moduleptr = &mod;

    UNITY_BEGIN();

    RUN_TEST(test_hello);
    RUN_TEST(test_goodbye);

#ifdef WITH_HARDWARE
    UNITY_END();
#else
    return UNITY_END();
#endif
}
