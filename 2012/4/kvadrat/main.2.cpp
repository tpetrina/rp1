#include <iostream>
#include <iomanip>
#include <string>
#include "kvadrat.h"

using namespace std;

void ispis( Kvadrat &K )
{
	for( int r = 1; r <= 4; ++r, cout << endl )
		for( int s = 1; s <= 4; ++s )
			cout << setw( 2 ) << K( r, s ) << " ";
}

int main( void )
{
	Kvadrat K;

	++K;
	ispis( K );
	cout << endl;

	K ^ make_pair( 1, 3 );
	ispis( K );
	cout << endl;

	K--;
	ispis( K );
	cout << endl;

	K > make_pair( 4, 1 );
	ispis( K );
	cout << endl;

	K++;
	ispis( K );
	cout << endl;

	K ^ make_pair( 2, 2 );
	ispis( K );
	cout << endl;

	--K;
	ispis( K );
	cout << endl;

	return 0;
}
