#include <unity.h>
#include "hello.h"
#include <stdlib.h>
#include <string.h>
char buffer[50];

void setUp(void)
{
}
void tearDown(void)
{
}
void test_printf(void)
{
    /*     buffer = (char *)malloc(sizeof(char) * 12);
    if (buffer == NULL)
    {
        printf("felfelfelfelfel");
        exit - 1;
    } */

    hello(buffer);
    TEST_ASSERT_EQUAL_STRING("Hello World!", buffer);
}

void main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_printf);
    UNITY_END();
}