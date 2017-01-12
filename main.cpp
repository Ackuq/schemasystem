#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <algorithm>
#include <sstream>
#include "person.h"
#include "elev.h"
#include "larare.h"
#include "klass.h"
#include "kurs.h"

using namespace std;

vector<kurs*> lektioner;
vector<kurs*> kurser;
vector<vector<kurs*> > skoldagar;
vector<klass*> klasser;
vector<larare*> _larare;

vector<kurs*> shuffle(vector <kurs*> lektion){
    srand(time(NULL));
    random_shuffle(lektion.begin(), lektion.end());
    return lektion;
}

void displayTime(int _hh, float _mm){
    ostringstream s_hh, s_mm;
    if(_hh<10){
        s_hh <<0<< _hh;
    }
    else{
        s_hh<<_hh;
    }
    if((_mm*60) < 9){
        s_mm<<0<<(_mm*60);
    }
    else{
        s_mm<<(_mm*60);
    }
    if(s_mm.str()=="60"){
        s_mm.str("00");
    }
    cout<<s_hh.str()<<":"<<s_mm.str();
}

vector<kurs*> createLektioner(vector<kurs*> _kurser, vector<kurs*> _lektioner){
    for(unsigned int i = 0; i<_kurser.size();i++){
        int currTime = 0;
        int reqTime = 5;
        while(currTime<reqTime){
            _lektioner.push_back(_kurser[i]);
            currTime++;
        }
    }
    return _lektioner;
}

vector<kurs*> addLarare(vector<kurs*> _lektioner, vector<larare*> _larar){
    for(unsigned int i = 0;i<_larar.size();i++){
        for(unsigned int j=0;j<_lektioner.size();j++){
            if(_lektioner[j] -> kursnamn == _larar[i] -> amne){
                _lektioner[j] -> addLarare(_larar[i]);
                break;
            }
            else{
            }
        }
    }
    return _lektioner;
}

int main()
{
    klass te14a("Te14a");
    elev Jacob("1234","Jacob");
    te14a.elever.push_back(Jacob);
    elev Samuel("1234","Samuel");
    te14a.elever.push_back(Samuel);
    elev Julian("1234","Julian");
    te14a.elever.push_back(Julian);

    larare B("1234","Barbro","PRO02");
    _larare.push_back(&B);
    larare S("1234","Sattar","MAT04");
    _larare.push_back(&S);
    larare M("1234","Mattias","SVE03");
    _larare.push_back(&M);
    larare J("1234","Jenny","FYS02");
    _larare.push_back(&J);
    larare P("1234","Pernilla","ENG07");
    _larare.push_back(&P);


    kurs Matte4("MAT04");
    kurser.push_back(&Matte4);
    kurs Fysik2("FYS02");
    kurser.push_back(&Fysik2);
    kurs Svenska3("SVE03");
    kurser.push_back(&Svenska3);
    kurs Engelska7("ENG07");
    kurser.push_back(&Engelska7);
    kurs Programmering("PRO02");
    kurser.push_back(&Programmering);

    lektioner = createLektioner(kurser,lektioner);
    lektioner = shuffle(lektioner);
    lektioner = addLarare(lektioner,_larare);

    unsigned int j=0;
    int hh = 9;
    float mm = 0;
    for(unsigned int i=0;i<lektioner.size();i++){
        if((j*5)-i==3){
            cout<<"* Lunch *"<<endl<<endl;
            hh++;
        }
        if(i%(lektioner.size()/5)==0){
            cout<<endl<<"Dag: "<<j+1<<endl<<endl;
            j++;
            hh=9;
            mm=0;
        }
        displayTime(hh,mm);
        hh++;
        mm+=(1.0/3.0);
        if(mm>=1){
            hh++;
            mm--;
        }
        cout<<"-";
        displayTime(hh,mm);
        cout<<"\t";
        mm+=(1.0/12.0);
        if(mm>=1){
            hh++;
            mm--;
        }
        lektioner[i] ->knamnOut();
    }
    return 0;
}
