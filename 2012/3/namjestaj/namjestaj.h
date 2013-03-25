#include <string>
#include <list>

using namespace std;

class namjestaj
{
    private:
        int kg, kn;
        string mat;
        static list<namjestaj*> listaNamjestaja;
    protected:
    public:
        namjestaj(int masa, int cijena, string materijal);
        int masa();
        int cijena();
        string materijal();
        void spustiCijenu(int x);
        static namjestaj* stvoriGarnituru(namjestaj *pojedinacniElementi[], int size);
        static namjestaj& nadjiNajjeftiniji(string materijal);
        virtual int vrijednostMaterijala();
        ~namjestaj();
};

class drveniNamjestaj : public namjestaj
{
    private:
        int debljina;
        string tip;
    public:
        drveniNamjestaj(int masa, int cijena, string tipDrva, int debljinaDrva);
        int debljinaDrva();
        string tipDrva();
};

class namjestajIverica : public drveniNamjestaj
{
    public:
        namjestajIverica(int masa, int cijena, int debljinaDrva) : drveniNamjestaj(masa, cijena, "iverica", debljinaDrva) {}
        int vrijednostMaterijala();
};

class namjestajPunoDrvo : public drveniNamjestaj
{
    public:
        namjestajPunoDrvo(int masa, int cijena, int debljinaDrva) : drveniNamjestaj(masa, cijena, "puno_drvo", debljinaDrva) {}
        int vrijednostMaterijala();
        namjestajIverica* jeftinaKopija();
};
