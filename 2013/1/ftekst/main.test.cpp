// testni main za "fromatiranje teksta"
//
// verzija: 1.6
// datum: 8.3.2013.
//
// changelog:
// v1.6: izbacio "\n" s kraja stringa s3
// v1.5: testovi za rijeciVanLinije i brojRijeciVanLinije prepravljeni
// v1.4: test za rijeciVanLinije prepravljen
// v1.3: dodao oznake linija i paragrafa (kao komentare) za string s1
// v1.2: test za pravilo 3 prepravljen
// v1.1: test za pravilo 3 prepravljen

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
        "ovo je zakon. Ma daj.   evo  nesto sam tako.\n" // l4, p1
        "prica jedna.  hehe.\n" // l5, p1
        "  \n" // l6
        "         nije normalna! zar ne? hehehe.\n" // l7, p2
        "\n" // l8
        "x?   z! a sta sad?  p.\n" // l9, p3
        "\n" // l10
        "\n" // l11
        "ovo je        ludnica.  ili? \n" // l12, p4
        "\n" // l13
        "The parameters index and num have default values, which means that erase() can be called with just index to erase all characters after index or with no arguments to erase all characters.           Druga recenica.  Treca recenica.\n" // l14, p5
        "\n" // l15
        "Cetvrta  recenica?   \n"; // l16, p6

    string s2 =
        "\n"
        "\n"
        "\n"
        "ovo je zakon.  Ma daj.  evo nesto sam tako.  prica\n"
        "jedna.  hehe.\n"
        "\n"
        "nije normalna!  zar ne?  hehehe.\n"
        "\n"
        "x?  z!  a sta sad?  p.\n"
        "\n"
        "ovo je ludnica.  ili?\n"
        "\n"
        "The parameters index and num have default values,\n"
        "which means that erase() can be called with just index\n"
        "to erase all characters after index or with no\n"
        "arguments to erase all characters.  Druga recenica.\n"
        "Treca recenica.\n"
        "\n"
        "Cetvrta recenica?\n";

    string p = "A sto  je ovo bio dobar zadatak to je cudo jedno :D!";

    string s3 =
        "\n"
        "\n"
        "\n"
        "ovo je zakon.  Ma daj.  evo nesto sam tako.  prica\n"
        "jedna.  hehe.\n"
        "\n"
        "nije normalna!  zar ne?  hehehe.\n"
        "\n"
        "x?  z!  a sta sad?  p.\n"
        "\n"
        "ovo je ludnica.  ili?\n"
        "\n"
        "The parameters index and num have default values,\n"
        "which means that erase() can be called with just index\n"
        "to erase all characters after index or with no\n"
        "arguments to erase all characters.  Druga recenica.\n"
        "Treca recenica.\n"
        "\n"
        "Cetvrta recenica?  A sto je ovo bio dobar zadatak to\n"
        "je cudo jedno :D!";


    FTekst FT = FTekst(s1);

    if( FT.testPravilo1() == string("4;12;16") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( FT.testPravilo2() == string("1;2;3;5") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( FT.testPravilo3() == string("1,2;3,4") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( FT.testPravilo4(54) == string("2;4;6;7;12;14;16") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( FT.rijeciVanLinije(101) == string("recenica;recenica;Treca;after;all;all;arguments;characters;characters;Druga;erase;erase;hehe;index;index;jedna;no;or;prica;to;to;with") ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    if( FT.brojRijeciVanLinije(101) == 22 ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    FT.format(54);
    if( FT.tekst == s2 ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    FT.dodaj(p);
    if( FT.tekst == s3 ){
        cout << "Ispravno!" << endl;
    }
    else{
        cout << "Neispravno!" << endl;
    }

    return 0;
}
