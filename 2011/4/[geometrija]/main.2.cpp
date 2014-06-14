#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  Tocka A(-3.2,4.1),B(A),O;
  Pravac xo=O/O;
  cout<<(A/B||xo)<<(A/B==A/A)<<(O/B||A/B)<<(A/B==xo);
  cout<<((A/B^xo)<.001)<<endl;B.y=2.4;
  cout<<(fabs((O/A^O/B)-0.264566)<.001)<<endl;
  cout<<xo+xo<<z(xo+xo,xo+A/A)<<endl;

  return 0;
}
