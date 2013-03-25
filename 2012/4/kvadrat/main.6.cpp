#include <iostream>
#include <iomanip>
#include <string>
#include "kvadrat.h"

using namespace std;

class MainKvadrat : public Kvadrat
{
	int __brojPoziva;
	int __M[ 16 ];
	
	void __rot( int perm[], int duljina )
	{
		int temp = __M[ perm[ duljina-1 ] ];
		for( int i = duljina-1; i > 0; --i )
			__M[ perm[ i ] ] = __M[ perm[ i-1 ] ];
		__M[ perm[ 0 ] ] = temp;
	}

public:
	MainKvadrat() { __brojPoziva = 0; }
	int __getBrojPoziva() { return __brojPoziva; }

	MainKvadrat &operator>( const pair<int, int> &x )
	{
		++__brojPoziva;
		int perm[ 4 ];
		for( int i = 0; i < 4; ++i )
			perm[ i ] = (x.first-1)*4 + i;
		
		for( int i = 0; i < x.second; ++i )
			__rot( perm, 4 );

		
		Kvadrat::operator>( x );
		return *this;
	}

	MainKvadrat &operator^( const pair<int, int> &x )
	{
		++__brojPoziva;
		int perm[ 4 ];
		for( int i = 0; i < 4; ++i )
			perm[ i ] = 4*(3-i) + x.first-1;
		
		for( int i = 0; i < x.second; ++i )
			__rot( perm, 4 );
		
		Kvadrat::operator^( x );
		return *this;
	}

	void __set( int r, int s, int value )
	{
		__M[ 4*(r-1) + s-1 ] = value;

		(*this)( r, s ) = value;
	}

	void __printout()
	{
		for( int r = 1; r <= 4; ++r, cout << endl )
			for( int s = 1; s <= 4; ++s )
				cout << setw(2) << __M[ 4*(r-1) + s-1 ] << " ";
	}
};


int main( void )
{
	{
		MainKvadrat K;

		K.__set( 1, 1, 14 ); K.__set( 1, 2, 4 ); K.__set( 1, 3,  7 ); K.__set( 1, 4, 16 );
		K.__set( 2, 1, 15 ); K.__set( 2, 2, 2 ); K.__set( 2, 3,  6 ); K.__set( 2, 4, 11 );
		K.__set( 3, 1,  1 ); K.__set( 3, 2, 3 ); K.__set( 3, 3,  5 ); K.__set( 3, 4, 13 );
		K.__set( 4, 1,  9 ); K.__set( 4, 2, 8 ); K.__set( 4, 3, 12 ); K.__set( 4, 4, 10 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	{
		MainKvadrat K;

		K.__set( 1, 1,  4);  K.__set( 1, 2,  9 ); K.__set( 1, 3, 14 ); K.__set( 1, 4,  7 );
		K.__set( 2, 1, 11 ); K.__set( 2, 2, 13 ); K.__set( 2, 3,  2 ); K.__set( 2, 4, 15 );
		K.__set( 3, 1,  5 ); K.__set( 3, 2,  1 ); K.__set( 3, 3,  8 ); K.__set( 3, 4, 16 );
		K.__set( 4, 1, 10 ); K.__set( 4, 2, 12 ); K.__set( 4, 3,  3 ); K.__set( 4, 4,  6 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	{
		MainKvadrat K;

		K.__set( 1, 1,  1 );  K.__set( 1, 2,  2 ); K.__set( 1, 3,  3 ); K.__set( 1, 4,  4 );
		K.__set( 2, 1,  5 );  K.__set( 2, 2,  6 ); K.__set( 2, 3,  7 ); K.__set( 2, 4,  8 );
		K.__set( 3, 1,  9 );  K.__set( 3, 2, 10 ); K.__set( 3, 3, 11 ); K.__set( 3, 4, 12 );
		K.__set( 4, 1, 13 );  K.__set( 4, 2, 14 ); K.__set( 4, 3, 16 ); K.__set( 4, 4, 15 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	return 0;
}
