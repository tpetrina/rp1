#include <list>

using namespace std;

class racunalo
{
    private:
        int mhz, mgb;
        float inch;
        static list<racunalo*> listaRacunala;
    public:
        racunalo(int brzina, int ram, float velicinaEkrana);
        int brzina();
        int ram();
        float velicinaEkrana();
        virtual int cijenaNadogradnje(int novaBrzina, int noviRam);
        static racunalo& najbrzeRacunalo();
        static racunalo* spojiRacunala(racunalo &r1, racunalo &r2);
        racunalo& nadjiPrviVeciEkran();
        ~racunalo();
};

class laptop : public racunalo
{
    private:
        float kg;
    public:
        laptop(int brzina, int ram, float velicinaEkrana, float masa);
        float masaLaptopa();
        virtual int cijenaNadogradnje(int novaBrzina, int noviRam);
};

class ultrabook : public laptop
{
    private:
        int mm;
    public:
        ultrabook(int brzina, int ram, float velicinaEkrana, float masa, int debljina);
        int debljina();
        int cijenaNadogradnje(int novaBrzina, int noviRam);
};
