#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  Tocka A(3.2,4.1),B(3.2,0.1),C(-1.2,-0.1);
  Pravac va=A/(A|B/C),vb=B/(B|A/C),vc=C/(C%(A/B));
  Tocka S1=va+vb,S2=va+vc,S3=vb+vc;
  cout<<z(S1,S2)<<z(S2,S3)<<z(S1,S3)<<endl;

  return 0;
}
