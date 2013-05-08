#include <iostream>
#include <utility>
#include <string>
#include <set>
#include <iostream>
#include "trokut.h"

using namespace std;

typedef std::pair<double,double> tocka;

int main()
{
        // testiramo konstruktore
        
        tocka A(-1,0), B(0,0.5773497), C(1,0);
        tocka A2(-1,0), B2(0,1), C2(1,0);

        Trokut c1(A,B,C), c2(2,3,4);
        JednakokracanTrokut t1(A,B,C), t2(5,5);
        JednakostranicanTrokut p1(A,B,C), p2(3);

        // ako kompajliranje prodje sve je u redu

        cout << "Ispravno" << endl;

        return 0;
}
