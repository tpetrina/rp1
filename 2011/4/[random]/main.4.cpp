#include<iostream>
#include<cmath>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.0001;
}
int main(){
  Random X(0,999),Y(X),S(0);
  cout<<a(X+Y<99,99./20000);
  cout<<a(X+X=0,1./1000);
  cout<<a(X<Y,Y<X)<<endl;
  for(int i=0;i<10;++i)S=S+Random(0,1);
  cout<<S<<endl;

  return 0;
}
