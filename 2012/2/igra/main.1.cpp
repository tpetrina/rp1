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

    game.dodajPolje(1212, -4);game.dodajPolje(2258, -15); game.dodajPolje(3227, 2);
    game.dodajPolje(9326, 1); game.dodajPolje(1528, -3); game.dodajPolje(4445, 5);
    game.dodajPolje(6459, 7); game.dodajPolje(1120, -2); game.dodajPolje(1415, -1);
    game.dodajPolje(8421, -4);game.dodajPolje(1217, 4);  game.dodajPolje(1226, 5);
    game.dodajPolje(6454, 4);game.dodajPolje(2022, 6); game.dodajPolje(2211,3);
    game.izbrisiPolje(9326); game.izbrisiPolje(6454);

    ispisiListu(game.vratiListu());

    return 0;
}
