#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s1="aaaaaxababa";

    Trigrami T1;
    T1.postavi(s1);

    Trigrami T2 = T1.leksikografski();

    if (T2.trigrami[0].trigram == string("aaa") && T2.trigrami[1].trigram == string("aax")){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}


