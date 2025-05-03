#include "sleutelslot.h"

Sleutelslot::Sleutelslot(std::string sleuteltje, bool vergrendeld): sleutel(sleuteltje), vergrendeld(vergrendeld) {}

void Sleutelslot::vergrendel(){
    vergrendeld = VERGRENDELD;
}
bool Sleutelslot::isVergrendeld(){

    return vergrendeld;
}
void Sleutelslot::ontgrendel(std::string eenSleutel){
    if(eenSleutel == sleutel)
    vergrendeld = NIETVERGRENDELD;
}
