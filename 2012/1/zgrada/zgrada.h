#pragma once

struct Stan{
  char id;
  int kat;
  double povr;
  Stan(char id1,int kat1,double povrsina);
  Stan();
  void ispisi();
};

struct Zgrada{
  Stan s[1000];
  int bs,bk;
  Zgrada(Stan S0);
  int brojKatova();
  bool dodaj(Stan S);
  bool stabilna();
  void grijanje(double iznos);
};

