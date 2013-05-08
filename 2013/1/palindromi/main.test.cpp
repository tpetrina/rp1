// testni main za "palindromi"
//
// verzija: 1.0
// datum: 1.3.2013.
//
// changelog:

#include <iostream>
#include <string>
#include "palindromi.h"

using namespace std;

int main(int argc, const char *argv[])
{
    string s1("anananazabcazaxxxyzxxxqwxxxbbbxbbbcccc");
    string s2("azaxxxyzxxxqazawxxaza");

    Palindromi P1 = Palindromi();
    P1.postavi(s1);

    if( P1.kaoString() == string("xxx;aza;ccc;ananana;bbbxbbb;xbbbx") ){
        cout << "1 Ispravno!" << endl;
    }
    else{
        cout << "1 Neispravno!" << endl;
    }

    if( P1.najduzi() == string("ananana;bbbxbbb") ){
        cout << "2 Ispravno!" << endl;
    }
    else{
        cout << "2 Neispravno!" << endl;
    }

    if( P1.najkraci() == string("xxx;aza;ccc") ){
        cout << "3 Ispravno!" << endl;
    }
    else{
        cout << "3 Neispravno!" << endl;
    }

    Palindromi P2 = Palindromi(s2);
    Palindromi Z = P1.zajednicki(P2);

    if( Z.kaoString() == string("aza;xxx") ){
        cout << "4 Ispravno!" << endl;
    }
    else{
        cout << "4 Neispravno!" << endl;
    }

    if( P1.oznaci(s2) == string("AZAXXXyzXXXqAZAwxxAZA") ){
        cout << "5 Ispravno!" << endl;
    }
    else{
        cout << "5 Neispravno!" << endl;
    }

    return 0;
}

