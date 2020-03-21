#include <unity.h>
#include <module.h>

extern const int pin = 13;
static AsyncWebServer server(3000);
static bool state = false;

/**********************************Setup and teardown********************************* */

void setUp()
{

    //posibly reset fake varables();
}

void tearDown()
{
}
/* ************************Fake functions without hardware**************************************** */
#ifdef WITH_HARDWARE
boolean hello(AsyncWebServer *server)
{
}

boolean goodbye(AsyncWebServer *server)
{
    state = false;
    return state;
}

#else
/* **********************Fake functions with hardware *********************************** */
bool hello(AsyncWebServer *server)
{
    state = true;
    return state;
}

bool goodbye(AsyncWebServer *server)
{
    state = false;
    return state;
}

#endif
/* ******************************Test cases********************************** */

void test_hello(void)
{
    TEST_ASSERT_EQUAL_INT(1, hello(&server));
}

void test_goodbye(void)
{
    TEST_ASSERT_EQUAL_INT(0, goodbye(&server));
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

#ifdef WITH_HARDWARE
//rikta om till spionfunktioner om vi vill
#else
//rikta om till fakefunktioner
#endif

    UNITY_BEGIN();

    RUN_TEST(test_hello);
    RUN_TEST(test_goodbye);

#ifdef WITH_HARDWARE
    UNITY_END();
#else
    return UNITY_END();
#endif
}
