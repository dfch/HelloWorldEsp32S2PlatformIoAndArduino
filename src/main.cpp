/**
* Copyright (c) Ronald Rink
* See LICENSE file in the project root for full license information.
*/

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
