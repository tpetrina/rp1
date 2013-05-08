#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <cmath>
#include "cetverokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo povrsinu
        
        tocka A(-1,0), B(0,2), C(1,0), D(0,-2);
        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);
        tocka A3(-1,0), B3(0,4), C3(1,0), D3(0,-1);

        bool uvjet = true;

        Cetverokut c1(A3,B3,C3,D3);
        if( fabs(c1.povrsina() - 5) > 0.01 ) uvjet = false;

        Trapez t2(A,B,C,D);
        if( fabs(t2.povrsina() - 4) > 0.01  ) uvjet = false;

        Trapez t3(3,sqrt(2),1,sqrt(2));
        if( fabs(t3.povrsina() - 2) > 0.01  ) uvjet = false;

        Pravokutnik p1(A2,B2,C2,D2);
        if( fabs(p1.povrsina() - 2) > 0.01 ) uvjet = false;

        Kvadrat k1(A2,B2,C2,D2);
        if( fabs(k1.povrsina() - 2) > 0.01 ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
