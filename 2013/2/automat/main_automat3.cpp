#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "automat.h"

using namespace std;

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
	
	A.dodaj("Rumko",10,4.50);A.dodaj("Kiki",5,7.50);A.dodaj("Bananko",15,2.50);A.dodaj("Orbit",10,4.50);
	A.dodaj("Dorina",5, 8.50);A.dodaj("Kiki",5,7);A.dodaj("Milka",5,10);
	
	ispisiListu(A.manjeOd(11));
	cout << endl;
	// 5 Dorina 6 Milka 1 Rumko 2 Kiki 5 Orbit
	// bitan redoslijed!
		
	return 0;
}
