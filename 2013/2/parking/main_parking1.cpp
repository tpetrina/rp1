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
	
	P.istekaoSat(); P.istekaoSat(); 

	cout << P.mapaParking[2].second << endl;
	// 0
	
	cout << P.izbaci("ZG2175") << " " << P.izbaci("KA5638") << endl;
	// 1 0

	return 0;
}
