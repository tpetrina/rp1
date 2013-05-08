#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s1="aaaaaxababa";
    string s2="axabxabcde";

    Trigrami T1;
    T1.postavi(s1);

    Trigrami T3(s2);
    Trigrami Z = T1.zajednicki(T3);

    if( Z.kaoString() == string("xab;axa") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}

