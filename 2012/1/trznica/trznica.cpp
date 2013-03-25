#include "trznica.h"

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

Stand::Stand(){nam="";c=0;}

Stand::Stand(string namirnica,int cijena){
    nam=namirnica;c=cijena;
  }
  
void Stand::ispisi(){cout<<nam<<" ["<<c<<"Kn]";}

Trznica::Trznica(int m1,int n1){m=m1;n=n1;}

int Trznica::dodaj(Stand S,int i,int j){
    int k;
    if(i<0||j<0||i>=m||j>=n)return 0;
    for(k=0;k<4&&s[i][j][k].c>0;++k);
    if(k<4)s[i][j][k]=S;
    return k;
  }
  
int Trznica::prazno(){
    int br=0;
    for(int i=0;i<m;++i)for(int j=0;j<n;++j)
      if(!s[i][j][0].c)++br;
    return br;
  }
  
double Trznica::putemTrosi(int p){
    int tr=0,j,k;
    for(j=0;j<n;++j)for(k=0;k<4;++k){
      if(p>0&&p<=m)tr+=s[p-1][j][k].c;
      if(p>=0&&p<m)tr+=s[p][j][k].c;
    }
    return tr;
  }
  
Stand Trznica::najjeftiniji(string namirnica){
    Stand t;
    int i,j,k;
    for(i=0;i<m;++i)for(j=0;j<n;++j)for(k=0;k<4;++k)
      if(s[i][j][k].nam==namirnica
        &&(t.c==0||s[i][j][k].c<t.c))t=s[i][j][k];
    return t;
  }
  
double Trznica::najblizi(double x,double y){
    int i,j;
    double md=-1;
    for(i=0;i<m;++i)for(j=0;j<n;++j)if(s[i][j][0].c){
      double dx=x-j,dy=y+i;
      double d=sqrt(dx*dx+dy*dy);
      if(md==-1||md>d)md=d;
    }
    return md;
  }

