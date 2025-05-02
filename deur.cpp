#include "deur.h"
#include "define.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

Deur::Deur(int x, int y,unsigned int len):x_coordinaat(x),y_coordinaat(y),lengte(len),status(DICHT) {}
Deur::Deur(int x, int y,unsigned int len, shared_ptr<Slot> slot):x_coordinaat(x),y_coordinaat(y),lengte(len),status(DICHT),nieuweSlot(slot) {}

void Deur::open(){
    status = OPEN;
}
void Deur::sluit(){
    status = DICHT;
}

// void Deur::teken(QPaintDevice *tp){
//     QPainter painter(tp);
//     QPen pen(Qt::black);
//     painter.setPen(pen);

//     if(isDeurOpen())
//         painter.drawLine(temp.first,y_coordinaat,x_coordinaat,y_coordinaat+lengte);
//     else{
//         painter.drawLine(x_coordinaat,y_coordinaat,x_coordinaat,y_coordinaat-lengte);

//     }

// }

bool Deur::isDeurOpen(){
    return status;
}
unsigned int Deur::deurLengte(){
    return lengte;
}


std::pair<int,int> Deur::coordinaten() const {

    std::pair<int,int> temp;
    temp.first= x_coordinaat;
    temp.second= y_coordinaat;
    return temp;

}
