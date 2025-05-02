#include "hallsensor.h"
#include "sensor.h"
#include <QPaintDevice>
#include <QPainter>
#include <QPen>

HallSensor::HallSensor(int a,int b): Sensor(a,b)
{
}

void HallSensor::teken(QPaintDevice* tp)
{
    QPainter p(tp);
    QColor kleur;
    p.setBrush(Qt::SolidPattern);

    if(isGeactiveerd())
        kleur=Qt::green;

    else
        kleur=Qt::red;

    p.setBrush(kleur);
    QPen pen(kleur,2,Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    p.setPen(pen);

    std::pair<int,int> pos = coordinaten();
    p.drawEllipse(pos.first, pos.second, 20, 20);

}
