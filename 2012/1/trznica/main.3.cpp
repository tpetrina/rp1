#include <iostream>
#include "trznica.h"

using namespace std;

int main(){
  Stand njen("kupus",8);
  Stand moj("brusnica",40);
  Trznica Branimirova(10,7);
  cout<<Branimirova.dodaj(moj,5,7)<<endl;
  cout<<Branimirova.dodaj(njen,3,2)<<endl;
  cout<<Branimirova.dodaj(moj,2,1)<<endl;
  cout<<Branimirova.prazno()<<endl;
}
