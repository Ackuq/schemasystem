#ifndef ELEV_H
#define ELEV_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class elev : public person
{
    protected:
        string pnm;
        string nam;
    public:
        elev();
        elev(string,string);
        void utElev()
        {
            cout<<nam<<endl<<pnm<<endl<<endl;
        }
        virtual ~elev();

};

#endif // ELEV_H
