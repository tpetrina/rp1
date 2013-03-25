#include <iostream>
#include "poligon.h"

using namespace std;

int main( void )
{
	Poligon P;

	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}

	P > make_pair( 2, 1 );
	P ^ make_pair( 3, -4 );
	P > make_pair( 4, 5 );
	P ^ make_pair( 1, -3 );

	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}

	P > make_pair( 4, 3 );
	P ^ make_pair( 2, -1 );
	P > make_pair( 1, 3 );
	P ^ make_pair( 3, 2 );

	cout << endl;
	for( int pas = 1; pas <= 4; ++pas )
	{
		pair<int, int> pozicija = P( string( 1, pas+'0' ) );
		cout << "Pas " << pas << ": pozicija (" << pozicija.first << ", " << pozicija.second << ")" << endl;
	}

	return 0;
}
