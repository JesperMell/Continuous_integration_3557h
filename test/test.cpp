#include <unity.h>
#include <module.h>
#include <Arduino.h>

/* **************************************************************** */

boolean hello(AsyncWebServer *server) {
    return true;
}

boolean goodbye(AsyncWebServer *server) {
    return false;
}

/* **************************************************************** */

AsyncWebServer server(3000);

void test_hello(void) {
    TEST_ASSERT_EQUAL_INT(1, hello(&server));
}

void test_goodbye(void) {
    TEST_ASSERT_EQUAL_INT(0, goodbye(&server));
}

/* **************************************************************** */

void setup() {

    delay(2000);

    UNITY_BEGIN(); 

    RUN_TEST(test_hello);
    delay(500);

    RUN_TEST(test_goodbye);
    delay(500);

    UNITY_END();

}

void loop() {
 
}