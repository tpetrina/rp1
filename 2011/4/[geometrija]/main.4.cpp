#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  Tocka O,A(2.6,2),B(-1.3,-1);
  Pravac p=A/B;
  cout<<(fabs(O-p)<0.001)<<endl;
  A.x+=3;B.x+=3;
  cout<<(p||A/B)<<(p==A/B)<<endl;
  A|=p;B%=p;
  Tocka R1(4.48476,3.44981),R2(-0.530483,1.89963);
  cout<<z(A,R1)<<z(B,R2)<<endl;
  cout<<(fabs(O-(p^=B)-1.82913)<0.001)<<endl;

  return 0;
}
