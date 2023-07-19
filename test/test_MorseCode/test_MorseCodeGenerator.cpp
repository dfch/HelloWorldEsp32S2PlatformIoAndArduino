/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <Arduino.h>
#include <unity.h>
#include <memory>

#include "MorseCode/MorseCodeGeneratorConfiguration.h"
#include "MorseCode/MorseCodeSignal.h"
#include "MorseCode/MorseCodeGenerator.h"

void setUp(void)
{
  Serial.begin(115200);
}

void tearDown(void)
{
    Serial.end();
}

void test_SerialiseReturnsCorrectVectorLength(void)
{
    // Arrange
    auto configuration = std::make_shared<MorseCodeGeneratorConfiguration>();
    configuration->Transmit = [](int ms) { return; };
    configuration->NoTransmit = [](int ms) { return; };
    configuration->DitLengthMs = 1;

    std::string message = "sos";

    auto sut = std::make_shared<MorseCodeGenerator>(configuration);

    // Act
    auto result = sut->Serialise(message);

    // Assert
    TEST_ASSERT_EQUAL(3+3 + 3+3 + 3+3 +4, result.size());
}

void setup()
{
    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);


    UNITY_BEGIN(); // IMPORTANT LINE!

    RUN_TEST(test_SerialiseReturnsCorrectVectorLength);

    UNITY_END(); // stop unit testing
}

void loop()
{
    throw;
}