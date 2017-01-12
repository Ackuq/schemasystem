#ifndef ELEV_H
#define ELEV_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class elev : public person
{
    protected:

    public:
        elev();
        elev(string,string);
        virtual ~elev();

};

#endif // ELEV_H
