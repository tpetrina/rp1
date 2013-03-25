#include "petshop.h"

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

Ljubimac::Ljubimac(){vr="";c=0;}

Ljubimac::Ljubimac(string vrsta,double cijena){
    vr=vrsta;c=cijena;
  }

void Ljubimac::ispisi(){
    int cc=c*100;
    if(cc<c*100)++cc;
    cout<<vr<<": "<<cc/100<<','<<setw(2)
        <<setfill('0')<<cc%100<<"Kn";
  }

PetShop::PetShop(double pocetniKapital,double marza){
    stanjeNaRacunu=pocetniKapital;mar=marza;bl=0;
  }
  
int PetShop::dopremi(string vrsta,int koliko,double nabavna){
    double pc=nabavna*(1+mar)*100;
    int i,plc=pc;
    if(plc<pc)++plc;
    int dop=stanjeNaRacunu/nabavna;
    if(dop>koliko)dop=koliko;
    stanjeNaRacunu-=dop*nabavna;
    for(i=0;i<dop;++i)
      p[bl++]=Ljubimac(vrsta,plc/100.);
    return dop;
  }
  
Ljubimac PetShop::prodaj(string trazeno){
    int i,n=-1;
    Ljubimac t;
    for(i=0;i<bl;++i)
      if(p[i].vr.find(trazeno)!=string::npos
         &&(t.c==0||p[i].c<t.c))t=p[n=i];
    if(n>-1){
      --bl;
      for(i=n;i<bl;++i)p[i]=p[i+1];
      stanjeNaRacunu+=t.c;
    }else cout<<"nema "<<trazeno;
    return t;
  }
  
void PetShop::inventura(){
    for(int i=0;i<bl;++i){p[i].ispisi();cout<<endl;}
  }

