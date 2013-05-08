// testni main za "cetverokut"
//
// verzija: 1.3
// datum: 4.5.2013.
//
// changelog:
// v1.3: promijenio ispis sa "120"/"60" na "60"/"120" da bude uskladjeno sa
// sortiranoscu set-a
// v1.2: promijenio trokut za ispis "120"/"60"
// v1.1: promijenio poredak tocaka kod konstruktora
//

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "cetverokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        tocka A(-1,0), B(0,0.5773497), C(1,0),  D(0,-0.5773497);
        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);

        Cetverokut a(A,B,C,D), b(A2,B2,C2,D2);
        Pravokutnik c(3,4);

        cout << a.tipCetverokuta() << endl; // treba ispisati "trapez"
        cout << b.tipCetverokuta() << endl; // treba ispisati "kvadrat"
        cout << c.tipCetverokuta() << endl; // treba ispisati "pravokutnik"

        // ispisuje "60" i "120" (ili dovoljno blizu tome)
        std::set<double> K = a.kutovi();
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                cout << *i << endl;
        }

        // ispisuje samo "90"
        K = c.kutovi();
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                cout << *i << endl;
        }
        
        return 0;
}
