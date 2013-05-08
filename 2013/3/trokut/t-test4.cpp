#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <cmath>
#include "trokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo povrsinu
        
        tocka A(-1,0), B(0,2), C(1,0);
        tocka A2(-1,0), B2(0,1), C2(1,0);
        tocka A3(-1,0), B3(0,4), C3(1,0);

        bool uvjet = true;

        Trokut c1(A3,B3,C3);
        if( fabs(c1.povrsina() - 4) > 0.01 ) uvjet = false;

        JednakokracanTrokut t2(A,B,C);
        if( fabs(t2.povrsina() - 2) > 0.01  ) uvjet = false;

        JednakostranicanTrokut t3(5);
        if( fabs(t3.povrsina() - 10.82532) > 0.01  ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
