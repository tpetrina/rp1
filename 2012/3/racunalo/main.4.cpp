#include <iostream>
#include "racunalo.h"

int main(void)
{
    racunalo X(1800, 2048, 23), Y(2500, 1024, 23);
    racunalo *Z = racunalo::spojiRacunala(X, Y);
    cout << X.brzina() << " " << X.ram() << " " << X.velicinaEkrana() << endl;
    cout << Y.brzina() << " " << Y.ram() << " " << Y.velicinaEkrana() << endl;
    cout << Z->brzina() << " " << Z->ram() << " " << Z->velicinaEkrana() << endl;

    racunalo W(1100, 512, 19);
    racunalo *U = racunalo::spojiRacunala(W, Y);
    cout << W.brzina() << " " << W.ram() << " " << W.velicinaEkrana() << endl;
    cout << Y.brzina() << " " << Y.ram() << " " << Y.velicinaEkrana() << endl;
    cout << U->brzina() << " " << U->ram() << " " << U->velicinaEkrana() << endl;
    return 0;
}

