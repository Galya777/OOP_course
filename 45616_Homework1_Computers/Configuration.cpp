#include "Configuration.h"

ComputerPart Configuration::getPartAt(int index)
{
    return parts[index];
}

int Configuration::getSize() const
{
    return size;
}
