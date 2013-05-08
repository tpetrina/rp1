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

	P.istekaoSat(); P.istekaoSat(); 

	cout << P.izbaci("ZG1112") << endl;
	// 0

	P.izbaci("ZG3174"); P.dodaj("ZG0032",3);

	ispisiMapu(P.mapaParking);
	// 1 ZG3172 2, 2 ZG2175 0, 3 KA5638 5, 4 DU6724 9, 5 DU1108 1, 6 SP9926 8, 7 ZG0032 3, 8 KA6610 0, 9 OS3346 22, 10 DU8023 0, 12 KA0026 3

	list<string> L = P.preostaloVrijeme();
	cout << L.front() << endl;
	// OS3346

	ispisiSkup(P.izGrada("DU"));
	// 4 DU6724   5 DU1108   10 DU8023

	P.izbaci("DU8023"); P.izbaci("ZG2175"); P.izbaci("DU1108"); P.izbaci("SP9926");

	pair<int, int> blok = P.maxBlok();
	cout << blok.first << " " << blok.second << endl;
	// 5 6


	return 0;
}
