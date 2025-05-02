#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H
#include <string>
#include "islot.h"
#include "define.h"

class Sleutelslot  : public ISlot
{

public:
    Sleutelslot(std::string);
    void vergrendel();
    bool isVergrendeld();
    void ontgrendel(std::string eenSleutel);
private:
    std::string sleutel;
    bool vergrendeld;
};

#endif // SLEUTELSLOT_H
