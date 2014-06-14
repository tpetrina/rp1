#include<iostream>
#include<cmath>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.01;
}
int main(){
  const Random X(0,4);
  Random Y=X;
  cout<<a(~X,2)<<a(X=0,1./5)<<(X==Y)<<endl;
  cout<<a(X<Y,2./5)<<a(1<X,3./5)<<endl;
  cout<<X<<endl<<Y<<endl<<(X!=X)<<(X!=Y)<<a(*X,2)<<endl;

  return 0;
}
