#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "parking.h"

using namespace std;

void ispisiMapu(map<int, pair<string, int> > M){

	map<int, pair<string, int> >::iterator iter = M.begin();
	if(M.size() > 0){
		cout << iter->first << " " << iter->second.first << " " << iter->second.second;
		++iter;
		for(; iter!=M.end(); ++iter)
			cout << ", " << iter->first << " " << iter->second.first << " " << iter->second.second;
		cout << endl;
	}
	else cout << "Mapa je prazna" << endl;
}

void ispisiSkup(set<pair<int, string> > S){

	set<pair<int, string> >::iterator iter = S.begin();
	if(S.size() > 0){
		for(; iter != S.end(); ++iter)
			cout << iter->first << " " << iter->second << "   ";
		cout << endl;
	}
	else cout << "Skup je prazan" << endl;

}


int main(void){

	parking P;

	P.dodaj("ZG3172",4);P.dodaj("ZG2175",1);P.dodaj("KA5638",7);P.dodaj("DU6724",11);
	P.dodaj("DU1108",3);P.dodaj("SP9926",10);P.dodaj("ZG1112",3);P.dodaj("KA6610",1);
	P.dodaj("OS3346",24);P.dodaj("DU8023",2);P.dodaj("ZG3174",8);P.dodaj("KA0026",5);

	pair<int, int> blok = P.maxBlok();
	cout << blok.first << " " << blok.second << endl;
	// 0 0

	P.izbaci("ZG2175");P.izbaci("KA5638");P.izbaci("DU6724");P.izbaci("ZG3174");	
	P.izbaci("SP9926");P.izbaci("ZG1112");P.izbaci("KA6610");
	
	blok = P.maxBlok();
	cout << blok.first << " " << blok.second << endl;
	// 2 4

	P.dodaj("ZG2175",1);P.dodaj("KA5638",7);P.dodaj("DU6724",11);P.dodaj("SP9926",10);
	P.dodaj("ZG1112",3);P.dodaj("KA6610",1);
	
	blok = P.maxBlok();
	cout << blok.first << " " << blok.second << endl;
	// 11 11 

	return 0;
}
