#ifndef LARARE_H
#define LARARE_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include "person.h"

using namespace std;

class larare : public person
{
    protected:
        //vector<string> amnen;
    public:
        string amne;
        larare();
        larare(string,string,string);
        virtual ~larare();
        larare(const larare& other);
    private:
};

#endif // LARARE_H
