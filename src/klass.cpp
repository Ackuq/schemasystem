#include "klass.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <time.h>
#include <cmath>
#include "kurs.h"


klass::klass(string k)
{
    klassnamn=k;
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

void klass::displayTime()
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
void klass::displaySchema()
{
    system("CLS");
    cout<<"Schema f\x94r "<<klassnamn<<endl;
    unsigned int j=0;
    for(unsigned int i=0; i<lektioner.size(); i++)
    {
        if((j*5)-i==3)
        {
            cout<<"* Lunch *"<<endl<<endl;
            hh++;
        }
        if(i%(lektioner.size()/5)==0)
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
        lektioner[i].knamnOut();
    }
}

void klass::createLektioner(vector<kurs*> _kurser)
{
    int dag = 0;
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
                else{
                    i++;
                }
            }
            lektioner.push_back(*_kurser[randomIndex]);
            used.push_back(randomIndex);
            lektion++;
        }
        dag++;
    }
}

void klass::shuffleRange(int p){
    int dag = floor(p/5);
    for(int i= 0; i<5;i++){
        int randomIndex1 = rand()% 5 + 0;
        int randomIndex2 = rand()% 5 + 0;
        while(randomIndex1 == randomIndex2)
        {
            randomIndex2 = rand()% 5 + 0;
        }
        randomIndex1+= dag*5;
        randomIndex2+= dag*5;
        kurs hold = lektioner[randomIndex1];
        lektioner[randomIndex1] = lektioner[randomIndex2];
        lektioner[randomIndex2] = hold;
    }
}

void klass::addLarare( vector<larare*> _larar)
{
    for(unsigned int i=0;i<lektioner.size();i++){
        vector<larare*> hold;
        for(unsigned int j=0;j<_larar.size();j++){
            for(unsigned int z=0; z <_larar[j] -> kurser.size();z++){
                if(lektioner[i].kursnamn == _larar[j] -> kurser[z]){
                    hold.push_back(_larar[j]);
                }
            }
        }
        if(hold.size()>1){
            int z = 0;
            for(unsigned int j = 1;j<hold.size();j++){
                if(hold[j]->lek < hold[j-1]->lek ){
                    z = j;
                }
                else if(hold[j]->lek == hold[j-1]->lek){
                    z = rand()% j + (j-1);
                }
            }
            hold[z] -> lek+=1;
            hold[z] -> tider.push_back(i);
            lektioner[i].addLarare(hold[z]);
            //vector<int> used;
            /*for(unsigned int j = 0;i<hold[z] -> tider.size();j++){
                if(i == hold[z] -> tider[j]){
                    hold[z] -> tider.erase(hold[z] -> tider.begin()+j);
                    //lektioner[i]._larare -> tider.push_back(i-1);
                    iter_swap(lektioner.begin()+i, lektioner.begin()+(i-1));
                    i-=1;
                }
            }*/
        }
        else{
            hold[0] -> tider.push_back(i);
            lektioner[i].addLarare(hold[0]);
        }
    }
}
void klass::shuffle()
{
    int dag =0;
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
            kurs hold = lektioner[randomIndex1];
            lektioner[randomIndex1] = lektioner[randomIndex2];
            lektioner[randomIndex2] = hold;
        }
        dag++;
    }
}


klass::~klass()
{
    //dtor
}
