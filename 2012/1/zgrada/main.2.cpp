#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Stan S('B',2,50.512);
  S.ispisi();
  cout<<endl;
  Stan P('#',0,0.1);
  P.ispisi();
  cout<<endl;
}
