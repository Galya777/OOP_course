
#include "Ram.h"

Ram::Ram(int gygabites, int cips, int colors)
{
    this->gygabites = gygabites;
    this->cips = cips;
    this->colors = colors;
}

Ram::Ram()
{
    gygabites = 0;
    cips = 0;
    colors = 0;
}

const int Ram::getGygabites()
{
    return gygabites;
}

const int Ram::getCips() 
{
    return cips;
}

const int Ram::getColors()
{
    return colors;
}

std::ifstream& operator>>(std::ifstream& is, Ram& ram)
{
    is >> ram.gygabites >> ram.cips >> ram.colors;
    return is;
}
