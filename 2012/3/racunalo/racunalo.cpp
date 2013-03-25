#include "racunalo.h"
#include <limits>
#include <iostream>

using namespace std;
list<racunalo*> racunalo::listaRacunala;

racunalo::racunalo(int brzina, int ram, float velicinaEkrana)
{
    mhz = brzina;
    mgb = ram;
    inch = velicinaEkrana;
    listaRacunala.push_back(this);
}

int racunalo::brzina()
{
    return mhz;
}

int racunalo::ram()
{
    return mgb;
}

float racunalo::velicinaEkrana()
{
    return inch;
}

int racunalo::cijenaNadogradnje(int novaBrzina, int noviRam)
{
    return (novaBrzina - mhz) * 2 + (noviRam - mgb) * 1;
}

racunalo& racunalo::nadjiPrviVeciEkran()
{
    list<racunalo*>::iterator it;
    float max = numeric_limits<float>::max();
    racunalo *trazeno = NULL;
    for(it = listaRacunala.begin(); it != listaRacunala.end(); it++)
    {
        if((*it)->inch > inch && (*it)->inch < max)
        {
            max = (*it)->inch;
            trazeno = *it;
        }
    }
    if(trazeno != NULL) return *trazeno;
    else return *this;
}

racunalo& racunalo::najbrzeRacunalo()
{
    list<racunalo*>::iterator it;
    int max = numeric_limits<int>::min();
    racunalo *trazeno = NULL;

    for(it = listaRacunala.begin(); it != listaRacunala.end(); it++)
    {
        if((*it)->mhz > max)
        {
            max = (*it)->mhz;
            trazeno = *it;
        }
    }
    return *trazeno;
}

racunalo* racunalo::spojiRacunala(racunalo &r1, racunalo &r2)
{
    int brzina, ram;
    float ekran;

    if(r1.mhz >= r2.mhz) { brzina = r1.mhz; r1.mhz = 0;}
    else { brzina = r2.mhz; r2.mhz = 0;}
    if(r1.mgb >= r2.mgb) { ram = r1.mgb; r1.mgb = 0;}
    else  { ram = r2.mgb; r2.mgb = 0;}
    if(r1.inch >= r2.inch) { ekran = r1.inch; r1.inch = 0;}
    else { ekran = r2.inch; r2.inch = 0;}

    return new racunalo(brzina, ram ,ekran);
}

laptop::laptop(int brzina, int ram, float velicinaEkrana, float masa) : racunalo(brzina, ram, velicinaEkrana)
{
    kg = masa;
}

float laptop::masaLaptopa()
{
    return kg;
}

int laptop::cijenaNadogradnje(int novaBrzina, int noviRam)
{
    return (novaBrzina - this->brzina()) * 3 + (noviRam - this->ram()) * 2;
}

ultrabook::ultrabook(int brzina, int ram, float velicinaEkrana, float masa, int debljina) : laptop(brzina, ram, velicinaEkrana, masa)
{
    mm = debljina;
}

int ultrabook::debljina()
{
    return mm;
}

int ultrabook::cijenaNadogradnje(int novaBrzina, int noviRam)
{
    return (novaBrzina - this->brzina()) * 3 + (noviRam - this->ram()) * 3;
}

racunalo::~racunalo()
{
    list<racunalo*>::iterator it;
    for(it = listaRacunala.begin(); it != listaRacunala.end(); it++)
    {
        if(*it == this)
        {
            listaRacunala.erase(it);
            break;
        }
    }
}
