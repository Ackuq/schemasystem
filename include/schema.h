#ifndef SCHEMA_H
#define SCHEMA_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "kurs.h"
#include "larare.h"

class schema
{
private:
    int hh;
    float mm;

public:
    schema();
    void displaySchema(vector<kurs*>);
    void displayTime();
    vector<kurs*> createLektioner(vector<kurs*>, vector<kurs*>);
    vector<kurs*> shuffle(vector<kurs*>);
    vector<kurs*> addLarare(vector<kurs*>, vector<larare*>);
    virtual ~schema();
};

#endif // SCHEMA_H
