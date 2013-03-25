#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Stan S('a',1,40);
  S.ispisi();
  Zgrada Z(S);
  cout<<endl<<Z.brojKatova()<<'\t'<<Z.stabilna()<<endl;
  Z.dodaj(S);
  cout<<Z.brojKatova()<<'\t'<<Z.stabilna()<<endl;
  Z.dodaj(Stan('c',2,30));
  cout<<Z.brojKatova()<<'\t'<<Z.stabilna()<<endl;
  Z.grijanje(1111.11);
  cout<<"Zima"<<endl;
  Z.grijanje(3649.23);
}
