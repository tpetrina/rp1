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
	
	A.dodaj("Kiki",5,7.50);	A.dodaj("Dorina",5, 8.50);A.dodaj("Kiki",5,7);
	A.izbaci("Kiki",1);
	
	cout << A.polica[A.lokacija("Kiki")].second << endl;
	//9
	
	cout << A.cijena["Kiki"] << endl;
	// 7
	
	return 0;
}
