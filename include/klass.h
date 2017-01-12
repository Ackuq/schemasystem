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

        klass();
        klass(string k)
        {
            klassnamn=k;
        }
        ~klass();
        void knamnOut(){
            cout<<klassnamn<<endl;
        }
        void kOut(){
            cout<<"Klass: "<<klassnamn<<endl;
            cout<<"Antal elever i klass: "<<elever.size();
            for (unsigned int i = 0; i<elever.size();i++){
                elever[i].pOut();
            }
        }
};

#endif // KLASS_H
