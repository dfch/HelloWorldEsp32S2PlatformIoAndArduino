/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

// #ifndef PIO_UNIT_TESTING
// #ifndef ENV_NATIVE

#if defined(ARDUINO)

#include <Program.h>

static std::shared_ptr<Program> program;

void setup() 
{
  program = Program::Factory::Create();
}

void loop() 
{
  program->Invoke();
}

#else

int main(int argc, char **argv) 
{
    return 0;
}

#endif
