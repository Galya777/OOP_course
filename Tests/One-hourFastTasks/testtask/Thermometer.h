//
// Created by galya777 on 05.08.25.
//

#ifndef OOP_COURSE_THERMOMETER_H
#define OOP_COURSE_THERMOMETER_H


class Thermometer: public MeasuringDevice {
public:
    Thermometer(int id){
        this->id=id;
    }
    virtual double read() const override{
        return 36.6;
    };
private:

};


#endif //OOP_COURSE_THERMOMETER_H
