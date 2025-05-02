#include "draaideur.h"
#include "deur.h"

Draaideur::Draaideur(int x, int y,unsigned int len, bool liggendeDeur,std::shared_ptr<Codeslot> slot): Deur(x,y,len,slot), liggend(liggendeDeur) {

}

void Draaideur::teken(QPaintDevice *tp){

    std::pair draaiDeurCoordinaten = this-> coordinaten();

QPainter painter(tp);
QPen pen(Qt::black);
painter.setPen(pen);


if (liggend) {
    if (!isDeurOpen()) {
        painter.drawLine(draaiDeurCoordinaten.first, draaiDeurCoordinaten.second, draaiDeurCoordinaten.first - deurLengte(), draaiDeurCoordinaten.second);

    } else {

        painter.drawLine(draaiDeurCoordinaten.first, draaiDeurCoordinaten.second, draaiDeurCoordinaten.first, draaiDeurCoordinaten.second - deurLengte());
    }
} else {

    if (!isDeurOpen()) {

        painter.drawLine(draaiDeurCoordinaten.first, draaiDeurCoordinaten.second, draaiDeurCoordinaten.first, draaiDeurCoordinaten.second - deurLengte());
    } else {

        painter.drawLine(draaiDeurCoordinaten.first, draaiDeurCoordinaten.second, draaiDeurCoordinaten.first + deurLengte(), draaiDeurCoordinaten.second);
    }
}
}
