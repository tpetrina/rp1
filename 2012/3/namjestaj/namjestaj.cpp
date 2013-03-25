#include "namjestaj.h"
#include <limits>

using namespace std;

list<namjestaj*> namjestaj::listaNamjestaja;

namjestaj::namjestaj(int masa, int cijena, string materijal)
{
    kg = masa;
    kn = cijena;
    mat = materijal;
    listaNamjestaja.push_back(this);
}

int namjestaj::masa()
{
    return kg;
}

int namjestaj::cijena()
{
    return kn;
}

string namjestaj::materijal()
{
    return mat;
}

void namjestaj::spustiCijenu(int x)
{
    kn -= x;
}

int namjestaj::vrijednostMaterijala()
{
    return kg * 100;
}

namjestaj* namjestaj::stvoriGarnituru(namjestaj *pojedinacniElementi[], int size)
{
    int masa = 0, cijena = 0, max = numeric_limits<int>::min();
    string materijal;
    namjestaj *temp;

    for(int i = 0; i < size; i++)
    {
        if(pojedinacniElementi[i]->kg > max)
        {
            max = pojedinacniElementi[i]->kg;
            materijal = pojedinacniElementi[i]->mat;
        }

        masa += pojedinacniElementi[i]->kg;
        cijena += pojedinacniElementi[i]->kn;
    }

    temp = new namjestaj(masa, cijena, materijal);
    return temp;
}

namjestaj& namjestaj::nadjiNajjeftiniji(string materijal)
{
    list<namjestaj*>::iterator it;
    namjestaj *temp;
    int min = numeric_limits<int>::max();

    for(it = listaNamjestaja.begin(); it != listaNamjestaja.end(); it++)
        if((*it)->kn < min && (*it)->mat == materijal)
        {
            min = (*it)->kn;
            temp = *it;
        }
    return *temp;
}

drveniNamjestaj::drveniNamjestaj(int masa, int cijena, string tipDrva, int debljinaDrva) : namjestaj(masa, cijena, "drvo")
{
    tip = tipDrva;
    debljina = debljinaDrva;
}

string drveniNamjestaj::tipDrva()
{
    return tip;
}

int drveniNamjestaj::debljinaDrva()
{
    return debljina;
}

int namjestajIverica::vrijednostMaterijala()
{
    return this->masa() * 50;
}

int namjestajPunoDrvo::vrijednostMaterijala()
{
    return this->masa() * 200;
}

namjestajIverica* namjestajPunoDrvo::jeftinaKopija()
{
    namjestajIverica *temp;
    temp = new namjestajIverica(this->masa()/2, this->cijena()/3, this->debljinaDrva());
    return temp;
}

namjestaj::~namjestaj()
{
    list<namjestaj*>::iterator it;

    for(it = listaNamjestaja.begin(); it!= listaNamjestaja.end(); it++)
        if (*it == this)
        {
            listaNamjestaja.erase(it);
            break;
        }
}
