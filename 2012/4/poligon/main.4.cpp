#include <iostream>
#include "poligon.h"

using namespace std;

int main( void )
{
	Poligon P;

	( P > make_pair( 1, 4 ) ) ^ make_pair( 1, -2 );
	( P > make_pair( 2, 0 ) ) ^ make_pair( 2, -2 );
	( P > make_pair( 3, 6 ) ) ^ make_pair( 3, -1 );
	( P > make_pair( 4, 2 ) ) ^ make_pair( 4, -1 );

	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// .2.41.3.
	// ........
	// ........
	// ........
	// ........
	// ........
	++P;
	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}
	// ........
	// ........
	// .2.4..A.
	// ........
	// ........
	// ........
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
	// .A.4..3.
	// ........
	// ........
	// ........
	// ........
	// ........

	( P ^ make_pair( 4, -3 ) ) > make_pair( 4, 3 );
	// ........
	// ........
	// .A....3.
	// ........
	// ........
	// ......4.
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
	// .A....B.
	// ........
	// ........
	// ........
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
	// .C....4.
	// ........
	// ........
	// ........
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
	// .D......
	// ........
	// ........
	// ........
	// ........
	// ........

	cout << P( "123" ).first << P( "poligon" ).first << P( "5" ).first << P( "0" ).first << endl;

	return 0;
}
