#pragma once
#include "Building.h"
class Analizer: public Building
{
    /**
     * @brief sort the Rooms in a HotelBuilding based on some score
     *
     * @param hB HotelBuilding
     * @param score array of points for each Room
     * @param from beginning of the array
     * @param to end of the array
     */
    static void sortRoomsByScore(Building& hB, unsigned* score, size_t from, size_t to);

    /**
     * @brief sort the Rooms in a HotelBuilding based on their number
     *
     * @param hB HotelBuilding
     * @param from beginning of the array
     * @param to end of the array
     */
    static void sortRoomsByNumber(Building& hB, size_t from, size_t size);

    /**
     * @brief template for swapping values of two elements
     *
     * @tparam T typename of swapped objects/variables
     * @param a
     * @param b
     */
    template <typename T>
    static void swap(T& a, T& b);

public:
    /**
     * @brief print top DISPLAY rooms info based on suitability of a Room (desired number of beds and period of time)
     *
     * @param hB HotelBuilding
     * @param beds desired number of beds
     * @param period period of time
     */
    static void suggest(Building& hB, unsigned beds, DatePeriod period);

    /**
     * @brief print soonest period when a particular room is free for particular number of nights
     *
     * @param hB HotelBuilding
     * @param number ID of the Room
     * @param nights length of a period
     * @param today today's Date
     */
    static void soonestFreePeriod(const Building& hB, unsigned number, unsigned nights, Date today);
};

template <typename T>
void Analizer::swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}



