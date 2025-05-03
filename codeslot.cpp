#include "codeslot.h"

#include <cstdlib>
#include <QDebug>
#include <stdexcept>
#include <string>

Codeslot::Codeslot(int numCode, bool vergrendeld): code(numCode), vergrendeld(vergrendeld) {}

void Codeslot::vergrendel(){

    vergrendeld = VERGRENDELD;
}

bool Codeslot::isVergrendeld(){
    return vergrendeld;
}

void Codeslot::ontgrendel(std::string eenCode){

    int Code = std::stoi(eenCode);
    if(Code == code)
    vergrendeld = NIETVERGRENDELD;

}
