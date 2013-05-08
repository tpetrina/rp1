#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include "parking.h"

using namespace std;


int main(void){

	parking P;

	P.dodaj("ZG3172",4);P.dodaj("ZG2175",1);P.dodaj("KA5638",7);
	
	P.izbaci("ZG2175");
	
//	cout << P.nadi("ZG2175") << endl;
	// 0 
	
	cout << P.mapaParking.count(2) << endl;
	// 0
	
	P.dodaj("RI1234",3);
	
	cout << P.nadi("RI1234") << endl;
	// 2

	return 0;
}
