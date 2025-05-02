#ifndef CODESLOT_H
#define CODESLOT_H

class Codeslot
{
public:
    Codeslot();
    void vergrendel();
    bool isVergrendeld();
    void ontgrendel(string eenCode);
private:
    int code;
    bool vergrendeld;
};

#endif // CODESLOT_H
