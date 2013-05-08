#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <iostream>
#include "cetverokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo konstruktore
        
        tocka A(-1,0), B(0,0.5773497), C(1,0),  D(0,-0.5773497);
        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);

        Cetverokut c1(A,B,C,D);
        Trapez t1(A,B,C,D), t2(8,7,6,5);
        Pravokutnik p1(A,B,C,D), p2(3,4);
        Kvadrat k1(A,B,C,D), k2(5);

        // ako kompajliranje prodje sve je u redu

        cout << "Ispravno" << endl;

        return 0;
}
