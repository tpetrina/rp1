#include <iostream>
#include <set>
#include <string>
#include <algorithm>
#include "poligon.h"

using namespace std;


struct __Pozicije
{
	int r[ 4 ], s[ 4 ];

	bool isFinal()
	{
		int minR = *min_element( r, r+4 ), minS = *min_element( s, s+4 );
		set<pair<int, int> > S, target;

		S.insert( make_pair( r[0] - minR, s[0] - minS ) );
		S.insert( make_pair( r[1] - minR, s[1] - minS ) );
		S.insert( make_pair( r[2] - minR, s[2] - minS ) );
		S.insert( make_pair( r[3] - minR, s[3] - minS ) );

		target.insert( make_pair( 0, 0 ) );
		target.insert( make_pair( 0, 1 ) );
		target.insert( make_pair( 1, 0 ) );
		target.insert( make_pair( 1, 1 ) );

		return S == target;
	}

	void idiDesno( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] )
	{
		int delta = ( x.second > 0 ? 1 : -1 );
		int pas = x.first-1;
		
		for( int i = 0; i != x.second; i += delta )
		{
			int rr = r[ pas ], ss = s[ pas ] + delta;
			if( !( 0 <= rr && rr <= 7 && 0 <= ss && ss <= 7 ) || prepreka[ rr ][ ss ] )
				break;
				
			r[ pas ] = rr; s[ pas ] = ss;
		}
	}


	void idiGore( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] )
	{
		int delta = ( x.second > 0 ? 1 : -1 );
		int pas = x.first-1;
		
		for( int i = 0; i != x.second; i += delta )
		{
			int rr = r[ pas ] - delta, ss = s[ pas ];
			if( !( 0 <= rr && rr <= 7 && 0 <= ss && ss <= 7 ) || prepreka[ rr ][ ss ] )
				break;
				
			r[ pas ] = rr; s[ pas ] = ss;
		}
	}
};


class MainPoligon : public Poligon
{
	int __brojPoziva;
	bool __prepreka[ 8 ][ 8 ];
	__Pozicije __pozicije;

public:
	MainPoligon()
	{
		for( int r = 0; r < 8; ++r )
			for( int s = 0; s < 8; ++s )
				__prepreka[ r ][ s ] = false;
				
		__pozicije.r[ 0 ] = 0; __pozicije.s[ 0 ] = 0;
		__pozicije.r[ 1 ] = 0; __pozicije.s[ 1 ] = 1;
		__pozicije.r[ 2 ] = 1; __pozicije.s[ 2 ] = 0;
		__pozicije.r[ 3 ] = 1; __pozicije.s[ 3 ] = 1;
	}

	MainPoligon &operator>( const pair<int, int> &x )
	{
		++__brojPoziva;
		
		if( 1 <= x.first && x.first <= 4 && -8 <= x.second && x.second <= 8 )
			__pozicije.idiDesno( x, __prepreka );

		Poligon::operator>( x );
		return *this;
	}

	MainPoligon &operator^( const pair<int, int> &x )
	{
		++__brojPoziva;
		if( 1 <= x.first && x.first <= 4 && -8 <= x.second && x.second <= 8 )
			__pozicije.idiGore( x, __prepreka );

		Poligon::operator^( x );
		return *this;
	}

	int __getBrojPoziva() { return __brojPoziva; }
	void __resetBrojPoziva() { __brojPoziva = 0; }
	bool __isFinal() { return __pozicije.isFinal(); }

	void __staviPrepreku( int r, int s ) { __prepreka[ r-1 ][ s-1 ] = true; }
	void __ispisiPozicije()
	{
		for( int pas = 0; pas < 4; ++pas )
			cout << "(" << __pozicije.r[pas]+1 << ", " << __pozicije.s[pas]+1 << ") ";
	}
};


void pripremiTest( MainPoligon &P, string test[] )
{
	int pas_r[] = { 0, 0, 1, 1 }, pas_s[] = { 0, 1, 0, 1 };

	for( int pas = 1; pas <= 4; ++pas )
		for( int r = 0; r < 8; ++r )
			for( int s = 0; s < 8; ++s )
				if( test[ r ][ s ] == pas + '0' )
				{
					P ^ make_pair( pas, -r + pas_r[ pas-1 ] );
					P > make_pair( pas, s - pas_s[ pas-1 ] );
				}

	for( int r = 0; r < 8; ++r )
		for( int s = 0; s < 8; ++s )
			if( test[ r ][ s ] == 'x' )
			{
				P.__staviPrepreku( r+1, s+1 );
				P[ make_pair( r+1, s+1 ) ];
			}
}


int main( void )
{
	{
		MainPoligon P;
		
		string test[] = {
			"........",
			".1......",
			"......3.",
			"........",
			".......4",
			"........",
			"....2...",
			"........" };

		pripremiTest( P, test );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			if( P.__isFinal() )
				cout << "OK" << endl << endl;
			else
			{
				cout << "psi nisu na dobroj konacnoj poziciji: dovedeni su na ";
				P.__ispisiPozicije();
				cout << endl;
			}
		}
		else
			cout << "ne moze dovesti pse na konacnu poziciju" << endl;
	}

	{
		MainPoligon P;
		
		string test[] = {
			"........",
			"....x...",
			"....x3..",
			"....x...",
			"....x...",
			"...1x...",
			"....x.4.",
			"......2." };

		pripremiTest( P, test );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			if( P.__isFinal() )
				cout << "OK" << endl << endl;
			else
			{
				cout << "psi nisu na dobroj konacnoj poziciji: dovedeni su na ";
				P.__ispisiPozicije();
				cout << endl;
			}
		}
		else
			cout << "ne moze dovesti pse na konacnu poziciju" << endl;
	}

	{
		MainPoligon P;
		
		string test[] = {
			"........",
			"...4....",
			"....xx..",
			"..xx....",
			".x31x..x",
			".x2.x..x",
			"..x.....",
			"..x.x..." };

		pripremiTest( P, test );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			if( P.__isFinal() )
				cout << "OK" << endl << endl;
			else
			{
				cout << "psi nisu na dobroj konacnoj poziciji: dovedeni su na ";
				P.__ispisiPozicije();
				cout << endl;
			}
		}
		else
			cout << "ne moze dovesti pse na konacnu poziciju" << endl;
	}

	return 0;
}
