#include <iostream>
#include "poligon.h"

using namespace std;

int main( void )
{
	Poligon P;

	( P > make_pair( 1, 4 ) ) ^ make_pair( 1, -2 );
	( P > make_pair( 2, 0 ) ) ^ make_pair( 2, -2 );
	( P > make_pair( 3, 4 ) ) ^ make_pair( 3, -4 );
	( P > make_pair( 4, 1 ) ) ^ make_pair( 4, -4 );

	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// .2..1...
	// ........
	// ........
	// ..4.3...
	// ........
	// ........

	Poligon Q;
	( Q > make_pair( 3, 4 ) ) ^ make_pair( 3, -1 ); cout << (P==Q);
	( Q > make_pair( 4, 0 ) ) ^ make_pair( 4, -1 ); cout << (P==Q);
	( Q > make_pair( 1, 4 ) ) ^ make_pair( 1, -5 ); cout << (P==Q);
	( Q > make_pair( 2, 1 ) ) ^ make_pair( 2, -5 ); cout << (P==Q);

	++P;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// ....A...
	// ........
	// ........
	// ..4.3...
	// ........
	// ........
	P++;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// ....B...
	// ........
	// ........
	// ..4.....
	// ........
	// ........

	--P;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// ....B...
	// ........
	// ........
	// ..4.....
	// ........
	// ........

	( P > make_pair( 1, -7 ) ) > make_pair( 3, -2 );
	cout << P[ make_pair( 3, 3 ) ] << P[ make_pair( 3, 2 ) ] << P[ make_pair( 4, 3 ) ] << endl;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// 1x3.2...
	// ..x.....
	// ........
	// ..4.....
	// ........
	// ........

	--P; P++;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// 1xA.....
	// ..x.....
	// ........
	// ..4.....
	// ........
	// ........

	cout << P[ make_pair( 4, 3 ) ] << endl;
	P--;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// 1x3.....
	// ........
	// ........
	// ..A.....
	// ........
	// ........

	Poligon W;
	( W > make_pair( 1, 2 ) ) ^ make_pair( 1, -5 ); cout << (P==W);
	( W > make_pair( 2, 1 ) ) ^ make_pair( 2, -2 ); cout << (P==W);
	( W > make_pair( 3, 0 ) ) ^ make_pair( 3, -1 ); cout << (P==W);
	( W > make_pair( 4, 1 ) ) ^ make_pair( 4, -4 ); cout << (P==W);
	cout << endl;

	return 0;
}
