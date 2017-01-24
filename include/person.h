#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstdlib>


using namespace std;

class person
{
    protected:
        string pnmr;

    public:
        string namn;

        person();
        person(string,string);
        person(const person& other);
        void pOut()
        {
            cout<<pnmr;
            cout<<namn;
        }
        virtual ~person();

};

#endif // PERSON_H
