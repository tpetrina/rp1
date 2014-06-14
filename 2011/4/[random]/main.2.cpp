#include<iostream>
#include<cmath>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.01;
}
int main(){
  Random Y(1,3),Z(-2,1),W(5);
  cout<<Y*Z<<endl<<Y-Z<<endl;
  cout<<a(*Z,5./4)<<a(Z=-1,1./4);
  cout<<a(Z=-3,0)<<a(*W,0)<<a(Y<Random(3),2./3)<<endl;

  return 0;
}
