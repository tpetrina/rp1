#include <iostream>
#include "vozilo.h"

int main(void)
{
    motor M(350, "MMMM");

    cout << M.kupiBolji().snagaMotora() << " " << M.registracija() << endl;
    cout << M.kupiBolji().kupiBolji().snagaMotora() << " " << M.registracija() << endl;

    return 0;
}
