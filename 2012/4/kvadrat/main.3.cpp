#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
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

	K > make_pair( 3, 2 );
	K ^ make_pair( 3, 2 );
	ispis( K );
	cout << endl;

	for( int i = 0; i <= 17; ++i )
	{
		char s[ 10 ];
		sprintf( s, "%d", i );
		pair<int, int> p = K[ string( s ) ];
		cout << "(" << p.first << ", " << p.second << ") ";
	}

	cout << endl << ( K == Kvadrat() ) << endl;

	return 0;
}
