#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "bankomati.h"

using namespace std;

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
        cout << *it << " " ;
}

int main(void)
{
    bankomati B;
    B.dodaj("A", 3); B.dodaj("B", -2); B.dodaj("C", -20);
    B.dodaj("D", 2); B.dodaj("Epbz", 10); B.dodaj("F", -30);
    B.dodaj("G", -2); B.dodaj("HpbzJ", 5); B.dodaj("I", 5);
    B.dodaj("J", 4); B.dodaj("pbzKS",10);  B.dodaj("L", -3);
    B.dodaj("M", 10);

    ispisiListu(B.nadjiBankomat("pbz"));

    return 0;
}
