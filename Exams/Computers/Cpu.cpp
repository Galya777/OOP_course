#include "Cpu.h"

Cpu::Cpu(int core, double frequency)
{
    this->core = core;
    this->frequency = frequency;
}

Cpu::Cpu()
{
    core = 0;
    frequency = 0;
}

const int Cpu::getCore() 
{
    return core;
}

const double Cpu::getFrequency() 
{
    return frequency;
}

std::ifstream& operator>>(std::ifstream& is, Cpu& cpu)
{
    is >> cpu.core >> cpu.frequency;
    return is;
}
