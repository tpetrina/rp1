#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Zgrada K(Stan('a',0,100));
  for(int i=1;i<618;++i)K.dodaj(Stan('z'-i%25,i/25,1e4/i));
  cout<<K.stabilna()<<'\t'<<K.brojKatova()<<endl;
  K.dodaj(Stan('a',15,47));
  cout<<K.stabilna()<<'\t'<<K.brojKatova()<<endl;
}

