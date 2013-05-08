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
        // testiramo kutove
        
        tocka A(-1,0), B(0,0.5773497), C(5,0.5773497),  D(5.5773497, 0);
        double K1[4] = {30.0, 45.0, 135.0, 150.0 };

        tocka A2(-1,0), B2(0,1), C2(1,0), D2(0,-1);
        double K2 = 90;

        tocka A3(-1,0), B3(0,4), C3(1,0), D3(0,-1);
        double K3[3] = { 28.07236, 90.0, 120.9638 };

        bool uvjet = true;

        Cetverokut c(A3,B3,C3,D3);

        std::set<double> K = c.kutovi();
        if( K.size() != 3 ) uvjet = false;
        int br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( K3[br++] - *i ) > 0.01 ) uvjet = false;
        }

        Trapez t(A2,B2,C2,D2), t2(A,B,C,D);

        K = t.kutovi();
        if( K.size() != 1 ) uvjet = false;
        br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( K2 - *i ) > 0.01 ) uvjet = false;
        }

        K = t2.kutovi();
        if( K.size() != 4 ) uvjet = false;
        br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( K1[br++] - *i ) > 0.01 ) uvjet = false;
        }


        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
