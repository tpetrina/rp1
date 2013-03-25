#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "automat.h"

using namespace std;

template <class T>
void ispisiSkup(set<T> S){
	
	if(S.size() > 0){
		set<T>::iterator iter = S.begin();
		for(; iter != S.end(); ++iter)
			cout << *iter << "   ";
		cout << endl;
	}
	else cout << "Skup je prazan" << endl;
	
}

void ispisiListu(list<pair<int,string> > L){

	if(L.size() > 0){
		list<pair<int,string> >::iterator iter = L.begin();
		for(; iter != L.end(); ++iter)
			cout << iter->first << " " << iter->second << "   ";
	}
	else cout << "Lista je prazna" << endl;
}

int main(void){

	automat A;
	
	A.dodaj("Kiki",5,7.50);A.dodaj("Rumko",10,4.50);A.dodaj("Bananko",15,2.50);A.dodaj("Orbit",10,4.50);
	A.dodaj("Dorina",5, 8.50);A.dodaj("Kiki",5,7);A.dodaj("Milka",5,10);
	
	cout << A.cijena["Kiki"] << endl;
	// 7
	
	A.izbaci("Bananko",5); A.izbaci("Dorina",5); A.izbaci("Orbit",2);
	
	ispisiListu(A.manjeOd(10));
	cout << endl;
	// 6 Milka   4 Orbit
	
	vector<pair<string, int>> V;
	V.push_back(pair<string, int>("Rumko",3)); V.push_back(pair<string, int>("Milka",1));
	cout << A.naplata(V) << endl;
	// 23.5
	
	ispisiSkup(A.maxProizvod(8.50));
	// Bananko Orbit
	
	return 0;
}
