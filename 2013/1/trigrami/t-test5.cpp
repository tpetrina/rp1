#include "trigrami.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
    string s1="aaaaaxababa";
    string s2="axabxabcde";
    string s3="aaax abaaaxaa xa";

    Trigrami T1;
    T1.postavi(s1);

    Trigrami T3(s2);
    Trigrami Z = T1.zajednicki(T3);

    if( T3.oznaci(s3) == string("aaAX ABaaaxaA XA") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}
