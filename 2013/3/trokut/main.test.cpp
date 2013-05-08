// testni main za "trokut"
//
// verzija: 1.2
// datum: 4.5.2013.
//
// changelog:
// v1.2: promijenio ispis sa "120"/"30" na "30"/"120" da bude uskladjeno sa
// sortiranoscu set-a
// v1.1: prepravio komentare kod *.tipTrokuta()
//

#include <iostream>
#include <utility>
#include <string>
#include <set>
#include "trokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        tocka A(-1,0), B(1,0), C(0,0.5773497);
        Trokut a(3,4,5), b(A,B,C);
        JednakostranicanTrokut c(5);

        cout << a.tipTrokuta() << endl; // treba ispisati "trokut"
        cout << b.tipTrokuta() << endl; // treba ispisati "jednakokracantrokut"
        cout << c.tipTrokuta() << endl; // treba ispisati "jednakostranicantrokut"

        // ispisuje "30" i "120" (ili dovoljno blizu tome)
        std::set<double> K = b.kutovi();
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                cout << *i << endl;
        }

        // ispisuje samo "60"
        K = c.kutovi();
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                cout << *i << endl;
        }
        
        return 0;
}
