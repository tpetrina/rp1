#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  Tocka P(2,3),Q(-2,-3);
  Pravac p=P/Q;
  P.x=Q.y;
  P.y=Q.x;
  Tocka P1(P);
  (P%=p)|=p;
  cout<<z(P,P1|p)<<endl;
  Q%=p^=P1;
  cout<<z(Q,Tocka(-4.30769,-1.46154))<<endl;

  return 0;
}
