#ifndef KURS_H
#define KURS_H

#include <vector>
#include "elev.h"

class kurs
{
    protected:
        vector<elev> elever;

        string kursnamn;
    public:
        kurs();
        kurs(string k){
            kursnamn = k;
        }
        void addElevk(elev Elev){
            elever.push_back(Elev);
        }
        virtual ~kurs();
        void knamnOut(){
            cout<<kursnamn<<endl;
        }
        void kOut(){
            cout<<"Kurs "<<kursnamn<<endl;
            cout<<"Antal Elever i kurs: "<<elever.size()<<endl;
            for (unsigned int i = 0; i<elever.size();i++){
                elever[i].utElev();
            }
        }

    private:
};

#endif // KURS_H
