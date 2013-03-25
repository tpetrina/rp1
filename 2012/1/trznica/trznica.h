#pragma once

#include<string>

using namespace std;

struct Stand{
  string nam;
  int c;
  Stand();
  Stand(string namirnica,int cijena);
  void ispisi();
};

struct Trznica{
  Stand s[30][30][4];
  int m,n;
  Trznica(int m1,int n1);
  int dodaj(Stand S,int i,int j);
  int prazno();
  double putemTrosi(int p);
  Stand najjeftiniji(string namirnica);
  double najblizi(double x,double y);
};

