#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "trokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo ispravanTip
        
        tocka A(-1,0), B(0,0.5773497), C(1,0);
        tocka A2(-1,0), B2(0,1), C2(1,0);
        tocka A3(-1,0), B3(0,0), C3(1,0);

        bool uvjet = true;

        Trokut c1(A,B,C), c2(A3,B3,C3);
        if( c1.ispravanTip() != true || c2.ispravanTip() != false ) uvjet = false;

        JednakokracanTrokut t1(A3,B3,C3), t2(A,B,C);
        if( t1.ispravanTip() != false || t2.ispravanTip() != true ) uvjet = false;

        JednakostranicanTrokut p1(A,B,C), p2(3);
        if( p1.ispravanTip() != false || p2.ispravanTip() != true ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
