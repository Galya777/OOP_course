#pragma once
#include "HotelMaker.h"
class Interface
{
public:
    /**
     * @brief print to stdout centered name of the Hotel
     *
     * @param H Hotel whose name is to be printed
     */
    static void createHeader(HotelMaker& H);

    /**
     * @brief print the today's date and available commands to use for a Hotel
     *
     */
    static void beginDay();
};

