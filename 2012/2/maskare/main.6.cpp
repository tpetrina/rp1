#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <sstream>
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
    stringstream ss;

    for(int i = 0; i <= 20000; i++)
    {
        ss.clear();
        ss.str("");
        ss << i;
        mask.dodaj("A" + ss.str(), 2);
        mask.dodaj("B" + ss.str(), -3);
    }
    for(int i = 0; i <= 20000; i++)
    {
        ss.clear();
        ss.str("");
        ss << i;
        mask.dodaj("C" + ss.str(), 2);
        mask.dodaj("D" + ss.str(), -1);
    }

    pair<string, string> p = mask.pametniObilazak(10);
    cout << p.first << " " << p.second;

    return 0;
}
