#include "klass.h"


klass::klass(string k)
{
    klassnamn=k;
}

void klass::knamnOut()
{
    cout<<klassnamn<<endl;
}
void klass::kOut()
{
    cout<<"Klass: "<<klassnamn<<endl;
    cout<<"Antal elever i klass: "<<elever.size();
    for (unsigned int i = 0; i<elever.size(); i++)
    {
        elever[i].pOut();
    }
}

klass::~klass()
{
    //dtor
}
