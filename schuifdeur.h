#ifndef SCHUIFDEUR_H
#define SCHUIFDEUR_H
#include <QPainter>
#include "deur.h"
#include "hallsensor.h"
#include "sleutelslot.h"
class Schuifdeur: public Deur{
public:
    Schuifdeur(int,int,unsigned int, HallSensor* sensorHall);
    void teken(QPaintDevice*);
    void sluit();
private:
    HallSensor* sensortje;
    std::shared_ptr<Sleutelslot> slot;
};

#endif // SCHUIFDEUR_H
