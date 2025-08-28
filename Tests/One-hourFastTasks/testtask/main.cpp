//
// Created by galya777 on 05.08.25.
//
#include <iostream>
#include "MeasuringDevice.h"
#include "Thermometer.h"
#include "Barometer.h"

int main() {
    const int SIZE = 2;
    MeasuringDevice* devices[SIZE];

    devices[0] = new Thermometer(1);
    devices[1] = new Barometer(2);

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Reading from device " << i + 1 << ": " << devices[i]->read() << std::endl;
    }

    for (int i = 0; i < SIZE; i++) {
        delete devices[i]; // ❗ Важно: деструкторът на MeasuringDevice трябва да е виртуален и дефиниран!
    }

    return 0;
}
