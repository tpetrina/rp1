#include <iostream>
#include "petshop.h"

using namespace std;

int main(){
  PetShop M(1203,.25);
  cout<<M.dopremi("africka lastavica",10,250)<<endl;
  cout<<M.dopremi("europska lastavica",10,100)<<endl;
  M.inventura();
  cout<<endl<<M.stanjeNaRacunu<<endl;
  M.prodaj("lastavica").ispisi();
  cout<<endl<<M.stanjeNaRacunu<<endl;
  M.inventura();
  cout<<"Kraj"<<endl;
}
