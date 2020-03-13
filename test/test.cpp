#include <unity.h>

void setUp()
{
}
void tearDown()
{
}
void test_123hejhej(void)
{
    TEST_ASSERT_EQUAL_UINT8(1, 1);
    TEST_ASSERT_EQUAL_UINT8(0, 0);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_123hejhej);
    UNITY_END();

    return 0;
}