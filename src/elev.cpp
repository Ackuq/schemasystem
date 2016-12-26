#include "elev.h"
#include <string>

elev::elev()
{

    //ctor'
}
elev::elev(string p,string n) : person(p,n){
    pnm=p;
    nam=n;
}

elev::~elev()
{
    //dtor
}
