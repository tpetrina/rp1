#include <iostream>
#include <string>
#include "ftekst.h"

using namespace std;

int main(int argc, const char *argv[])
{
    string s1 =
        "\n" // l1
        "                   \n" // l2
        "\n" // l3
        "ovo je zakon.  Ma daj.  evo           nesto sam tako.\n" // l4, p1
        "prica jedna.  hehe.\n" // l5, p1
        "\n" // l6
        "         nije normalna! zar ne? hehehe.\n" // l7, p2
        "  \n" // l8
        "x?   z! a sta sad?  p.\n" // l9, p3
        "\n" // l10
        "\n" // l11
        "ovo    je        ludnica.  ili? \n" // l12, p4
        "\n" // l13
        "The parameters index and num have default values, which means that erase() can be called with just index to erase all characters after index or with no arguments to erase all characters.           Druga recenica.  Treca recenica.\n"; // l14, p5

    FTekst FT = FTekst(s1);

    if( FT.testPravilo2() == string("2;3;5") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}


