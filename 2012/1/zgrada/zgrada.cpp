#include "zgrada.h"

#include<iostream>
#include<iomanip>

using namespace std;

Stan::Stan(char id1,int kat1,double povrsina){
    id=id1;kat=kat1;povr=povrsina;
  }
  
Stan::Stan(){id='\0';kat=0;povr=0;}

void Stan::ispisi(){
    cout<<kat<<'/'<<id;
  }

Zgrada::Zgrada(Stan S0){
    S0.kat=0;s[0]=S0;bs=1;bk=0;
  }
  
int Zgrada::brojKatova(){return bk;}

bool Zgrada::dodaj(Stan S){
    if(S.kat<=bk+1){
      s[bs++]=S;
      if(S.kat>bk)++bk;
    }
    return S.kat<=bk;
  }
  
bool Zgrada::stabilna(){
    double pk[1000]={0};
    int i;
    for(i=0;i<bs;++i)pk[s[i].kat]+=s[i].povr;
    for(i=0;i<bk;++i)if(pk[i]<pk[i+1])return false;
    return true;
  }
  
void Zgrada::grijanje(double iznos){
    double up=0;
    int i,j;
    for(i=0;i<bs;++i)for(j=0;j<i;++j)
      if(s[i].kat<s[j].kat||
         s[i].kat==s[j].kat&&s[i].id<s[j].id){
           Stan t=s[i];s[i]=s[j];s[j]=t;
      }
    for(i=0;i<bs;++i)up+=s[i].povr;
    for(i=0;i<bs;++i){
      s[i].ispisi();
      double pl=iznos/up*s[i].povr*100;
      //cout<<'<'<<pl<<'|'<<pl-(int)pl<<'>'<<endl;
      int plc=pl;
      if(plc<pl)++plc;
      cout<<'\t'<<setw(4)<<plc/100<<','
          <<setw(2)<<setfill('0')<<plc%100
          <<setfill(' ')<<"Kn"<<endl;
    }
  }

