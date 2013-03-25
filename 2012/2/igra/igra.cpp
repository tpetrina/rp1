#include "igra.h"

using namespace std;

void igra::dodajPolje(int ID, int bodovi)
{
    listaPolja.push_back(pair<int, int> (ID, bodovi));
}

void igra::izbrisiPolje(int ID)
{
    list<pair<int, int> >::iterator it;

    it = listaPolja.begin();
    while(it != listaPolja.end())
    {
        if(it->first == ID) listaPolja.erase(it++);
        else it++;
    }
}

vector<pair<int, int> > igra::polja(int igrac)
{
    list<pair<int, int> >::iterator it;
    vector<pair<int, int> > V;
    int n = 0;

    for(it = listaPolja.begin(); it != listaPolja.end(); it++)
        if(it->first % 2 == igrac-1) n++;

    V.resize(n);
    n = 0;

    for(it = listaPolja.begin(); it != listaPolja.end(); it++)
        if(it->first % 2 == igrac-1)
        {
            V[n] = *it;
            n++;
        }

    return V;
}

map<int, int> igra::viseOd(int bodovi)
{
    list<pair<int, int> >::iterator it;
    map<int, int> M;

    for(it = listaPolja.begin(); it != listaPolja.end(); it++)
        if(it->second > bodovi) M[it->first] = it->second;

    return M;
}

int igra::pobjednik(int poc1, int kraj1, int poc2, int kraj2)
{
    int suma1, suma2;
    bool zbrajaj1, zbrajaj2;
    suma1 = suma2 = 0;
    zbrajaj1 = zbrajaj2 = false;
    list<pair<int, int> >::iterator it;

    for(it = listaPolja.begin(); it != listaPolja.end(); it++)
    {
        if(it->first == poc1) zbrajaj1 = true;
        if(it->first % 2 == 0 && zbrajaj1) suma1 += it->second;
        if(it->first == kraj1) zbrajaj1 = false;
        if(it->first == poc2) zbrajaj2 = true;
        if(it->first % 2 == 1 && zbrajaj2) suma2 += it->second;
        if(it->first == kraj2) zbrajaj2 = false;
    }

    if(suma1 == suma2) return 0;
    else if(suma1 > suma2) return 1;
    else return 2;

}

pair<int, int> igra::optimalnaIgra(int igrac)
{
    list<pair<int, int> >::iterator it, temp;

    int pocetak, kraj, trenutniPocetak, max, trenutniMax;

    max = trenutniMax = 0;
    for(it = listaPolja.begin(); it != listaPolja.end(); it++)
        if(it->first % 2 == igrac - 1)
        {
            pocetak = kraj = trenutniPocetak = it->first;
            break;
        }


    for(; it != listaPolja.end(); it++ )
    {
        if(it->first % 2 == igrac-1)
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
                it++;
                while(it->first % 2 != igrac - 1 && it != listaPolja.end()) it++;
                if(it != listaPolja.end()) trenutniPocetak = it->first;
                it--;
            }
        }
    }
    return pair<int, int> (pocetak, kraj);
}
