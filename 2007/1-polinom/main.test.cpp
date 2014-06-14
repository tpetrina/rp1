#include "polinom.h"
#include <iostream>

using namespace std;
int main()
{
    Polinom p,      // p(x) = 0
            q(3),   // q(x) = 3
            r(2,3), // r(x) = 2*x^3
            x(1,1); // x(x) = x

    cout << q.koeficijent(10) << endl;    // ispiše 0
    p.copy(r);     // p = 2*x^3
    p.dodaj(x);    // p = 2*x^3+x
    if (p.isEqual(q)) // nije jednak
    {
        cout << "P i Q su isti." << endl;
    }
    else
    {
       cout << "P i Q su razliciti." << endl;
    }

    r.mnozi(p); // r = 4x^6 + 2x^4
    cout << r.racunaj(-5) << endl; // ispiše 63750


    Polinom t(-1, 14); // r(x) = -x^14
    t.mnozi(r);        // t(x) = -2x^18 ... član -4x^20 zanemarujemo

    cout << t.stupanj() << endl; // ispiše 18
    cout << t.koeficijent(18) << endl; // ispiše -2

    return 0;
}