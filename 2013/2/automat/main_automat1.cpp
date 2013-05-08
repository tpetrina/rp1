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
	A.izbaci("Bananko",17);

        cout<<(A.polica).count(3)<<endl;
	//0

	A.dodaj("Milka",2,10);
	cout << A.lokacija("Milka") << endl;
	//3
	
	return 0;
}
