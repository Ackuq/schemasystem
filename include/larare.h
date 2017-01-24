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
        vector<string> kurser;

        larare(const larare& other);
        larare(string,string);
        void addKurs(string);
        virtual ~larare();
    private:
};

#endif // LARARE_H
