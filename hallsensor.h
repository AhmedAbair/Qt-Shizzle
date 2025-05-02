#ifndef HALLSENSOR_H
#define HALLSENSOR_H
#include <string>
#include "sensor.h"

//class QPaintDevice;
class Sensor;

class HallSensor : public Sensor{

public:
    HallSensor(int,int);
    void teken(QPaintDevice*);
};
#endif // HALLSENSOR_H
