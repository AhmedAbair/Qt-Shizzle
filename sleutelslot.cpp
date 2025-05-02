#include "sleutelslot.h"

Sleutelslot::Sleutelslot() {}

void Sleutelslot::vergrendel(){
    vergrendeld = true;
}
bool Sleutelslot::isVergrendeld(){

    return vergrendeld;
}
void Sleutelslot::ontgrendel(string eenSleutel){
    vergrendeld = false;
}
