#ifndef KLASS_H
#define KLASS_H

#include "elev.h"
#include <vector>

class klass
{
    protected:
        string klassnamn;
    public:
        vector<elev> elever;
        klass(string);

        void knamnOut();
        void kOut();
        ~klass();

};

#endif // KLASS_H
