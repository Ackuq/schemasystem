#include "larare.h"
#include <string>


larare::larare(string p,string n,string a) : person(p,n){
    amne = a;
}



larare::~larare()
{
    //dtor
}

larare::larare(const larare& other)
{
    //copy ctor
}
