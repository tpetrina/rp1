#include <iostream>
#include "trznica.h"

using namespace std;

int main(){
  Stand neki("krumpir",12),jeftiniji("krumpir",11);
  Trznica mala(1,1);
  cout<<mala.prazno()<<endl;
  cout<<mala.dodaj(neki,0,0)<<'\t';
  cout<<mala.prazno()<<endl;
  cout<<mala.dodaj(jeftiniji,0,0)<<'\t';
  cout<<mala.dodaj(neki,0,0)<<'\t';
  cout<<mala.prazno()<<endl;
  mala.najjeftiniji("krumpir").ispisi();cout<<endl;
  cout<<mala.putemTrosi(2)<<'\t';
  cout<<mala.putemTrosi(1)<<'\t';
  cout<<mala.putemTrosi(0)<<'\t';
  cout<<mala.putemTrosi(-1)<<endl;
}
