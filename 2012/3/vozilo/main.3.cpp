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

    for(int i = 0; i < 8; i++)
    {
        nizVozila[i]->odvoziKrug();
        nizVozila[i]->odvoziKrug();
        nizVozila[i]->odvoziKrug();
        nizVozila[i]->odvoziKrug();
    }

    for(int i = 0; i < 8; i++)
        cout << nizVozila[i]->registracija() << " " << nizVozila[i]->istrosenostGuma() << endl;

    return 0;
}
