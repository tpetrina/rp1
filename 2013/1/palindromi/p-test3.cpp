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

    if( P1.najkraci() == string("aba;bab") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}


