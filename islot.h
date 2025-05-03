#ifndef ISLOT_H
#define ISLOT_H
#include <string>

class ISlot
{
public:

    virtual void ontgrendel(std::string eenSleutel)=0;
    virtual void vergrendel()=0;
    virtual bool isVergrendeld()=0;

};

#endif // ISLOT_H
