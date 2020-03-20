#include <unity.h>
#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

void setUp()
{
}
void tearDown()
{
}
void test_123hejhej(void)
{
    /*     SSID = linus iphone;
    password = 12345678;
    wificonnect(); */
    TEST_ASSERT_EQUAL_UINT8(WL_CONNECTED(wifi.status())
}

void setup()
{
    delay(1000);
}

void loop(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_123hejhej);

    UNITY_END();
}