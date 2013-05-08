#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s4="abbcxbxbxbccabbabb";

    Trigrami T4(s4);

    if( T4.distribucija(2) == string("bxa") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}

