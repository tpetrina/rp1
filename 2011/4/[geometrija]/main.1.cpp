#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  Tocka A(-3.2,4.1),B,C(0.3,-0.1);
  
  cout<<z(A/C+C/B,C)<<endl;
  B.x=3;cout<<B<<endl;
  
  return 0;
}
