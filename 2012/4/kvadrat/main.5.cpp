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
		// K > make_pair( 3, 2 );
		// K ^ make_pair( 1, 3 );
		// 13  2  3  4
		//  1  6  7  8
		//  5 12  9 10
		// 11 14 15 16
		K.__set( 1, 1, 13 ); K.__set( 1, 2,  2 ); K.__set( 1, 3,  3 ); K.__set( 1, 4,  4 );
		K.__set( 2, 1,  1 ); K.__set( 2, 2,  6 ); K.__set( 2, 3,  7 ); K.__set( 2, 4,  8 );
		K.__set( 3, 1,  5 ); K.__set( 3, 2, 12 ); K.__set( 3, 3,  9 ); K.__set( 3, 4, 10 );
		K.__set( 4, 1, 11 ); K.__set( 4, 2, 14 ); K.__set( 4, 3, 15 ); K.__set( 4, 4, 16 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	{
		MainKvadrat K;
		// K > make_pair( 4, 2 );
		// K ^ make_pair( 2, 1 );
		// K > make_pair( 1, 3 );
		//  6  3  4  1
		//  5 10  7  8
		//  9 16 11 12
		// 15  2 13 14

		K.__set( 1, 1,  6 ); K.__set( 1, 2,  3 ); K.__set( 1, 3,  4 ); K.__set( 1, 4,  1 );
		K.__set( 2, 1,  5 ); K.__set( 2, 2, 10 ); K.__set( 2, 3,  7 ); K.__set( 2, 4,  8 );
		K.__set( 3, 1,  9 ); K.__set( 3, 2, 16 ); K.__set( 3, 3, 11 ); K.__set( 3, 4, 12 );
		K.__set( 4, 1, 15 ); K.__set( 4, 2,  2 ); K.__set( 4, 3, 13 ); K.__set( 4, 4, 14 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	{
		MainKvadrat K;
		// K ^ make_pair( 2, 3 );
		// K > make_pair( 1, 1 );
		// K > make_pair( 4, 2 );
		// K ^ make_pair( 3, 2 );
		//  4  1 11  3
		//  5  2 13  8
		//  9  6 14 12
		// 15 16  7 10

		K.__set( 1, 1,  4 );  K.__set( 1, 2,  1 ); K.__set( 1, 3, 11 ); K.__set( 1, 4,  3 );
		K.__set( 2, 1,  5 );  K.__set( 2, 2,  2 ); K.__set( 2, 3, 13 ); K.__set( 2, 4,  8 );
		K.__set( 3, 1,  9 );  K.__set( 3, 2,  6 ); K.__set( 3, 3, 14 ); K.__set( 3, 4, 12 );
		K.__set( 4, 1, 15 );  K.__set( 4, 2, 16 ); K.__set( 4, 3,  7 ); K.__set( 4, 4, 10 );

		cout << "prije:" << endl; K.__printout();
		!K;
		cout << "poslije:" << endl; K.__printout();
		cout << ( ( K.__getBrojPoziva() < 1000 ) ? "OK" : "previse poziva" ) << endl << endl;
	}

	return 0;
}
