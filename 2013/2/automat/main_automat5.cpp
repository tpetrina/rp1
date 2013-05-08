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
		typename set<T>::iterator iter = S.begin();
		for(; iter != S.end(); ++iter)
			cout << *iter << "   ";
		cout << endl;
	}
	else cout << "Skup je prazan" << endl;
	
}


int main(void){

	automat A;
	
	A.dodaj("Kiki",5,7.50);A.dodaj("Rumko",10,7.50);A.dodaj("Bananko",15,2.50);A.dodaj("Orbit",10,4.50);
	A.dodaj("Dorina",5, 8);A.dodaj("Kiki",5,7);A.dodaj("Milka",5,10);
	
	
	ispisiSkup(A.maxProizvod(1));
	// Skup je prazan
	
	ispisiSkup(A.maxProizvod(15));
	// Bananko  Kiki  Orbit
	
	return 0;
}
