/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <unity.h>

#include <MorseCodeGenerator.h>

void setUp(void)
{
    // N/A
}

void tearDown(void)
{
    // N/A
}

void SerialiseReturnsCorrectVectorLength(void)
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
    TEST_ASSERT_EQUAL(3+1 + 3+1 + 3+1 +1, result.size());
}

void SerialiseReturnsCorrectVectorContent(void)
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
    TEST_ASSERT_EQUAL(Dit, result[0]);
    TEST_ASSERT_EQUAL(Dit, result[1]);
    TEST_ASSERT_EQUAL(Dit, result[2]);
    
    TEST_ASSERT_EQUAL(Char, result[3]);

    TEST_ASSERT_EQUAL(Dah, result[4]);
    TEST_ASSERT_EQUAL(Dah, result[5]);
    TEST_ASSERT_EQUAL(Dah, result[6]);

    TEST_ASSERT_EQUAL(Char, result[7]);

    TEST_ASSERT_EQUAL(Dit, result[8]);
    TEST_ASSERT_EQUAL(Dit, result[9]);
    TEST_ASSERT_EQUAL(Dit, result[10]);
    
    TEST_ASSERT_EQUAL(Char, result[11]);

    TEST_ASSERT_EQUAL(Word, result[12]);
}

int runUnityTests(void)
{
    UNITY_BEGIN();

    RUN_TEST(SerialiseReturnsCorrectVectorLength);
    RUN_TEST(SerialiseReturnsCorrectVectorContent);

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
