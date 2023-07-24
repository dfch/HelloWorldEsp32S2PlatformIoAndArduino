/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#if defined(ARDUINO)

#include "Program.h"

Program::Program()
{
    Serial.begin(115200);

    pinMode(LED_BUILTIN, OUTPUT);

    auto configuration = std::make_shared<MorseCodeGeneratorConfiguration>();
    auto flag = false;
    configuration->Transmit = [flag](int ms)
    { 
        if(!flag) digitalWrite(LED_BUILTIN, HIGH); 
        delay(ms);
        digitalWrite(LED_BUILTIN, LOW); 
    };
    configuration->NoTransmit = [flag](int ms) mutable
    { 
        if(flag) digitalWrite(LED_BUILTIN, LOW); 
        delay(ms);
        flag = false;
    };

    generator = std::make_shared<MorseCodeGenerator>(configuration);
}

void Program::Invoke()
{
    #if defined(ARDUINO)
        while(true)
        {
    #endif

        Serial.println(message.c_str());
        
        generator->Send(message);

    #if defined(ARDUINO)
        }
    #endif
}

std::shared_ptr<Program> Program::Factory::Create()
{
    return std::make_shared<Program>();
}

#endif
