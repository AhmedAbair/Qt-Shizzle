#ifndef DRAAIDEUR_H
#define DRAAIDEUR_H
#include "deur.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPen>
#include "codeslot.h"
class Draaideur: public Deur
{
public:
    Draaideur(int,int,unsigned int,bool,std::shared_ptr<Codeslot> slot);
    void teken(QPaintDevice *);
private:
    bool liggend;
};

#endif // DRAAIDEUR_H
