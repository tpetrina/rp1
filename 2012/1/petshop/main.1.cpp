#include <iostream>
#include "petshop.h"

using namespace std;

int main(){
  Ljubimac Pero("golub",10);
  Pero.ispisi();cout<<endl;
  PetShop A(2000,.1);
  A.inventura();
  cout<<A.stanjeNaRacunu<<endl;
  cout<<A.dopremi("papiga",5,69.76)<<endl;
  cout<<A.stanjeNaRacunu<<endl;
  cout<<A.dopremi("skocimis",15,235)<<endl;
  cout<<A.stanjeNaRacunu<<endl;
  A.inventura();
  A.prodaj("mis").ispisi();
  cout<<endl<<(int)A.stanjeNaRacunu<<endl;
}
