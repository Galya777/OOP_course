#include "HotelMaker.h"
#include <cassert>

Date HotelMaker::now = Date::getToday();

void HotelMaker::nextDay()
{
    building->newDate(++now);
}

HotelMaker& HotelMaker::showAvailableRooms(std::ostream& os, Date d)
{
    os << "Available rooms for " << d << (d < HotelMaker::today() ? " we" : " a") << "re:\n";
    building->showAvailableRooms(os, d);
    return *this;
}

HotelMaker& HotelMaker::getReport(DatePeriod& period)
{
    building->createReport(period);
    return *this;
}

bool HotelMaker::reserveRoom(unsigned number, const DatePeriod& period, std::string name, std::string s)
{
    if (!((*building)[number]))
    {
        std::cerr << "No such Room.\n";
        return false;
    }
    if ((*building)[number]->addReservation(name, s, period))
    {
        std::clog << "Reservation successfully made!\n";
        return true;
    }
    std::cerr << "Making reservation failed.\n";
    return false;
}

HotelMaker::HotelMaker(std::string hotelDataFile)
{
    std::ifstream ifs(hotelDataFile, std::ios::in);
    assert(ifs.is_open());
    size_t length;
    ifs >> length;
    ifs.get();
    name = readFromIfstream(ifs, length);
    building = new Building(ifs);
    ifs.close();

    std::ifstream data(name + ".dat", std::ios::in | std::ios::binary);
    if (data.is_open())
    {

        now.readDataFromBinary(data);
        if (Date::getToday() > now)
            now = Date::getToday();
        building->readDataFromBinary(data);
    }
    data.close();
}

std::string readFromIfstream(std::ifstream& ifs, size_t len)
{
    char* buf = new char[len + 1];
    ifs.getline(buf, len + 1);
    buf[len] = '\0';
    std::string res(buf);
    delete[] buf;
    return res;
}

HotelMaker::~HotelMaker()
{
    delete building;
}

bool HotelMaker::serviceRoom(unsigned number, const DatePeriod& period, std::string note)
{
    if (!((*building)[number]))
    {
        std::cerr << "No such Room.\n";
        return false;
    }
    if ((*building)[number]->closeForService(note, period))
    {
        std::clog << "Service successfully planned!\n";
        return true;
    }
    std::cerr << "Room is reserved for this period.\n";
    return false;
}

bool HotelMaker::freeRoom(unsigned number)
{
    Reservation* tmp;
    if (!((*building)[number]))
    {
        std::cerr << "No such room.\n";
        return false;
    }
    if ((*building)[number]->freeRoom(tmp))
    {
        std::clog << "Room freed successfully.\n";
        return true;
    }
    std::cerr << "Room is free already!\n";
    return true;
}

void HotelMaker::searchRoom(unsigned minBeds, const DatePeriod& period) const
{
    if (period.from < now)
    {
        std::cerr << "Cannot suggest rooms for the past!\n";
        return;
    }
    building->suggestRoom(minBeds, period);
}

HotelMaker& HotelMaker::showToday()
{
    building->showRoomsStatesToday(now);
    return *this;
}

HotelMaker& HotelMaker::seeRoomForNights(unsigned number, unsigned nights)
{
    building->showRoomForNights(number, nights, now);
    return *this;
}

bool HotelMaker::workDay()
{
    char cmd[1000];
    std::cin.getline(cmd, 1000, ':');
    while (strchr(cmd, '\n'))
    {
        std::cerr << "Uknown command!\n";
        std::cin.getline(cmd, 1000);
        std::cin.getline(cmd, 1000, ':');
    }
    while (*cmd && strcmp(cmd, "close"))
    {
        if (!strcmp(cmd, "day"))
        {
            nextDay();
            std::cin.get();
            return true;
        }
        if (!strcmp(cmd, "request"))
        {
            unsigned beds;
            DatePeriod per;
            std::cin >> beds;
            per.readProper();
            std::cin.get();
            searchRoom(beds, per);
        }
        else if (!strcmp(cmd, "rooms"))
        {
            std::cin.get();
            showToday();
        }
        else if (!strcmp(cmd, "plan"))
        {
            unsigned number, nights;
            std::cin >> number >> nights;
            std::cin.get();
            seeRoomForNights(number, nights);
        }
        else if (!strcmp(cmd, "free"))
        {
            unsigned number;
            std::cin >> number;
            std::cin.get();
            freeRoom(number);
        }
        else if (!strcmp(cmd, "report"))
        {
            DatePeriod per;
            per.readProper();
            std::cin.get();
            getReport(per);
        }
        else if (!strcmp(cmd, "reserve"))
        {
            unsigned number;
            DatePeriod per;
            std::cin >> number;
            per.readProper();
            std::string name = "", note = "";
            std::cin.get(*cmd);
            if (*cmd != '\n')
            {
                std::cin.getline(cmd, 100, ';');
                name = cmd;
                std::cin.getline(cmd, 100);
                if (*cmd)
                {
                    note = cmd;
                    reserveRoom(number, per, name, note);
                }
                else
                    reserveRoom(number, per, name);
            }
            else
                reserveRoom(number, per);
        }
        else if (!strcmp(cmd, "maintenance"))
        {
            unsigned number;
            DatePeriod per;
            std::cin >> number;
            per.readProper();
            std::cin.get();
            std::cin.getline(cmd, 100);
            serviceRoom(number, per, cmd);
        }
        else if (!strcmp(cmd, "available"))
        {
            Date d;
            do
            {
                std::cin >> d;
                if (d == Date())
                    std::cerr << "Input the date again!\n";
            } while (d == Date());
            std::cin.get();
            showAvailableRooms(std::cout, d);
        }
        std::cin.getline(cmd, 100, ':');
        while (strchr(cmd, '\n'))
        {
            std::cerr << "Unknown command!\n";
            std::cin.getline(cmd, 100);
            std::cin.getline(cmd, 100, ':');
        }
    }
    writeToBinaryFile();
    return false;
}

void HotelMaker::writeToBinaryFile()
{
    std::string streamName = name;
    streamName += ".dat";
    std::ofstream ofs(streamName, std::ios::out | std::ios::binary);
    assert(ofs.is_open());
    now.writeToBinaryFile(ofs);
    building->writeToBinaryFile(ofs);
    ofs.close();
}