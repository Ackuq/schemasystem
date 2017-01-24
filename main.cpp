#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "person.h"
#include "elev.h"
#include "larare.h"
#include "klass.h"
#include "kurs.h"
#include "schema.h"

using namespace std;

vector<kurs*> lektioner;
vector<kurs*> kurser;
vector<vector<kurs*> > skoldagar;
vector<klass*> klasser;
vector<larare*> _larare;


int main()
{
    schema s;
    klass te14a("Te14a");
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

    larare S("1234","Sattar");
    S.addKurs("MAT04");
    S.addKurs("MAT05");
    _larare.push_back(&S);

    larare M("1234","Mattias");
    M.addKurs("SVE03");
    _larare.push_back(&M);

    larare J("1234","Jenny");
    J.addKurs("FYS02");
    _larare.push_back(&J);

    larare P("1234","Pernilla");
    P.addKurs("ENG07");
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

    lektioner = s.createLektioner(kurser,lektioner);
    lektioner = s.shuffle(lektioner);
    lektioner = s.addLarare(lektioner,_larare);

    s.displaySchema(lektioner);

    return 0;
}
