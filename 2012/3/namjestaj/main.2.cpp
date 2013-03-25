#include "namjestaj.h"
#include <iostream>

using namespace std;

int main(void)
{
    namjestaj A(10, 2300, "drvo"), B(20, 3000, "aluminij"), C(5, 1200, "plastika"), D(15, 2000, "plastika");

    namjestaj *nizNamjestaja[8];
    nizNamjestaja[0] = new drveniNamjestaj(30, 1500, "hrast", 4);
    nizNamjestaja[1] = new namjestajIverica(10, 1000, 2);
    nizNamjestaja[2] = new namjestajPunoDrvo(25, 4000, 5);
    nizNamjestaja[3] = new namjestajPunoDrvo(20, 3000, 3);
    nizNamjestaja[4] = new namjestajIverica(5, 1100, 1);
    nizNamjestaja[5] = new namjestaj(10,1500, "plastika");
    nizNamjestaja[6] = new namjestaj(3,2000, "aluminij");
    nizNamjestaja[7] = new drveniNamjestaj(15, 2000, "orah", 5);

    namjestaj &jeftinoDrvo = namjestaj::nadjiNajjeftiniji("drvo");
    cout << jeftinoDrvo.masa() << " " << jeftinoDrvo.cijena() << " " << jeftinoDrvo.materijal() << endl;

    namjestaj &jeftinaPlastika = namjestaj::nadjiNajjeftiniji("plastika");
    cout << jeftinaPlastika.masa() << " " << jeftinaPlastika.cijena() << " " << jeftinaPlastika.materijal() << endl;

    namjestaj &jeftiniAlum = namjestaj::nadjiNajjeftiniji("aluminij");
    cout << jeftiniAlum.masa() << " " << jeftiniAlum.cijena() << " " << jeftiniAlum.materijal() << endl;

    return 0;
}
