#include "Room.h"
const int INIT_CAPACITY = 1000;
std::ostream& operator<<(std::ostream& os, const Room& R)
{
    if (&os == &std::cout)
        os << "Number: ";
    os << R.getNumber() << '\t';
    if (&os == &std::cout)
        os << "Beds: ";
    return os << R.getBedCount();
}

bool Room::freeRoom(Reservation*& curRes)
{
    if (isFreeNow())
        return false;
    curRes = reservations[0];
    if (curRes->isActive())
        curRes->LeavingInAdvance(HotelMaker::today());

    if (!curRes->isServiced() && curRes->getFrom() < curRes->getTo())
    {
        if (pastCount == pastCapacity)
            expand(pastReservations, pastCount, pastCapacity);
        pastReservations[pastCount++] = curRes;
    }
    else
        delete curRes;

    for (unsigned i = 0; i < resCount - 1; ++i)
        reservations[i] = reservations[i + 1];
    --resCount;
    if (2 * resCount <= resCapacity && resCapacity > INIT_CAPACITY)
        shrink(reservations, resCount, resCapacity);
    return true;
}

void Room::moveToPast()
{
    if (!reservations[0]->isServiced())
    {
        if (pastCount == pastCapacity)
            expand(pastReservations, pastCount, pastCapacity);
        pastReservations[pastCount++] = reservations[0];
    }
    else
        delete reservations[0];

    for (unsigned i = 0; i < resCount - 1; ++i)
        reservations[i] = reservations[i + 1];
    --resCount;
    if (2 * resCount <= resCapacity && resCapacity > INIT_CAPACITY)
        shrink(reservations, resCount, resCapacity);
}

Room::Room(unsigned n, unsigned bC)
    : number(n), bedCount(bC),
    reservations(new Reservation* [INIT_CAPACITY]),
    resCapacity(INIT_CAPACITY), resCount(0),
    pastReservations(new Reservation* [INIT_CAPACITY]),
    pastCapacity(INIT_CAPACITY), pastCount(0)
{
}

void Room::shrink(Reservation**& arr, size_t& size, size_t& cap)
{
    if (!size)
        return;
    cap = size;
    Reservation** newArr = new Reservation * [cap];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

void Room::expand(Reservation**& arr, size_t& size, size_t& cap)
{
    cap = 2 * cap;
    Reservation** newArr = new Reservation * [cap];
    for (unsigned i = 0; i < size; ++i)
        newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
}

bool Room::isFreeNow() const
{
    return !resCount || !reservations[0]->isActive();
}

void Room::newDate(Date newD)
{
    if (!resCount)
        return;
    for (unsigned i = 0; i < resCount; ++i)
        reservations[i]->onDate(newD);
    if (reservations[0]->isPast())
        moveToPast();
}

bool Room::isFreeOnDate(Date d) const
{
    if (d < HotelMaker::today())
    {
        if (resCount && reservations[0]->stateOnDate(d) != ACTIVE || !pastCount)
            return true;
        unsigned i = 0;
        while (i < pastCount && pastReservations[i]->stateOnDate(d) == FUTURE)
            ++i;
        return i == pastCount || pastReservations[i]->stateOnDate(d) == PAST;
    }
    else
    {
        if (!resCount)
            return true;
        unsigned i = 0;
        while (i < resCount && reservations[i]->stateOnDate(d) == PAST)
            ++i;
        return i == resCount || reservations[i]->stateOnDate(d) == FUTURE;
    }
}

Room::~Room()
{
    for (unsigned i = 0; i < resCount; ++i)
        delete reservations[i];
    delete[] reservations;
    for (unsigned i = 0; i < pastCount; ++i)
        delete pastReservations[i];
    delete[] pastReservations;
}

unsigned Room::daysTakenInPeriod(const DatePeriod& period) const
{
    unsigned count = 0, thisRes;
    thisRes = 0;
    while (thisRes < pastCount && pastReservations[thisRes]->stateOnDate(period.from) == PAST)
        ++thisRes;

    if (thisRes < pastCount)
    {
        if (pastReservations[thisRes]->stateOnDate(period.from) == ACTIVE)
            count += pastReservations[thisRes]->getTo() - period.from;
        if (pastReservations[thisRes]->stateOnDate(period.to) == ACTIVE)
        {
            count -= pastReservations[thisRes]->getTo() - period.to;
            return count;
        }
        while (thisRes < pastCount && pastReservations[thisRes]->stateOnDate(period.to) != FUTURE)
        {
            count += pastReservations[thisRes]->getNights();
            ++thisRes;
        }
        if (thisRes < pastCount && pastReservations[thisRes]->stateOnDate(period.to) == ACTIVE)
            count -= pastReservations[thisRes]->getTo() - period.to;
    }

    return count;
}

bool Room::showReservationsInPeriod(std::ostream& os, const DatePeriod& period) const
{
    unsigned count = daysTakenInPeriod(period);
    if (!count)
        return false;
    os << "Room #" << number << " between " << period.from << " and " << period.to << ": " << count << " nights.\n";
    return true;
}

bool Room::newReservation(std::string name, std::string note, const DatePeriod& period, bool service)
{
    if (!isFreeInPeriod(period) || period.from < HotelMaker::today())
        return false;

    if (resCapacity == resCount)
        expand(reservations, resCount, resCapacity);

    reservations[resCount] = new Reservation(name, period, note, service);
    reservations[resCount++]->onDate(HotelMaker::today());
    if (resCount < 2)
        return true;
    unsigned i = resCount - 1;
    Reservation* tmp{ nullptr };
    while (i && reservations[i - 1]->getFrom() >= reservations[i]->getTo())
    {
        tmp = reservations[i - 1];
        reservations[i - 1] = reservations[i];
        reservations[i] = tmp;
        --i;
    }
    return true;
}

bool Room::addReservation(std::string name, std::string note, const DatePeriod& period)
{
    return newReservation(name, note, period, false);
}

bool Room::closeForService(std::string note, const DatePeriod& period)
{
    return newReservation("-", note, period, true);
}

bool Room::isFreeInPeriod(const DatePeriod& period) const
{
    unsigned i = 0;
    while (i < resCount && reservations[i]->stateOnDate(period.from) == PAST)
        ++i;
    return !(i < resCount &&
        !(reservations[i]->stateOnDate(period.from) == FUTURE &&
            reservations[i]->stateOnDate(period.to) == FUTURE));
}

void Room::showActivity() const
{
    std::clog << number << ":\t";
    if (!resCount)
    {
        if (!pastCount)
        {
            std::clog << "No reservations.\n";
            return;
        }
        std::clog << "Last reservation was from "
            << pastReservations[pastCount - 1]->getFrom()
            << " to " << pastReservations[pastCount - 1]->getTo() << ".\n";
        return;
    }
    if (reservations[0]->isActive())
    {
        if (reservations[0]->isServiced())
            std::clog << "Closed for " << reservations[0]->getNote();
        else
            std::clog << "Reserved";
        std::clog << " until " << reservations[0]->getTo() << ".\n";
        return;
    }
    std::clog << "Next " << (reservations[0]->isServiced() ? "maintenance" : "reservation")
        << " is from "
        << reservations[0]->getFrom()
        << " to "
        << reservations[0]->getTo() << ".\n";
}

void Room::writeToBinaryFile(std::ofstream& ofs)
{
    ofs.write((const char*)&number, sizeof(number));

    ofs.write((const char*)&resCount, sizeof(resCount));
    for (unsigned i = 0; i < resCount; ++i)
        reservations[i]->writeToBinaryFile(ofs);
    ofs.write((const char*)&pastCount, sizeof(pastCount));
    for (unsigned i = 0; i < pastCount; ++i)
        pastReservations[i]->writeToBinaryFile(ofs);
}

void Room::readDataFromBinary(std::ifstream& ifs)
{
    ifs.read((char*)&resCount, sizeof(resCount));
    if (resCount)
    {
        resCapacity = resCount;
        Reservation** newArr = new Reservation * [resCapacity];
        delete[] reservations;
        reservations = newArr;
    }

    for (unsigned i = 0; i < resCount; ++i)
    {
        DatePeriod t;
        reservations[i] = new Reservation("", t);
        reservations[i]->readDataFromBinary(ifs);
    }

    ifs.read((char*)&pastCount, sizeof(pastCount));
    if (pastCount)
    {
        pastCapacity = pastCount;
        Reservation** newArr = new Reservation * [pastCapacity];
        delete[] pastReservations;
        pastReservations = newArr;
    }

    for (unsigned i = 0; i < pastCount; ++i)
    {
        DatePeriod t;
        pastReservations[i] = new Reservation("", t);
        pastReservations[i]->readDataFromBinary(ifs);
    }

    while (resCount && reservations[0]->isPast())
        moveToPast();
}