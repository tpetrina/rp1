#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "maskare.h"

void ispisiListu(list<pair<string, int> > L)
{
    list<pair<string, int> >::iterator it;

    for(it = L.begin(); it != L.end(); it++)
        cout << it->first << " " << it->second << " ";
}

void ispisiSkup(set<string> S)
{
    set<string>::iterator it;

    for(it = S.begin(); it != S.end(); it++)
        cout << *it << " ";
}

void ispisiMap(map<string, int> M)
{
    map<string, int>::iterator it;

    for(it = M.begin(); it != M.end(); it++)
        cout << it->first << " " << it->second << " ";
}


int main(void)
{
    maskare mask;

    mask.dodaj("josip", -2); mask.dodaj("bosko", 3); mask.dodaj("alma", -10);
    mask.dodaj("ivana", 1); mask.dodaj("marko", 2); mask.dodaj("igor", -7);
    mask.dodaj("mate", 3); mask.dodaj("filip", 5); mask.dodaj("ante", -15);
    mask.dodaj("petar", 1); mask.dodaj("karlo",1); mask.dodaj("maja", -10);
    mask.dodaj("tonci", 2); mask.dodaj("kristina", -1); mask.dodaj("ana", -4);

    cout << mask.izbjegavatIme() << endl;

    cout << mask.ukupnoKuna("ivana", "karlo", 2);

    return 0;
}
