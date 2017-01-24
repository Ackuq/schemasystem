#ifndef KURS_H
#define KURS_H

#include <vector>
#include "elev.h"
#include "larare.h"

class kurs
{
    protected:
        vector<elev> elever;
    public:
        larare* _larare;
        string kursnamn;
        kurs(string);

        void addElevk(elev);
        void addLarare(larare*);
        void knamnOut();
        void kOut();
        virtual ~kurs();

    private:
};

#endif // KURS_H
