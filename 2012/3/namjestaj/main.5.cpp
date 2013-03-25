
#include "namjestaj.h"
#include <iostream>

using namespace std;

int main(void)
{
    namjestajPunoDrvo A(20, 1500, 5);
    namjestajIverica *jeftino = A.jeftinaKopija();
    cout << jeftino->masa() << " " << jeftino->cijena() << " " << jeftino->materijal() << " "<< jeftino->tipDrva() << " " << jeftino->debljinaDrva() <<  endl;

    namjestaj *elementiZaGarniturau[3];
    elementiZaGarniturau[0] = new namjestaj(25, 500, "aluminij");
    elementiZaGarniturau[1] = new namjestajPunoDrvo(20, 2000, 4);
    elementiZaGarniturau[2] = new namjestaj(15, 1000, "plastika");
    namjestaj *garnitura = namjestaj::stvoriGarnituru(elementiZaGarniturau, 3);
    cout << garnitura->masa() << " " << garnitura->cijena() << " " << garnitura->materijal() << endl;

    return 0;
}
