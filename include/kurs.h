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
        larare* Larare;

        string kursnamn;

        kurs();
        kurs(string k){
            kursnamn = k;
        }
        void addElevk(elev Elev){
            elever.push_back(Elev);
        }
        virtual ~kurs();
        void knamnOut(){
            cout<<"Kurs: "<<kursnamn<<"\t"<<"L\x84rare: "<<Larare->namn<<endl<<endl;
        }
        void addLarare(larare* _Larare){
            Larare = _Larare;
        }
        void kOut(){
            cout<<"Kurs "<<kursnamn<<endl;
            cout<<"Antal Elever i kurs: "<<elever.size()<<endl;
            for (unsigned int i = 0; i<elever.size();i++){
                elever[i].pOut();
            }
        }

    private:
};

#endif // KURS_H
