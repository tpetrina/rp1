#pragma once

#include <string>

using namespace std;

struct Ljubimac{
  string vr;
  double c;
  Ljubimac();
  Ljubimac(string vrsta,double cijena);
  void ispisi();
};

struct PetShop{
  Ljubimac p[1000];
  double stanjeNaRacunu,mar;
  int bl;
  PetShop(double pocetniKapital,double marza);
  int dopremi(string vrsta,int koliko,double nabavna);
  Ljubimac prodaj(string trazeno);
  void inventura();
};

