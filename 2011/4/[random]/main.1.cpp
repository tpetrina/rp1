#include<iostream>
#include<cmath>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.01;
}
int main(){
  Random Y(1,3),Z(0,1);
  cout<<Y<<'|'<<Z<<endl<<a(~Y,2)<<'|'<<Y+Z<<endl;

  return 0;
}
