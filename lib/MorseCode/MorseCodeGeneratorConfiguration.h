/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#pragma once

#include <functional>
#include <memory>

class MorseCodeGeneratorConfiguration
{
    public:
        const unsigned short DitLengthMsDefault = 150;

        unsigned short DitLengthMs = DitLengthMsDefault;

        std::function<void(int ms)> Transmit = [](int ms) { return; };
        std::function<void(int ms)> NoTransmit = [](int ms) { return; };
};
