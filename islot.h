#ifndef ISLOT_H
#define ISLOT_H

class ISlot
{
public:
    ISlot();
    virtual void ontgrendel(string eenSleutel)=0;
    virtual void vergrendel()=0;
    virtual bool isVergrendeld()=0;

};

#endif // ISLOT_H
