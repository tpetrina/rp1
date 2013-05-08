#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "parking.h"

using namespace std;

void ispisiListu(list<string> L){

	if(L.size() > 0){
		list<string>::iterator iter = L.begin();
		for(; iter != L.end(); ++iter)
			cout << *iter << "   ";
	}
	else cout << "Lista je prazna" << endl;
}


int main(void){

	parking P;

	P.dodaj("DU0005",1);P.dodaj("ZG0003",4);P.dodaj("ZG0004",1);P.dodaj("KA0002",7);P.dodaj("DU0001",11);
	
	list<string> L = P.preostaloVrijeme();
	ispisiListu(L);
	cout << endl;
	// DU0001 KA0002 ZG0003 ZG0004 DU0005 
	// bitan poredak
	return 0;
}
