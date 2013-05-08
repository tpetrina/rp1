#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s1="aaaaaxababa";

    Trigrami T1;
    T1.postavi(s1);

    if( T1.kaoString() == string("aaa;aba;aax;axa;bab;xab") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}

