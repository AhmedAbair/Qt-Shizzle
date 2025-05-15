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

    try {
        int Code = std::stoi(eenCode);
        if (Code == code) {
            vergrendeld = NIETVERGRENDELD;
        }
    } catch (const std::invalid_argument& e) {
        qDebug() << "Ongeldige invoer voor CodeSlot (geen nummer):" << QString::fromStdString(eenCode);
    } catch (const std::out_of_range& e) {
        qDebug() << "CodeSlot invoer buiten bereik:" << QString::fromStdString(eenCode);
    }

}
