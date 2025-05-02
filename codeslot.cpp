#include "codeslot.h"

Codeslot::Codeslot(int numCode): code(numCode) {}

void Codeslot::vergrendel(){
    vergrendeld = true;
}
bool Codeslot::isVergrendeld(){

}
void Codeslot::ontgrendel(std::string eenCode){
    vergrendeld = false;

}
