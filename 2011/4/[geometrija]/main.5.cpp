#include<iostream>
#include<cmath>
#include"geometrija.h"
using namespace std;

bool z(const Tocka& A,const Tocka& B){
  return fabs(A.x-B.x)<0.001&&fabs(A.y-B.y)<0.001;
}
int main(){
  const Tocka ishodiste,Ex(1,0),Ey(0,1);
  cout<<Ey.x<<endl;
  const Pravac osx=ishodiste/Ex,osy=ishodiste/Ey;
  cout<<(fabs((osx^osy)-M_PI/2)<0.001)<<endl;
  Tocka A(1,2),B(1,4);
  cout<<(fabs(ishodiste-A/B-1)<0.001)<<endl;

  return 0;
}
