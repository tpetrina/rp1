#include <iostream>
#include <map>
#include <set>
#include <list>
#include <string>
#include <utility>
#include <vector>
#include "automat.h"

using namespace std;


int main(void){

	automat A;
	
	A.dodaj("Kiki",5,7.50);A.dodaj("Rumko",10,4.50);A.dodaj("Bananko",15,2.50);A.dodaj("Orbit",10,4.50);
	A.dodaj("Dorina",5, 8.50);A.dodaj("Kiki",5,7);A.dodaj("Milka",5,10);
	
	vector<pair<string, int> > V;
	V.push_back(pair<string, int>("Rumko",11)); V.push_back(pair<string, int>("Milka",1));V.push_back(pair<string, int>("Coksa",3));V.push_back(pair<string, int>("Bananko",0));
	cout << A.naplata(V) << endl;
	// 55
	
	return 0;
}
