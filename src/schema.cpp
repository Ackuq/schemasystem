#include "schema.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <time.h>
#include "klass.h"
#include "kurs.h"

schema::schema()
{
    hh=9;
    mm=0;
}

void schema::displayTime()
{
    ostringstream s_hh, s_mm;
    if(hh<10)
        s_hh <<0<< hh;
    else
        s_hh<<hh;
    if((mm*60) < 9)
        s_mm<<0<<(mm*60);
    else
        s_mm<<(mm*60);
    if(s_mm.str()=="60")
        s_mm.str("00");
    cout<<s_hh.str()<<":"<<s_mm.str();
}
void schema::displaySchema(klass _klass)
{
    cout<<"Schema f\x94r "<<_klass.klassnamn<<endl;
    unsigned int j=0;
    for(unsigned int i=0; i<_klass.lektioner.size(); i++)
    {
        if((j*5)-i==3)
        {
            cout<<"* Lunch *"<<endl<<endl;
            hh++;
        }
        if(i%(_klass.lektioner.size()/5)==0)
        {
            cout<<endl<<"Dag: "<<j+1<<endl<<endl;
            j++;
            hh=9;
            mm=0;
        }
        displayTime();
        hh++;
        mm+=(1.0/3.0);
        if(mm>=1)
        {
            hh++;
            mm--;
        }
        cout<<"-";
        displayTime();
        cout<<"\t";
        mm+=(1.0/12.0);
        if(mm>=1)
        {
            hh++;
            mm--;
        }
        _klass.lektioner[i].knamnOut();
    }
}

klass schema::createLektioner(vector<kurs*> _kurser, klass _klass)
{
    int dag = 0;
    srand(time(NULL));
    while(dag<5)
    {
        vector<int> used;
        int lektion = 0;
        while(lektion<5){
            int randomIndex = rand()% _kurser.size() + 0;
            for(unsigned int i =0;i<used.size();){
                if(randomIndex==used[i]){
                    randomIndex = rand()% _kurser.size() + 0;
                    i=0;
                }
                else
                    i++;
            }
            _klass.lektioner.push_back(*_kurser[randomIndex]);
            used.push_back(randomIndex);
            lektion++;
        }
        dag++;
    }
    return _klass;
}


vector<kurs> schema::addLarare(vector<kurs> _lektioner, vector<larare*> _larar)
{
    for(unsigned int i=0;i<_lektioner.size();i++){
        vector<larare*> hold;
        for(unsigned int j=0;j<_larar.size();j++){
            for(unsigned int z=0; z <_larar[j] -> kurser.size();z++){
                if(_lektioner[i].kursnamn == _larar[j] -> kurser[z]){
                    hold.push_back(_larar[j]);
                }
            }
        }
        if(hold.size()>1){
            int z = 0;
            for(unsigned int j = 1;j<hold.size();j++){
                if(hold[j]->lek < hold[j-1]->lek){
                    z = j;
                }
                else if(hold[j]->lek == hold[j-1]->lek){
                    z = rand()% j + (j-1);
                }
            }
            hold[z] -> lek+=1;
            _lektioner[i].addLarare(hold[z]);
        }
        else{
            _lektioner[i].addLarare(hold[0]);
        }
    }
    return _lektioner;
}
vector<kurs> schema::shuffle(vector<kurs> lektion)
{
    int dag =0;
    srand(time(NULL));
    while(dag<5)
    {
        for(int i=0;i<5;i++){
            int randomIndex1 = rand()% 5 + 0;
            int randomIndex2 = rand()% 5 + 0;
            while(randomIndex1 == randomIndex2)
            {
                randomIndex2 = rand()% 5 + 0;
            }
            randomIndex1+= dag*5;
            randomIndex2+= dag*5;
            kurs hold = lektion[randomIndex1];
            lektion[randomIndex1] = lektion[randomIndex2];
            lektion[randomIndex2] = hold;
        }
        dag++;
    }
    return lektion;
}

schema::~schema()
{
    //dtor
}
