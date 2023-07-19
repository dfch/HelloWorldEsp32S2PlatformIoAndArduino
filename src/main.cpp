/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include "main.h"

std::string message = "Hello, world!";
static std::shared_ptr<MorseCodeGenerator> generator;

void setup() 
{
  Serial.begin(115200);

  pinMode(LED_BUILTIN, OUTPUT);

  auto configuration = std::make_shared<MorseCodeGeneratorConfiguration>();
  configuration->Transmit = [](int ms) 
  { 
    digitalWrite(LED_BUILTIN, HIGH); 
    delay(ms);
    digitalWrite(LED_BUILTIN, LOW); 
  };
  configuration->NoTransmit = [](int ms) 
  { 
    digitalWrite(LED_BUILTIN, LOW); 
    delay(ms);
  };

  generator = std::make_shared<MorseCodeGenerator>(configuration);
}

void loop() 
{
  Serial.print(message.c_str());

  generator->Send(message);
}
