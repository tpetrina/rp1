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
        // testiramo kutove
        
        tocka A(-1,0), B(0,0.5773497), C(0.5773497,0);
        double K1[3] = {30.0, 45.0, 105.0 };

        tocka A2(-1,0), B2(0,1), C2(1,0);
        double K2[2] = {45.0, 90.0};

        bool uvjet = true;

        Trokut c(A,B,C);
        std::set<double> K = c.kutovi();
        if( K.size() != 3 ) uvjet = false;
        int br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( K1[br++] - *i ) > 0.01 ) uvjet = false;
        }

        JednakokracanTrokut t(5,5);

        K = t.kutovi();
        if( K.size() != 1 ) uvjet = false;
        br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( 60.0 - *i ) > 0.01 ) uvjet = false;
        }

        JednakokracanTrokut t2(A2,B2,C2);
        K = t2.kutovi();
        if( K.size() != 2 ) uvjet = false;
        br = 0;
        for( std::set<double>::iterator i = K.begin(); i!=K.end(); ++i){
                if( fabs( K2[br++] - *i ) > 0.01 ) uvjet = false;
        }

        if( uvjet ) cout << "Ispravno" << endl;

        return 0;
}
