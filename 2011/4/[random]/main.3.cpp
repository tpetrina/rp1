#include<iostream>
#include<cmath>
#include"random.h"
using namespace std;

bool a(double x,double y){
  return fabs(x-y)<0.01;
}
int main(){
  Random kocka(1,6),kocka2(1,6),novcic(0,1);
  cout<<kocka+kocka<<endl<<kocka+kocka2<<endl;
  cout<<kocka*novcic+novcic<<endl<<kocka-kocka2<<endl;
  cout<<(kocka==kocka2)<<(kocka==novcic);
  cout<<(kocka!=kocka)<<(kocka!=kocka2)<<endl;
  cout<<(kocka+kocka==kocka2*2)<<(kocka+kocka2==kocka*2)<<endl;
  cout<<(kocka<kocka)<<a(kocka<kocka2,5./12)<<a(kocka<3,1./3)<<endl;

  return 0;
}
