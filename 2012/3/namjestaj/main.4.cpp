#include "namjestaj.h"
#include <iostream>

using namespace std;

int main(void)
{
    namjestaj *nizNamjestaja[8];
    nizNamjestaja[0] = new drveniNamjestaj(30, 1500, "hrast", 4);
    nizNamjestaja[1] = new namjestajIverica(10, 1000, 2);
    nizNamjestaja[2] = new namjestajPunoDrvo(25, 4000, 5);
    nizNamjestaja[3] = new namjestajPunoDrvo(20, 3000, 3);
    nizNamjestaja[4] = new namjestajIverica(5, 1100, 1);
    nizNamjestaja[5] = new namjestaj(10,1500, "plastika");
    nizNamjestaja[6] = new namjestaj(40,5000, "aluminija");
    nizNamjestaja[7] = new drveniNamjestaj(15, 2000, "orah", 5);

    for(int i = 0; i < 8; i++)
        cout << nizNamjestaja[i]->vrijednostMaterijala() << endl;

    return 0;
}
