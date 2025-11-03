#include "Vehicle.h"
#pragma warning(disable:4996)
Vehicle::Vehicle(const char* registration, const char* description, std::size_t space) {
    v_description = description;
    v_registration = registration;
    v_parkingPlaces = space;
}
void Vehicle::setReg(const char* registration)
{
    v_registration=registration;
}
void Vehicle::setDesc(const char* description)
{
    v_description=description;
}
void Vehicle::setPlace(const std::size_t place)
{
    v_parkingPlaces = place;
}
const char* Vehicle::registration() const
{
    return v_registration.c_str();
}

const char* Vehicle::description() const
{
    return v_description.c_str();
}

std::size_t Vehicle::space() const
{
    return v_parkingPlaces;
}
