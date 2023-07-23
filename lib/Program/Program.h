/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

#pragma once

#include <Arduino.h>

#include <MorseCodeGenerator.h>

class Program
{
    private:
        std::shared_ptr<MorseCodeGenerator> generator;
        std::string message = "Hello, world!";

    public:
        Program();

        virtual void Invoke();
    
    class Factory
    {
        public:
            static std::shared_ptr<Program> Create();
    };
};