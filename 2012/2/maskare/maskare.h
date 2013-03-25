#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>

using namespace std;

struct maskare
{
    list<pair<string, int> > kuce;

    list<pair<string, int> > vratiListu(void) {return kuce;}
    void dodaj(string ime, int novac);
    void izbrisi(string ime);
    string izbjegavatIme(void);
    int ukupnoKuna(string pocetak, string kraj, int pocetniIznos);
    map<string, int> dobriJudi(void);
    set<string> pronadjiImena(string substr, int novac);
    pair<string, string> pametniObilazak(int pocetniIznos);
};
