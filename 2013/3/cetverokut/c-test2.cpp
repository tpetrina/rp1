#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "cetverokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo ispravanTip
        
        tocka A(-1,0), B(0,0.5773497), C(1,0),  D(0,-0.5773497);
        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);
        tocka A3(-1,0), B3(0,1), C3(1,0), D3(0,0);

        bool uvjet = true;

        Cetverokut c1(A,B,C,D), c2(A3,B3,C3,D3);
        if( c1.ispravanTip() != true || c2.ispravanTip() != false ) uvjet = false;

        Trapez t1(A3,B3,C3,D3), t2(A2,B2,C2,D2); 
        if( t1.ispravanTip() != false || t2.ispravanTip() != true ) uvjet = false;

        Pravokutnik p1(A,B,C,D), p2(3,4);
        if( p1.ispravanTip() != false || p2.ispravanTip() != true ) uvjet = false;

        Kvadrat k1(A,B,C,D), k2(5);
        if( k1.ispravanTip() != false || k2.ispravanTip() != true ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
