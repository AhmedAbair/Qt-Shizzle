#include "deur.h"
#include "define.h"

#include <QPaintDevice>
#include <QPainter>
#include <QPen>

//Deur::Deur(int x, int y,unsigned int len):x_coordinaat(x),y_coordinaat(y),lengte(len),status(DICHT) {}
Deur::Deur(int x, int y,unsigned int len):x_coordinaat(x),y_coordinaat(y),lengte(len),status(DICHT) {}

void Deur::open(){
      status = OPEN;

    if(slot->isVergrendeld()){
        status = DICHT;
    }




}
void Deur::sluit(){

    status = DICHT;
}

void Deur::teken(QPaintDevice *tp){

}

bool Deur::isDeurOpen(){
    return status;
}
unsigned int Deur::deurLengte(){
    return lengte;
}

void Deur::addSlot(std::shared_ptr<ISlot> slot) {
    this->slot = slot;  // Slot wordt toegevoegd of vervangen
}

std::pair<int,int> Deur::coordinaten() const {

    std::pair<int,int> temp;
    temp.first= x_coordinaat;
    temp.second= y_coordinaat;
    return temp;

}
//vooral klasse deur aanpassen
//functie at slot ofzo?
// constructoren bij schuifdeur en draaideur terug zetten want die moeten eigenlijk gwn normaal blijven
// slot hoort niet IN de deur maar die zit naast de deur dus de shr ptr hoeft niet in de constructor
