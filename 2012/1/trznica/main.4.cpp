#include <iostream>
#include "trznica.h"

using namespace std;

int main(){
  Stand njen("kupus",8);
  Stand moj("brusnica",40);
  Trznica NZ(20,26);
  for(int i=0;i<6;++i)cout<<NZ.dodaj(moj,5,18)<<'\t';
  cout<<endl;
  for(int i=0;i<6;++i)cout<<NZ.dodaj(njen,25,18)<<'\t';
  cout<<endl;
  cout<<NZ.prazno();
  NZ.najjeftiniji("kupus").ispisi();cout<<endl;
  NZ.najjeftiniji("brusnica").ispisi();cout<<endl;
}
