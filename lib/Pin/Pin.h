/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#include <Arduino.h>

class Pin
{
    private:
        const uint8_t mode;
        const uint8_t number;

    public:
        Pin(const uint8_t value, const uint8_t mode);

        void Set(bool flag);
        bool Get();
};
