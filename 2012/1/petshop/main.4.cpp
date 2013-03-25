#include <iostream>
#include "petshop.h"

using namespace std;

int main(){
  PetShop M(12121,.25);
  cout<<M.dopremi("sismis",100,10)<<endl;
  cout<<M.dopremi("divlja svinja",1,3000)<<endl;
  cout<<M.dopremi("nosorog",10,2000)<<endl;
  cout<<M.dopremi("lastavica",11,10)<<endl;
  cout<<M.dopremi("slon",1,8000)<<endl;
  cout<<M.dopremi("mrav",2000,.12)<<endl;
  double a=M.stanjeNaRacunu;
  cout<<(a>0)<<(a<0.1)<<endl;
}
