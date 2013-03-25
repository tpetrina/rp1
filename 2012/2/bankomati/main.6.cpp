#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <sstream>
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
    stringstream ss;

    for(int i = 0; i <= 20000; i++)
    {
        ss.clear();
        ss.str("");
        ss << i;
        B.dodaj("A" + ss.str(), 2);
        B.dodaj("B" + ss.str(), -3);
    }
    for(int i = 0; i <= 20000; i++)
    {
        ss.clear();
        ss.str("");
        ss << i;
        B.dodaj("C" + ss.str(), 2);
        B.dodaj("D" + ss.str(), -1);
    }

    pair<string, string> p;
    p = B.maxZarada();

    cout << p.first << " " << p.second;

    return 0;
}
