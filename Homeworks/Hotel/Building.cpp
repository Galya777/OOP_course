#include "Building.h"

Building::Building(std::ifstream& ifs)
{
    unsigned number, bedCount;
    ifs >> size;
    rooms = new Room * [size];
    for (unsigned i = 0; i < size; ++i)
    {
        ifs >> number >> bedCount;
        rooms[i] = new Room(number, bedCount);
    }
}

Building::~Building()
{
    for (unsigned i = 0; i < size; ++i)
        delete rooms[i];
    delete[] rooms;
}

Room* Building::operator[](unsigned roomNumber) const
{
    unsigned i = 0;
    while (i < size && roomNumber != rooms[i]->getNumber())
        ++i;
    if (i == size)
        return nullptr;
    return rooms[i];
}

void Building::newDate(Date newD)
{
    for (unsigned i = 0; i < size; ++i)
        rooms[i]->newDate(newD);
}

void Building::showAvailableRooms(std::ostream& os, Date d) const
{
    for (unsigned i = 0; i < size; ++i)
        if (rooms[i]->isFreeOnDate(d))
            os << *rooms[i] << '\n';
}

void Building::createReport(DatePeriod& period) const
{
    if (period.from > HotelMaker::today())
        return;
    if (period.to > HotelMaker::today())
        period.to = HotelMaker::today();
    char buf[30];
    strcpy(buf, "reports/report-");
    period.from(buf + 15);
    strcat(buf, ".txt");
    std::ofstream ofs(buf, std::ios::out);
    if (!ofs.is_open())
    {
        std::cerr << "Folder reports does not exist!\n";
        return;
    }
    ofs << "Report for the usage of the rooms between " << period.from << " and " << period.to << ":\n\t";
    for (unsigned i = 0; i < size; ++i)
        if (rooms[i]->showReservationsInPeriod(ofs, period))
            ofs << '\t';
    ofs.close();
    std::clog << "Report \"" << period.from << "\" created successfully.\n";
}

void Building::suggestRoom(unsigned beds, const DatePeriod& period)
{
    if (period.from < HotelMaker::today())
    {
        std::cerr << "Past period!\n";
        return;
    }
    Analizer::suggest(*this, beds, period);
}

void Building::showRoomsStatesToday(Date today) const
{
    for (unsigned i = 0; i < size; ++i)
        rooms[i]->showActivity();
}

void Building::showRoomForNights(unsigned number, unsigned nights, Date today) const
{
    Analizer::soonestFreePeriod(*this, number, nights, today);
}

void Building::writeToBinaryFile(std::ofstream& ofs)
{
    ofs.write((const char*)&size, sizeof(size));
    for (unsigned i = 0; i < size; ++i)
        rooms[i]->writeToBinaryFile(ofs);
}

void Building::readDataFromBinary(std::ifstream& ifs)
{
    unsigned int number;
    size_t count;
    ifs.read((char*)&count, sizeof(count));

    for (unsigned i = 0; i < count; ++i)
    {
        ifs.read((char*)&number, sizeof(number));
        if (this->operator[](number))
            this->operator[](number)->readDataFromBinary(ifs);
        else
            Room(0, 0).readDataFromBinary(ifs);
    }
}