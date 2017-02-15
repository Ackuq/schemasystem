#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include "person.h"
#include "elev.h"
#include "larare.h"
#include "klass.h"
#include "kurs.h"

using namespace std;

vector<kurs*> kurser;
vector<klass*> klasser;
vector<larare*> _larare;

bool print(){
    cout<<"Vilket schema vill du se?"<<endl;
    for(unsigned int i=0;i<klasser.size();i++){
        cout<<i+1<<": "<<klasser[i] ->klassnamn<<"\t";
    }
    cout<<"Press 0 to quit";
    cout<<endl;
    int i;
    cin>>i;
    switch(i){
        case 1: klasser[0]->displaySchema();
                return true;
        case 2: klasser[1]->displaySchema();
                return true;
        case 0: return false;
        default: return true;
    }
}


int main()
{
    srand(time(NULL));

    klass te14a("Te14a");
    klass te14b("Te14b");
    klasser.push_back(&te14a);
    klasser.push_back(&te14b);
    elev Jacob("1234","Jacob");
    te14a.elever.push_back(Jacob);
    elev Samuel("1234","Samuel");
    te14a.elever.push_back(Samuel);
    elev Julian("1234","Julian");
    te14a.elever.push_back(Julian);

    larare B("1234","Barbro");
    B.addKurs("PRO02");
    B.addKurs("WEBWEU01");
    _larare.push_back(&B);

    larare A("1234","Arif");
    A.addKurs("PRO02");
    A.addKurs("WEBWEU01");
    _larare.push_back(&A);

    larare S("1234","Sattar");
    S.addKurs("MAT04");
    S.addKurs("MAT05");
    S.addKurs("FYS02");
    _larare.push_back(&S);

    larare M("1234","Mattias");
    M.addKurs("SVE03");
    M.addKurs("ENG07");
    _larare.push_back(&M);

    larare J("1234","Jenny");
    J.addKurs("MAT04");
    J.addKurs("MAT05");
    J.addKurs("FYS02");
    _larare.push_back(&J);

    larare P("1234","Pernilla");
    P.addKurs("ENG07");
    P.addKurs("SVE03");
    _larare.push_back(&P);


    kurs Matte4("MAT04");
    kurser.push_back(&Matte4);
    kurs Matte5("MAT05");
    kurser.push_back(&Matte5);
    kurs Fysik2("FYS02");
    kurser.push_back(&Fysik2);
    kurs Svenska3("SVE03");
    kurser.push_back(&Svenska3);
    kurs Engelska7("ENG07");
    kurser.push_back(&Engelska7);
    kurs Programmering("PRO02");
    kurser.push_back(&Programmering);
    kurs Webbutveckling("WEBWEU01");
    kurser.push_back(&Webbutveckling);

    te14a.createLektioner(kurser);
    te14a.shuffle();


    te14b.createLektioner(kurser);
    te14b.shuffle();

    for(int i = 0;i<25;i++){
        if(te14a.lektioner[i].kursnamn == te14b.lektioner[i].kursnamn){
            te14b.shuffleRange(i);
            i=0;
        }
    }
    te14a.addLarare(_larare);
    te14b.addLarare(_larare);

    while (print()){}
    return 0;
}
