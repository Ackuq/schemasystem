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
        larare(const larare& other);
        larare(string,string,string);

        virtual ~larare();
    private:
};

#endif // LARARE_H
