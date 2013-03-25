#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Zgrada Z(Stan('a',0,30.1));
  cout<<Z.dodaj(Stan('d',1,29.6));
  cout<<Z.dodaj(Stan('c',3,42.1));
  cout<<Z.dodaj(Stan('b',1,25))<<endl;
  Z.grijanje(543.07);
  cout<<Z.brojKatova()<<Z.stabilna()<<endl;
}
