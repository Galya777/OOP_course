#pragma once
#include <fstream>
#include "Date.h"
#include "Reservation.h"
#include "Building.h"
#include <iomanip>
class HotelMaker
{
    /**
    * @brief name of Hotel
    *
    */
    std::string name;

    /**
     * @brief current Date according to all hotels
     *
     */
    static Date now;

    /**
     * @brief pointer to the vector of rooms
     *
     */
    Building* building;

    /**
     * @brief write this Hotel data into a binary file named "<name>.dat"
     *
     */
    void writeToBinaryFile();

public:
    HotelMaker() = delete;

    /**
     * @brief Construct a new Hotel object
     *
     * @param hotelDataFile path to file where rooms are recorded
     */
    HotelMaker(std::string hotelDataFile);
    HotelMaker(const HotelMaker&) = delete;
    HotelMaker& operator=(const HotelMaker&) = delete;

    /**
     * @brief Destroy the Hotel object
     *
     */
    ~HotelMaker();

    /**
     * @brief get today's Date according to all Hotels
     *
     * @return Date
     */
    static Date today() { return now; }

    /**
     * @brief get the name of this Hotel
     *
     * @return String
     */
    std::string getName() const { return name; }

    /**
     * @brief advance to the nextDay
     *
     */
    void nextDay();

    /**
     * @brief makes a new Reservation for particular Room and period with options for name of guest and notes to the Reservation
     *
     * @param number of the desired Room
     * @param from accomodation Date
     * @param to leaving Date
     * @param name guest's name
     * @param note note to the reservation
     * @return true successfull reservation
     * @return false failed reservation (not made)
     */
    bool reserveRoom(unsigned number, const DatePeriod& period, std::string name = "-", std::string note = "None\n");

    /**
     * @brief output to stream all available rooms for a particular Date
     *
     * @return Hotel& this Hotel
     */
    HotelMaker& showAvailableRooms(std::ostream&, Date);

    /**
     * @brief tries to free Room with particular ID
     *
     * @param number Room's ID
     * @return true room is now free
     * @return false room not found
     */
    bool freeRoom(unsigned number);

    /**
     * @brief Creates report for the usage of this Hotel's rooms in the period from-to. Report written in file named "report-YYYY-MM-DD.txt" where YYYY-MM-DD is the beginning of the period
     *
     * @param period desired period of time
     * @return Hotel& this Hotel
     */
    HotelMaker& getReport(DatePeriod& period);

    /**
     * @brief given minimum number of beds and a desired period to print most suitable rooms for accomodation
     *
     * @param minBeds minimum number of beds
     * @param period desired time period
     */
    void searchRoom(unsigned minBeds, const DatePeriod& period) const;

    /**
     * @brief plans maintenance for particular Room and period leaving note for the service
     *
     * @param number Room's ID
     * @param period desired period of time
     * @param note any notes to the service
     * @return true service planned successfully
     * @return false service planning failed (room not found or is reserved for the period)
     */
    bool serviceRoom(unsigned number, const DatePeriod& period, std::string note);

    /**
     * @brief print status of the building rooms
     *
     * @return Hotel& this Hotel
     */
    HotelMaker& showToday();

    /**
     * @brief print soonest period of particular number of days when particular room is free
     *
     * @param number ID of a room
     * @param nights number of nights to stay in the Hotel for
     * @return Hotel& this Hotel
     */
    HotelMaker& seeRoomForNights(unsigned number, unsigned nights);

    /**
     * @brief work with this Hotel for a whole day
     *
     * @return true day ended with the Hotel still working
     * @return false the Hotel was closed and its data written to "<name>.dat"
     */
    bool workDay();
};


