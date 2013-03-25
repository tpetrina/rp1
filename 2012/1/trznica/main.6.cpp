#include <iostream>
#include "trznica.h"

using namespace std;

int main(){
  Stand temp("a",1);
  Trznica mega(30,30);
  cout<<mega.najblizi(5,5)<<endl;
  for(int i=0;i<30;++i)
    for(int j=0;j<30;++j)
      for(int k=0;k<(i*i*j*j+2)%3;++k)
        mega.dodaj(temp,i,j);
  cout<<mega.prazno()<<endl;
  cout<<mega.najblizi(1,-1)<<endl;
  double a=mega.najblizi(1.5,-1.5);
  double b=a*a*2-5;
  if(b<0)b=-b;
  cout<<(b<1e-7)<<endl;
  a=mega.najblizi(-3,1);b=a*a-10;
  if(b<0)b=-b;
  cout<<(b<1e-7)<<endl;
}
