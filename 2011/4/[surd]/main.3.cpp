#include<iostream>
#include"surd.h"
using namespace std;

int main(){
  cout<<Surd(3,1,8)<<endl;
  cout<<Surd(-4,-5,-9)<<endl;
  cout<<Surd(4,5,9)-Surd(3,2,4)<<endl;
  cout<<Surd(-5,0,3)*Surd(4,-5,6)-Surd(2,3,24)<<endl;
  cout<<Surd(1,2,0)+Surd(2,3,5)<<endl;
  cout<<Surd(0,5,6)*Surd(0,-3,2)<<endl;
  Surd d(1,5,4);
  cout<<*d<<endl<<~d<<endl;
  cout<<++d<<endl<<d++<<endl<<(d^4)<<endl;

  return 0;
}
