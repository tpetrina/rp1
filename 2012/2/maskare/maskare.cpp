#include "maskare.h"

using namespace std;

void maskare::dodaj(string ime, int novac)
{
    kuce.push_back(pair<string, int> (ime, novac));
}

void maskare::izbrisi(string ime)
{
    list <pair<string, int> >::iterator it;

    it = kuce.begin();
    while(it != kuce.end())
    {

        if(it->first == ime) kuce.erase(it++);
        else it++;
    }
}

string maskare::izbjegavatIme()
{
    list<pair<string, int> >::iterator it;

    it = kuce.begin();
    int min = it->second;
    string ime = it->first;;

    for(; it != kuce.end(); it++)
        if(it->second < min)
        {
            min = it->second;
            ime = it->first;
        }

    return ime;
}

int maskare::ukupnoKuna(string pocetak, string kraj, int pocetnaIznos)
{
    int suma = pocetnaIznos;
    bool zbrajaj = false;
    list<pair<string, int> >::iterator it;

    for(it = kuce.begin(); it != kuce.end(); it++)
    {
        if(it->first == pocetak) zbrajaj = true;
        if(zbrajaj) suma += it->second;
        if(suma < 0) suma = 0;
        if(it->first == kraj) break;
    }

    return suma;
}

map<string, int> maskare::dobriJudi()
{
    list<pair<string, int> >::iterator it;
    map<string, int> M;

    for(it = kuce.begin(); it != kuce.end(); it++)
        if(it->second > 0) M[it->first] = it->second;

    return M;
}

set<string> maskare::pronadjiImena(string substr, int novac)
{
    list<pair<string, int> >::iterator it;
    set<string> S;

    for(it = kuce.begin(); it != kuce.end(); it++)
        if(it->first.find(substr) != string::npos && it->second > novac) S.insert(it->first);

    return S;
}

pair<string, string> maskare::pametniObilazak(int pocetniIznos)
{
   list<pair<string, int> >::iterator it, temp;

    string pocetak, kraj, trenutniPocetak;
    int max, trenutniMax;

    it = kuce.begin();
    max = trenutniMax = pocetniIznos;
    pocetak = kraj = trenutniPocetak = it->first;

    for(; it != kuce.end(); it++ )
    {
        trenutniMax += it->second;
        if(trenutniMax > max)
        {
            max = trenutniMax;
            pocetak = trenutniPocetak;
            kraj = it->first;
        }
        if(trenutniMax < pocetniIznos)
        {
            trenutniMax = pocetniIznos;
            temp = it; temp++;
            if(temp != kuce.end()) trenutniPocetak = temp->first;
        }
    }

    return pair<string, string> (pocetak, kraj);
}
