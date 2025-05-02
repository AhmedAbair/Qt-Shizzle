#ifndef CODESLOT_H
#define CODESLOT_H
#include <string>
#include "islot.h"
#include "define.h"

class Codeslot : public ISlot
{
public:
    Codeslot(int);
    void vergrendel();
    bool isVergrendeld();
    void ontgrendel(std::string eenCode);
private:
    int code;
    bool vergrendeld;
};

#endif // CODESLOT_H
