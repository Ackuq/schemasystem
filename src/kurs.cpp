#include "kurs.h"

kurs::kurs(string k)
{
    kursnamn = k;
}
void kurs::addElevk(elev _elev){
    elever.push_back(_elev);
}
void kurs::addLarare(larare* __larare)
{
    _larare = __larare;
}
void kurs::knamnOut()
{
    cout<<"Kurs: "<<kursnamn<<"\t"<<"L\x84rare: "<<_larare->namn<<endl<<endl;
}
void kurs::kOut(){
    cout<<"Kurs "<<kursnamn<<endl;
    cout<<"Antal Elever i kurs: "<<elever.size()<<endl;
    for (unsigned int i = 0; i<elever.size();i++){
        elever[i].pOut();
    }
}
kurs::~kurs()
{
    //dtor
}
