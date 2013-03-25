#include <iostream>
#include "racunalo.h"

int main(void)
{
    racunalo A(1800, 1024, 17), B(2500, 2048, 23), C(2200, 4096, 24);
    racunalo *nizRacunala[8];
    nizRacunala[0] = new laptop(2000, 2048, 15.6, 5.5);
    nizRacunala[1] = new racunalo(3300, 1024, 19);
    nizRacunala[2] = new ultrabook(1500, 1024, 15.6, 2.3, 22);
    nizRacunala[3] = new ultrabook(1700, 2048, 13.3, 1.8, 18);
    nizRacunala[4] = new laptop(2800, 4096, 17.3, 6);
    nizRacunala[5] = new racunalo(3500, 2048, 10);
    nizRacunala[6] = new laptop(2200, 1024, 22, 5);
    nizRacunala[7] = new ultrabook(1100, 512, 15.6, 3.1, 20);

    laptop D(3000, 4096, 17.3, 7);
    ultrabook E(1600, 2048, 13.3, 1.9, 3);

    for(int i = 0; i < 8; i++ )
        cout << nizRacunala[i]->brzina() << " " << nizRacunala[i]->ram() << " " << nizRacunala[i]->velicinaEkrana() << endl;

    cout << D.brzina() << " " << D.ram() << " " << D.velicinaEkrana() << " " << D.masaLaptopa() << endl;
    cout << E.brzina() << " " << E.ram() << " " << E.velicinaEkrana() << " " << E.masaLaptopa() << " " << E.debljina() << endl;

    return 0;
}

