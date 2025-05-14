#ifndef DEUR_H
#define DEUR_H
#include <QPainter>
#include <memory>
#include <utility>
#include "islot.h"

class Deur

{
public:
   // Deur(int,int,unsigned int);
    Deur(int,int,unsigned int);
    void addSlot(std::shared_ptr<ISlot> slot);
    void open();
    void sluit();
    virtual void teken(QPaintDevice *)=0;
    bool isDeurOpen();
    unsigned int deurLengte();
    std::pair<int,int> coordinaten() const;

private:
    bool status;
    int x_coordinaat;
    int y_coordinaat;
    unsigned int lengte;
    std::list<std::shared_ptr<ISlot>> slot;
};

#endif // DEUR_H
