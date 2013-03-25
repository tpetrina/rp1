#include <iostream>
#include <cstdlib>
#include "ploca.h"

using namespace std;

enum __orjentacija { __horizontalna, __vertikalna };
enum __strana { __plava, __crvena };

struct __Figurica
{
	int r, s;
	__strana str;
	__orjentacija orj;

	void operator++()
	{
		str = __strana(!str);
		
		if( orj == __horizontalna )
			s += 2;
		else
			s += 1;
	}

	void operator--()
	{
		str = __strana(!str);
		if( orj == __horizontalna )
			s -= 2;
		else
			s -= 1;
	}

	void operator++(int)
	{
		str = __strana(!str);
		
		if( orj == __horizontalna )
			r -= 1;
		else
			r -= 2;	
	}

	void operator--(int)
	{
		str = __strana(!str);
		
		if( orj == __horizontalna )
			r += 1;
		else
			r += 2;	
	}

	void operator>>( int phi )
	{
		if( phi != 90 && phi != 180 && phi != 270 )
			return;

		if( orj == __horizontalna )
		{
			if( phi == 90 )
				orj = __vertikalna;
			else if( phi == 180 )
				--s;
			else if( phi == 270 )
				--r, orj = __vertikalna;
		}
		else
		{
			if( phi == 90 )
				--s, orj = __horizontalna;
			else if( phi == 180 )
				--r;
			else if( phi == 270 )
				orj = __horizontalna;
		}
	}
};


class MainPloca : public Ploca
{
	int __brojPoziva;
	int __N;
	__Figurica __f;
	bool __kamencic[ 101 ][ 101 ];

	bool __moze( __Figurica x )
	{
		if( !( 0 <= x.r && x.r < __N && 0 <= x.s && x.s < __N ) || __kamencic[ x.r ][ x.s ] )
			return false;
		if( x.orj == __horizontalna )
		{
			if( !( 0 <= x.r && x.r < __N && 0 <= x.s+1 && x.s+1 < __N ) || __kamencic[ x.r ][ x.s+1 ] )
				return false;
		}
		else
		{
			if( !( 0 <= x.r+1 && x.r+1 < __N && 0 <= x.s && x.s < __N ) || __kamencic[ x.r+1 ][ x.s ] )
				return false;
		}

		return true;
	}

public:
	MainPloca( int N ) : Ploca( N ) 
	{
		this->__N = N;
		for( int r = 0; r < N; ++r )
			for( int s = 0; s < N; ++s )
				__kamencic[ r ][ s ] = false;
		
		__f.r = 0; __f.s = 0;
		__f.orj = __horizontalna;
		__f.str = __plava;
	}

	void operator++()
	{
		++__brojPoziva;
		__Figurica x = __f;
		++x;
		
		if( __moze( x ) )
			__f = x;

		Ploca::operator++();		
	}

	void operator--()
	{
		++__brojPoziva;
		__Figurica x = __f;
		--x;
		
		if( __moze( x ) )
			__f = x;

		Ploca::operator--();
	}

	void operator++(int)
	{
		++__brojPoziva;
		__Figurica x = __f;
		x++;

		if( __moze( x ) )
			__f = x;
		
		Ploca::operator++( 0 );
	}

	void operator--(int)
	{
		++__brojPoziva;
		__Figurica x = __f;
		x--;

		if( __moze( x ) )
			__f = x;
		
		Ploca::operator--( 0 );
	}


	MainPloca &operator>>( int phi )
	{
		++__brojPoziva;
		__Figurica x = __f;
		x >> phi;

		if( __moze( x ) )
			__f = x;
	
		Ploca::operator>>( phi );
		return *this;
	}

	int __getBrojPoziva() { return __brojPoziva; }
	void __resetBrojPoziva() { __brojPoziva = 0; }

	void __staviKamencic( int r, int s ) { __kamencic[ r-1 ][ s-1 ] = true; }
	void __ispisiFiguricu()
	{
		cout << "(" << __f.r+1 << ", " << __f.s+1 << ") ";
		cout << ( __f.orj == __horizontalna ? "horizontalna" : "vertikalna" ) << " ";
		cout << ( __f.str == __plava ? "plava" : "crvena" ) << endl;
	}
};

void pripremiTest( MainPloca &P, string ploca[], int N )
{
	for( int r = 0; r < N; ++r )
		for( int s = 0; s < N; ++s )
			if( ploca[ r ][ s ] == 'x' )
			{
				P.__staviKamencic( r+1, s+1 );
				P( make_pair( r+1, s+1 ) );
			}
}


int main( void )
{
	{
		MainPloca P( 8 );
		++P; ++P;
		string ploca[] = {
			"..x.PP..",
			"........",
			"........",
			"........",
			"........",
			"........",
			"........",
			"........" };

		pripremiTest( P, ploca, 8 );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			P.__ispisiFiguricu();
		}
		else
			cout << "ne moze dovesti figuricu na pocetnu poziciju" << endl;
	}

	{
		MainPloca P( 8 );
		P--; P >> 90; ++P; ++P; P >> 90;
		string ploca[] = {
			"........",
			"xCC.....",
			"........",
			"........",
			"........",
			"........",
			"........",
			"........" };

		pripremiTest( P, ploca, 8 );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			P.__ispisiFiguricu();
		}
		else
			cout << "ne moze dovesti figuricu na pocetnu poziciju" << endl;
	}

	{
		MainPloca P( 8 );
		++P; ++P; P >> 90; P--; P >> 90; P++;
		string ploca[] = {
			"...x....",
			".x.PP...",
			"..x.....",
			"........",
			"........",
			"........",
			"........",
			"........" };

		pripremiTest( P, ploca, 8 );
		P.__resetBrojPoziva();
		if( !P )
		{
			cout << P.__getBrojPoziva() << endl;
			P.__ispisiFiguricu();
		}
		else
			cout << "ne moze dovesti figuricu na pocetnu poziciju" << endl;
	}

	return 0;
}
