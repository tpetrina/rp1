#include <iostream>
#include "trznica.h"

using namespace std;

int main(){
  Stand Barica("sir",10),Jela("jabuka",7);
  Barica.ispisi();
  Trznica Dolac(5,8);
  cout<<endl<<Dolac.dodaj(Jela,3,4)<<'\t';
  cout<<Dolac.dodaj(Jela,4,7)<<'\t';
  cout<<Dolac.dodaj(Barica,3,4)<<'\t';
  cout<<Dolac.dodaj(Barica,0,0)<<endl;
  for(int p=-2;p<20;++p)cout<<Dolac.putemTrosi(p)<<' ';
  cout<<endl<<Dolac.prazno()<<endl;
  Dolac.najjeftiniji("sir").ispisi();cout<<endl;
  Dolac.najjeftiniji("kupus").ispisi();cout<<endl;
  cout<<Dolac.najblizi(4,-7)<<endl;
  cout<<Dolac.najblizi(0,0)<<endl;
}
