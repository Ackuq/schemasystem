#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <algorithm>
#include "person.h"
#include "elev.h"
#include "larare.h"
#include "klass.h"
#include "kurs.h"

using namespace std;

vector<kurs*> shuffle(vector <kurs*> lektion)
{
    srand(unsigned(time(NULL)));
    random_shuffle(lektion.begin(), lektion.end());
    return lektion;
}

vector<kurs*> createLektioner(vector<kurs*> _kurser, vector<kurs*> _lektioner)
{
    for(unsigned int i = 0; i<_kurser.size();i++){
        int currTime = 0;
        int reqTime = (4*60);
        while(currTime<reqTime){
            _lektioner.push_back(_kurser[i]);
            currTime +=50;
        }
    }
    return _lektioner;
}

/*vector<vector<kurs*> > createSkoldagar(vector<kurs*> _lektioner, vector<vector<kurs*> > _skoldagar)
{
    int j=0;
    for(unsigned int i=0;i<_lektioner.size();i++){
        if(j%5==0 &&j!=0){
            j++;
        }
        _skoldagar[j].push_back(_lektioner[i]);
    }
    return _skoldagar;
}*/


vector<kurs*> lektioner;
vector<kurs*> kurser;
vector<vector<kurs*> > skoldagar;
vector<klass*> klasser;


int main()
{
    elev Jacob("124214","Jacob");
    elev Smel("1253567","Smuel");
    elev Jul("1253567","Julle");
    elev Janu("1253567","Januari");

    klass te14a("Te14a");
    te14a.addElev(Jacob);
    te14a.addElev(Janu);
    klasser.push_back(&te14a);

    klass te14b("Te14b");
    te14b.addElev(Smel);
    te14b.addElev(Jul);
    klasser.push_back(&te14a);

    kurs Matte4("Matte 4");
    Matte4.addElevk(Janu);
    kurser.push_back(&Matte4);

    kurs Fysik2("Fysik 2");
    Fysik2.addElevk(Jacob);
    kurser.push_back(&Fysik2);

    kurs Svenska3("Svenska 3");
    Svenska3.addElevk(Smel);
    kurser.push_back(&Svenska3);


    lektioner = createLektioner(kurser,lektioner);
    lektioner = shuffle(lektioner);
    for(unsigned int i= 0;i<lektioner.size();i++){
        lektioner[i] ->knamnOut();
    }
    int j=0;
    for(unsigned int i=0;i<lektioner.size();i++){
        if(j%5==0 &&j!=0){
            j++;
        }
        skoldagar[j].push_back(lektioner[i]);
    }
    //createSkoldagar(lektioner,skoldagar);
    //skoldagar = createSkoldagar(lektioner, skoldagar);
    return 0;
}
