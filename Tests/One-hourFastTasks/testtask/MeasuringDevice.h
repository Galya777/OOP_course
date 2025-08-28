//
// Created by galya777 on 05.08.25.
//

#ifndef OOP_COURSE_MEASURINGDEVICE_H
#define OOP_COURSE_MEASURINGDEVICE_H


class MeasuringDevice {
public:
   virtual ~MeasuringDevice()=0;
   virtual double read() const=0;
protected:
    int id;


};
MeasuringDevice::~MeasuringDevice() {}

#endif //OOP_COURSE_MEASURINGDEVICE_H
