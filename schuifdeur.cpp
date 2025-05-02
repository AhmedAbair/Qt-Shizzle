#include "schuifdeur.h"
#include "define.h"
#include "deur.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPen>
#include "sleutelslot.h"
Schuifdeur::Schuifdeur(int x, int y, unsigned int len, std::shared_ptr<Sleutelslot> slot, HallSensor* sensorHall)
    : Deur(x, y, len, slot), sensortje(sensorHall) {}


void Schuifdeur::teken(QPaintDevice *tp){
    std::pair deurCorki = this->coordinaten();

    QPainter painter(tp);
    QPen pen(Qt::black);
    painter.setPen(pen);

    if(isDeurOpen())
        painter.drawLine(deurCorki.first, deurCorki.second, deurCorki.first, deurCorki.second + deurLengte());
    else{
       painter.drawLine(deurCorki.first, deurCorki.second, deurCorki.first, deurCorki.second - deurLengte());

    }

}

void Schuifdeur::sluit(){
    if(sensortje && !sensortje->isGeactiveerd()){

        Deur::sluit();
    }

}
