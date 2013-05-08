#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "trokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo tipTrokuta
        
        tocka A(-1,0), B(0,0.5773497), C(1,0);
        tocka A2(-1,0), B2(0,1), C2(1,0);

        bool uvjet = true;

        Trokut c1(A,B,C);
        if( c1.tipTrokuta() != string("jednakokracantrokut") ) uvjet = false;

        JednakokracanTrokut t2(A2,B2,C2);
        if( t2.tipTrokuta() != string("jednakokracantrokut") ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
