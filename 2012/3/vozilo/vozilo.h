#include <list>
#include <string>

using namespace std;


class vozilo
{
    private:
        int brKotaca;
        string reg;
        static list<vozilo*> listaVozila;
    protected:
        int gume, snaga;
    public:
        vozilo(int snagaMotora, int brojKotaca, string registracija);
        int snagaMotora();
        int brojKotaca();
        string registracija();
        vozilo& iduciBrzi();
        int istrosenostGuma();
        virtual void odvoziKrug();
        static vozilo& brzeVozilo(vozilo &voz1, vozilo &voz2);
        ~vozilo();
};

class automobil : public vozilo
{
    private:
        int brVrata;
    public:
        automobil(int snagaMotora, int brojVrata, string registracija);
        int brojVrata();
};

class trkaciAutomobil : public automobil
{
    public:
        trkaciAutomobil(int snagaMotora, string registracija) : automobil(snagaMotora, 2, registracija) {}
        void odvoziKrug();
};

class motor : public vozilo
{
    public:
        motor(int snagaMotora, string registracija) : vozilo(snagaMotora, 2, registracija) {}
        motor& kupiBolji();
};
