#include <set>
#include <list>
#include <string>
#include <utility>

using namespace std;

struct bankomati
{
    list<pair<string, int> > listaBank;

    list<pair<string, int> > vratiListu(void) {return listaBank;}
    void dodaj(string bankomatID, int novac);
    void izbrisi(string bakomatID);
    string najbolji(void);
    int zarada(string pocetak, string kraj);
    list<pair<string, int> > nadjiBankomat(string substr);
    set<string> viseOd(int novac);
    pair<string, string> maxZarada(void);
};
