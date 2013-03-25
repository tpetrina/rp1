// testni main za "trigrami"
//
// verzija: 1.0
// datum: 1.3.2013.
//
// changelog:

#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s1="aaaaaxaba";
    string s2="aaxabxab";
    string s3="aaaxabayyzyaaxabyaaxaybxab";
    string s4="aaaaabbbbcxxcxxvvv";

    Trigrami T1;
    T1.postavi(s1);

    if( T1.kaoString() == string("aaa;aax;aba;axa;xab") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    Trigrami T2 = T1.leksikografski();

    if (T2.trigrami[0].trigram == string("aaa") && T2.trigrami[2].trigram == string("aba")) {
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( T2.kaoString() == string("aaa;aax;aba;axa;xab") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    Trigrami T3(s2);
    Trigrami Z = T1.zajednicki(T3);

    if( Z.kaoString() == string("xab;aax;axa") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( T3.oznaci(s3) == string("aAAXABayyzyaaxabyAAXAyBXAB") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    Trigrami T4(s4);

    if( T4.distribucija(2) == string("abxc") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}


