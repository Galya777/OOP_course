#include "Control.h"

Control::Control(const Control& other)
{
    copy(other);
}

const Control& Control::operator=(const Control& other)
{
    if (this != &other) {
        del();
        copy(other);
    }
    return *this;
}

const int Control::getId() const
{
    return this->id;
}

const char* Control::getName() const
{
    return this->name;
}

const char* Control::getMessage() const
{
    return this->helpMessage;
}

const bool Control::getEnabled() const
{
    return this->enabled;
}

void Control::setEnabled(bool enabled)
{
    this->enabled = enabled;
}

void Control::copy(const Control& other)
{
    setName(other.name);
    setMessage(other.helpMessage);
    setEnabled(other.enabled);
}
void Control::del()
{
    delete[] name;
    delete[] helpMessage;
}