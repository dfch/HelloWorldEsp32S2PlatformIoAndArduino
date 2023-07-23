/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <unity.h>
#include <memory>

#include <MorseCodeGenerator.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_SerialiseReturnsCorrectVectorLength(void)
{
    // Arrange
    auto configuration = std::make_shared<MorseCodeGeneratorConfiguration>();
    configuration->Transmit = [](int ms) { return; };
    configuration->NoTransmit = [](int ms) { return; };

    std::string message = "sos";

    auto sut = std::make_shared<MorseCodeGenerator>(configuration);

    // Act
    auto result = sut->Serialise(message);

    // Assert
    TEST_ASSERT_EQUAL(3+3 + 3+3 + 3+3 +4, result.size());
}

void setup()
{
    UNITY_BEGIN(); // IMPORTANT LINE!

    RUN_TEST(test_SerialiseReturnsCorrectVectorLength);

    UNITY_END(); // stop unit testing
}

void loop()
{
    throw;
}