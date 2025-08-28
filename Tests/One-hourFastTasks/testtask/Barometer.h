//
// Created by galya777 on 05.08.25.
//

#ifndef OOP_COURSE_BAROMETER_H
#define OOP_COURSE_BAROMETER_H


class Barometer: public MeasuringDevice {
public:
    Barometer(int id){
        this->id=id;
    }
    virtual double read() const override {
        return 1013.25;
    };
private:

};


#endif //OOP_COURSE_BAROMETER_H
