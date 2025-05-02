#ifndef SLEUTELSLOT_H
#define SLEUTELSLOT_H

class Sleutelslot
{
public:
    Sleutelslot();
    void vergrendel();
    bool isVergrendeld();
    void ontgrendel(string eenSleutel);
private:
    string sleutel;
    bool vergrendeld;
};

#endif // SLEUTELSLOT_H
