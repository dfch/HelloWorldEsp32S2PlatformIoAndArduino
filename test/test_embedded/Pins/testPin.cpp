/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <unity.h>
#include <Arduino.h>

#include <Pin.h>

void setUp(void)
{
    // N/A
    Serial.begin(115200);
}

void tearDown(void)
{
    // N/A
}

void SettingBuiltinLedToHighSucceeds(void)
{
    // Arrange
    auto expected = false;
    auto sut = new Pin(LED_BUILTIN, OUTPUT);

    // Act
    sut->Set(true);

    auto result = sut->Get();

    // Assert
    TEST_ASSERT_EQUAL(true, result);
}

void SettingBuiltinLedToLowSucceeds(void)
{
    // Arrange
    auto expected = true;
    auto sut = new Pin(LED_BUILTIN, OUTPUT);

    // Act
    sut->Set(true);

    auto result = sut->Get();

    // Assert
    TEST_ASSERT_EQUAL(true, result);
}

int runUnityTests(void)
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);
    
    UNITY_BEGIN();

    RUN_TEST(SettingBuiltinLedToHighSucceeds);
    RUN_TEST(SettingBuiltinLedToLowSucceeds);

    return UNITY_END();
}

void setup()
{
    runUnityTests();
}

void loop()
{
    // N/A
}

void app_main() 
{
  runUnityTests();
}

int main(int argc, char **argv)
{
    return runUnityTests();
}
