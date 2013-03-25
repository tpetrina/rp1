
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
    {
        cout << nizNamjestaja[i]->masa() << " " << nizNamjestaja[i]->cijena() << " " << nizNamjestaja[i]->materijal() << endl;
    }

    drveniNamjestaj A(20, 2000, "hrast", 3);
    namjestajIverica B(10, 1000, 2);
    namjestajPunoDrvo C(15, 3000, 5);

    cout << A.masa() << " " << A.cijena() << " " << A.materijal() << " " << A.tipDrva() << " " << A.debljinaDrva() << endl;
    cout << B.masa() << " " << B.cijena() << " " << B.materijal() << " " << B.tipDrva() << " " << B.debljinaDrva() << endl;
    cout << C.masa() << " " << C.cijena() << " " << C.materijal() << " " << C.tipDrva() << " " << C.debljinaDrva() << endl;

    return 0;
}
