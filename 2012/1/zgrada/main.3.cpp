#include <iostream>
#include "zgrada.h"

using namespace std;

int main(){
  Stan S('a',3,20.3);
  Zgrada A(S);
  cout<<A.brojKatova()<<endl;
  cout<<A.dodaj(S)<<endl;
  cout<<A.brojKatova()<<endl;
  cout<<A.stabilna()<<endl;
}
