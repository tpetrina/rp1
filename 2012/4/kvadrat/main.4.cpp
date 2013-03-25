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
	Kvadrat K, L;

	K > make_pair( 1, 3 );
	K ^ make_pair( 4, 1 );
	ispis( K );
	cout << endl;

	L ^ make_pair( 4, 2 );
	L ^ make_pair( 3, 1 );
	ispis( L );
	cout << endl;

	cout << "( K == L ) -> " << ( K == L ) << endl;
	cout << "K( 3 ) -> " << K[ "3" ].first << " " << K[ "3" ].second << endl;
	cout << "L( 2 ) -> " << L[ "2" ].first << " " << L[ "2" ].second << endl;
	cout << "K( 12 ) -> " << K[ "12" ].first << " " << K[ "12" ].second << endl;
	cout << "L( 7 ) -> " << L[ "7" ].first << " " << L[ "7" ].second << endl;
	cout << endl;

	++K;
	L--;
	K++;
	L--;
	K--;
	++L;

	ispis( K );
	cout << endl;
	ispis( L );
	cout << endl;

	( ( ( ( K > make_pair( 3, 1 ) ) > make_pair( 1, 2 ) ) ^ make_pair( 1, 1 ) ) ^ make_pair( 2, 3 ) ) > make_pair( 2, 2 );
	( ( ( ( L ^ make_pair( 3, 1 ) ) ^ make_pair( 1, 2 ) ) > make_pair( 1, 1 ) ) > make_pair( 2, 3 ) ) > make_pair( 2, 2 );

	ispis( K );
	cout << endl;
	ispis( L );
	cout << endl;

	cout << "( K == L ) -> " << ( K == L ) << endl;
	cout << "K( 3 ) -> " << K[ "3" ].first << " " << K[ "3" ].second << endl;
	cout << "L( 2 ) -> " << L[ "2" ].first << " " << L[ "2" ].second << endl;
	cout << "K( 12 ) -> " << K[ "12" ].first << " " << K[ "12" ].second << endl;
	cout << "L( 7 ) -> " << L[ "7" ].first << " " << L[ "7" ].second << endl;

	return 0;
}
