#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.01;
}
int main(){
  stringstream ss;
  Random X(5,-6);
  char c,d,e;
  int i,j;
  string s;
  ss<<X;
  ss>>i>>c>>j>>d>>e>>s;
  cout<<i<<c<<j<<d<<e<<endl;
  cout<<s.substr(5,10)<<endl;

  return 0;
}
