#include "larare.h"
#include <string>

larare::larare(string p,string n) : person(p,n){
    lek = 0;
}

void larare::addKurs(string kurs)
{
    kurser.push_back(kurs);
}

larare::~larare()
{
    //dtor
}

larare::larare(const larare& other)
{
    //copy ctor
}
