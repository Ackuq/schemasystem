#ifndef KLASS_H
#define KLASS_H

#include "elev.h"
#include "kurs.h"
#include <vector>

class klass
{
    protected:
        int hh;
        float mm;
    public:
        string klassnamn;
        vector<kurs> lektioner;
        vector<elev> elever;
        klass(string);
        void displaySchema();
        void displayTime();
        void createLektioner(vector<kurs*>);
        void shuffle();
        void shuffleRange(int);
        void addLarare(vector<larare*>);
        void kOut();
        ~klass();

};

#endif // KLASS_H
