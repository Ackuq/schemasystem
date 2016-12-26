#include "person.h"

using namespace std;

person::person()
{
    //ctor
}

person::person(string p,string n) : pnmr(p),namn(n){}

person::person(const person& other)
{
    //copy ctor
}

person::~person()
{
    //dtor
}
