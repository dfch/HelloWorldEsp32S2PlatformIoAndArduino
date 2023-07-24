/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#if defined(ARDUINO)

#include "Pin.h"

Pin::Pin(const uint8_t number, const uint8_t mode)
    : number(number), mode(mode)
{
    pinMode(number, mode);
}

void Pin::Set(bool flag)
{
    digitalWrite(number, flag ? HIGH : LOW);
}

bool Pin::Get()
{
    return HIGH == digitalRead(number) ? true : false;
}

#endif
