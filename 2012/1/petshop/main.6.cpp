#include <iostream>
#include "petshop.h"

using namespace std;

int main(){
  PetShop X(10000,.137);
  X.dopremi("Fibonaccijev zec",2,10.13);
  X.dopremi("zabac",1,10.13);
  X.dopremi("divlja svinja",10,2505.12);
  X.inventura();cout<<endl;
  X.prodaj("zabac").ispisi();cout<<endl;
  X.prodaj("zec").ispisi();cout<<endl;
  X.prodaj("zaba");cout<<endl;
  X.stanjeNaRacunu+=1000;
  X.dopremi("konj",5,700);
  X.inventura();
  cout<<X.stanjeNaRacunu<<endl;
}
