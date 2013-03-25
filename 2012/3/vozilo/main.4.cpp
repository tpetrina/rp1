#include <iostream>
#include "vozilo.h"

int main(void)
{
    vozilo A(200, 2, "AAAA"), B(200, 4, "BBBB"), C(400, 4, "CCCC");
    motor M(350, "MMMM");
    trkaciAutomobil T(800, "TTTT");
    vozilo *nizVozila[8];
    nizVozila[0] = new automobil(200, 3, "0000");
    nizVozila[1] = new motor(200, "1111");
    nizVozila[2] = new automobil(250, 5, "2222");
    nizVozila[3] = new trkaciAutomobil(900, "3333");
    nizVozila[4] = new motor(125, "4444");
    nizVozila[5] = new vozilo(220, 2, "5555");
    nizVozila[6] = new vozilo(450, 4, "6666");
    nizVozila[7] = new trkaciAutomobil(700, "7777");

    vozilo &v = vozilo::brzeVozilo(A, C);
    cout << v.snagaMotora() << " " << v.brojKotaca() << " " << v.registracija() << endl;

    vozilo &v1 = vozilo::brzeVozilo(M, B);
    cout << v1.snagaMotora() << " " << v1.brojKotaca() << " " << v1.registracija() << endl;

    vozilo &v2 = vozilo::brzeVozilo(*nizVozila[2], *nizVozila[6]);
    cout << v2.snagaMotora() << " " << v2.brojKotaca() << " " << v2.registracija() << endl;

    return 0;
}
