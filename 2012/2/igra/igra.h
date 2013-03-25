#include <map>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct igra
{
    list<pair<int, int> > listaPolja;

    list<pair<int, int> > vratiListu(void) {return listaPolja;}
    void dodajPolje(int ID, int bodovi);
    void izbrisiPolje(int ID);
    vector<pair<int, int> > polja(int igrac);
    map<int, int> viseOd(int bodovi);
    int pobjednik(int poc1, int kraj1, int poc2, int kraj2);
    pair<int, int> optimalnaIgra(int igrac);
};
