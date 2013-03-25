#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Zgrada Z(Stan('a',0,30.1));
  Z.dodaj(Stan('b',1,29.6));
  Z.dodaj(Stan('c',3,42.1));
  Z.dodaj(Stan('d',2,25));
  Z.grijanje(8542.34);
  cout<<Z.brojKatova()<<Z.stabilna()<<endl;
}
