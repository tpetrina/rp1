#include "igra.h"
#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void ispisiListu(list<pair<int, int> > L)
{
    list<pair<int, int> >::iterator it;

    for(it = L.begin(); it != L.end(); it++)
        cout << it->first << " " << it->second << " ";
}

void ispisiMap(map<int, int> M)
{
    map<int, int>::iterator it;

    for(it = M.begin(); it != M.end(); it++)
        cout << it->first << " " << it->second << " ";
}

void ispisiVector(vector<pair<int, int> > V)
{
    for(int i = 0; i < V.size() ; i++)
        cout << V[i].first << " " << V[i].second << " ";
}


int main(void)
{
    igra game;

    for(int i = 1; i < 10000; i++)
    {
        game.dodajPolje(i, -1);
    }

    for(int i = 10000; i < 40000; i++)
    {
        if(i % 2 == 1) game.dodajPolje(i, 1);
        if(i%4 == 0) game.dodajPolje(i, 2);
        if(i%4 == 2) game.dodajPolje(i, -1);
    }

    pair<int, int> p = game.optimalnaIgra(1);
    cout << p.first << " " << p.second;

    return 0;
}
