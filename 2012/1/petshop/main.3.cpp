#include <iostream>
#include "petshop.h"

using namespace std;

int main(){
  PetShop M(12345,.01);
  cout<<M.stanjeNaRacunu<<endl;
  M.inventura();
  cout<<"Kraj"<<endl;
}
