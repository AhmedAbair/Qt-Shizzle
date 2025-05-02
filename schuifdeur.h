#ifndef SCHUIFDEUR_H
#define SCHUIFDEUR_H
#include <QPainter>
#include "deur.h"
#include "hallsensor.h"
class Schuifdeur: public Deur{
public:
    Schuifdeur(int,int,unsigned int, HallSensor*);
    void teken(QPaintDevice*);
    void sluit();
private:
    HallSensor* sensortje;
};

#endif // SCHUIFDEUR_H
