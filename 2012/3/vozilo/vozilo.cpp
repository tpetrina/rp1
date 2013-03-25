#include "vozilo.h"
#include <limits>


list<vozilo*> vozilo::listaVozila;

vozilo::vozilo(int snagaMotora, int brojKotaca, string registracija)
{
    snaga = snagaMotora;
    brKotaca = brojKotaca;
    reg = registracija;
    gume = 0;
    listaVozila.push_back(this);
}

int vozilo::snagaMotora()
{
    return snaga;
}

int vozilo::brojKotaca()
{
    return brKotaca;
}

string vozilo::registracija()
{
    return reg;
}

int vozilo::istrosenostGuma()
{
    return gume;
}

void vozilo::odvoziKrug()
{
    gume += 10;
}

vozilo &vozilo::iduciBrzi()
{
    list<vozilo*>::iterator it;
    int trazenaSnaga = numeric_limits<int>::max();
    vozilo *trazenoVozilo = NULL;

    for(it = listaVozila.begin(); it != listaVozila.end(); it++)
    {
        if((*it)->snaga > snaga && (*it)->snaga < trazenaSnaga && (*it)->brKotaca == brKotaca)
        {
            trazenaSnaga = (*it)->snaga;
            trazenoVozilo = *it;
        }
    }

    if(trazenoVozilo == NULL) return *this;
    else return *trazenoVozilo;
}

vozilo& vozilo::brzeVozilo(vozilo &voz1, vozilo &voz2)
{
    if(voz1.snaga >= voz2.snaga)
        return voz1;
    else return voz2;
}

automobil::automobil(int snagaMotora, int brojVrata, string registracija) : vozilo(snagaMotora, 4, registracija)
{
    brVrata = brojVrata;
}

int automobil::brojVrata()
{
    return brVrata;
}

void trkaciAutomobil::odvoziKrug()
{
    gume += 20;
}

motor& motor::kupiBolji()
{
    snaga += 100;
    return *this;
}

vozilo::~vozilo()
{
    list<vozilo*>::iterator it;
    for(it = listaVozila.begin(); it != listaVozila.end(); ++it)
    {
        if(*it == this)
        {
            listaVozila.erase(it);
            break;
        }
    }
}
