#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "cetverokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo tipCetverokuta
        
        tocka A(-1,0), B(0,0.5773497), C(1,0),  D(0,-0.5773497);
        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);

        bool uvjet = true;

        Cetverokut c1(A,B,C,D);
        if( c1.tipCetverokuta() != string("trapez") ) uvjet = false;

        Trapez t2(A2,B2,C2,D2);
        if( t2.tipCetverokuta() != string("kvadrat") ) uvjet = false;

        Pravokutnik p1(A2,B2,C2,D2);
        if( p1.tipCetverokuta() != string("kvadrat") ) uvjet = false;

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
