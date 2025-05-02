#ifndef DRAAIDEUR_H
#define DRAAIDEUR_H
#include "deur.h"
#include <QPainter>
#include <QPaintDevice>
#include <QPen>
class Draaideur: public Deur
{
public:
    Draaideur(int,int,unsigned int,bool);
    void teken(QPaintDevice *);
private:
    bool liggend;
};

#endif // DRAAIDEUR_H
