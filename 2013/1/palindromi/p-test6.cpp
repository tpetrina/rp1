#include <iostream>
#include <string>
#include "palindromi.h"

using namespace std;

int main(int argc, const char *argv[])
{
    string s1("abababxxababyabaxbab");
    string s2("abababaxyzbaba");
    string s3("abababaxyzba  ba");

    Palindromi P1 = Palindromi();
    P1.postavi(s1);

    Palindromi P2 = Palindromi(s2);

    if( P2.zajednicki(s1).oznaci(s3) == string("abababaxyzBA  BA") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}

