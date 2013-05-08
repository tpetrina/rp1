#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "parking.h"

using namespace std;

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

	ispisiSkup(P.izGrada("DU"));
	// 4 DU6724   5 DU1108   10 DU8023

	ispisiSkup(P.izGrada("ST"));
	//Skup je prazan
	


	return 0;
}
