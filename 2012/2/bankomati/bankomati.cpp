#include "bankomati.h"

using namespace std;

void bankomati::dodaj(string bankomatID, int novac)
{
    listaBank.push_back(pair<string, int> (bankomatID, novac));
}

void bankomati::izbrisi(string bankomatID)
{
    list <pair<string, int> >::iterator it;

    it = listaBank.begin();
    while(it != listaBank.end())
    {

        if(it->first == bankomatID) listaBank.erase(it++);
        else it++;
    }
}

string bankomati::najbolji()
{
    list<pair<string, int> >::iterator it;

    it = listaBank.begin();
    int max = it->second;
    string ID = it->first;;

    for(; it != listaBank.end(); it++)
        if(it->second > max)
        {
            max = it->second;
            ID = it->first;
        }

    return ID;
}

int bankomati::zarada(string pocetak, string kraj)
{
    int suma = 0;
    bool zbrajaj = false;
    list<pair<string, int> >::iterator it;

    for(it = listaBank.begin(); it != listaBank.end(); it++)
    {
        if(it->first == pocetak) zbrajaj = true;
        if(zbrajaj) suma += it->second;
        if(it->first == kraj) break;
    }

    return suma;
}

list<pair<string, int> > bankomati::nadjiBankomat(string substr)
{
    list<pair<string, int> > L;
    list<pair<string, int> >::iterator it;

    for(it = listaBank.begin(); it != listaBank.end(); it++)
        if(it->first.find(substr) != string::npos) L.push_back(*it);

    return L;
}

set<string> bankomati::viseOd(int novac)
{
    list<pair<string, int> >::iterator it;
    set<string> S;

    for(it = listaBank.begin(); it != listaBank.end(); it++)
        if(it->second > novac) S.insert(it->first);

    return S;
}

pair<string, string> bankomati::maxZarada()
{
   list<pair<string, int> >::iterator it, temp;

    string pocetak, kraj, trenutniPocetak;
    int max, trenutniMax;

    it = listaBank.begin();
    max = trenutniMax = 0;
    pocetak = kraj = trenutniPocetak = it->first;

    for(; it != listaBank.end(); it++ )
    {
        trenutniMax += it->second;
        if(trenutniMax > max)
        {
            max = trenutniMax;
            pocetak = trenutniPocetak;
            kraj = it->first;
        }
        if(trenutniMax < 0)
        {
            trenutniMax = 0;
            temp = it; temp++;
            if(temp != listaBank.end()) trenutniPocetak = temp->first;
        }
    }

    return pair<string, string> (pocetak, kraj);
}


