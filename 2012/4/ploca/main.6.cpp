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
		++P; ++P; P--; P--; P--; P--; P--;

		string ploca[] = {
			"..x....x",
			"........",
			"..x.x...",
			".x......",
			"...x...x",
			"...xCC..",
			".x......",
			".x....x." };

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
		MainPloca P( 11 );
		++P; ++P; P--; P--; P--; P--; P--; P >> 90; ++P; ++P; P--;

		string ploca[] = {
			"..xxxxxxxxx",
			"....x......",
			"....x..x.xx",
			".......x...",
			"...xxxxxx..",
			"..x......x.",
			".xx...x..x.",
			"x....xCx.x.",
			"x..xxxCx.x.",
			"x.x....x...",
			"x....x....." }; 

		pripremiTest( P, ploca, 11 );
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
		MainPloca P( 97 );
		++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P;
		++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; ++P; 
		P >> 90;
		P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--;
		P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--; P--;
		// (93,93)

		string ploca[] = {
			"...x.x....x..........xx...xxx......x....xxx....x........x...x....x.....x....xx...x.......x...x..x",
			"....x..x..x..x.x......x.............x..x.x......xx.x.x.x.x.x...x.x.....x....x.x........x.x.......",
			"xx.xxxxx..x.x..xxx.x.x....x.xx.x.x......x..x........x..xx............x..x.x......xxxx...x..xx....",
			".x.....x..........x..x..x...........x.x....xxx...x...xx..x.x......x...........x.x...x.x.x.x..x..x",
			"xx........x.......x.x.x....xx...x.x.....x..x..x.....x........xx....x......x.x.x...x..x.....x.....",
			".....xxx.x.......xx..x.x..x.x......xx...x.x..x..x.xx.x.....x.xx....x..x.........xxxx...x.........",
			"........x.x.....x..x....x...x....x.......x...xx.....x.x......x..xxx.x............x.......x..x..x.",
			".........x.x.x.x.xx............xxx.x.x.....xx.xx..x..xx......x..x....x......xx.xx......xxx.x.x...",
			"....x.....x.x........x..........x.x.....x.x..x...x...x.....x..xx.x......x.......x....x........x.x",
			"...x.x..xxxx.x.x.....x..xx......xxx....xx.x..x..x..x..x..x...x....x..xx.x..x....x...x..x.x.......",
			"xx..x....x..............x...x.....xx.xx.......x.x.xxx.x...x.x.xxxx.x..xx........x..x.x..xx.....xx",
			"........x......xx...x......x.....x...x.....x...........x......xx.x...x....x...x...x......x....x.x",
			".x..x..............x.x..x.x.x.xx....xx..........xx..x.......x....xx...x......x...x..xxxx..x.x..x.",
			"x.......x.x....x.x.xx....x................xx.x.x....xx..x........x.....x....x...x.x.....x........",
			"x....x....xx......x.....x.................x.........x....x....x..xx.x....x...x.............x.....",
			"..x..x.......x.......x...x..x.x.x.x..xxx.....x....x...xx........xx....x.xx..x......x..........x..",
			".x....x......x.x...x...x................x.....x.........x.x...x.x...x.x...x....x....x....x.....x.",
			"x..x..xx.......x..........x....x..........x.....x.....x...x....x..x....x...x...xx...x..x.....xx.x",
			"x.x......x..........xx.x.xxx.............xx....x...x...x......xx..x.............x......x..x.x....",
			"....xx.............xx......x..xx.....xxx.x.xx......x...x...........xxx.......x.....x....x..x.....",
			".x............xxx........x......xx.xx.....x.x.x.x..xx.x.....x.xx......xx..x...x.....xx......x.xx.",
			".x......x...x.........x..x......x.....x..x.................xx........xx..x......x....xxx.....xxx.",
			"...x....x..x.....x........xx.x.x.......x..x......x.x.x.......x.......x..x.x........x..x.x..x.....",
			"........x.x...x.xx..........x.......x...x....x....x.x....x..xx.......x.x.x....xx.......x.x.......",
			".x....x.............x...x..x.x.x........x.x....x......x..x..xx...x.....x..........x........x.....",
			"....x.x...x............x.......x.x..xx......xx...x...x...x...x....x.x.......x.........x..x.......",
			".......x.x.......x.x.........x.x..x.x....x.x................xx...x.......x....x.x..x...x.x....x..",
			"..x....xx...xx...x.......xx........x.x.xx.xx..x..x...x......xxx....x....x.xxx....x..x...x......xx",
			"x..x.x...x.....x...x...x..xx....xxx..x....xx....x..........x.x.....x.x.x...xx......xx.........x..",
			".x......x........x.....xx.x.xx.x.....x..x.x.x........xxx.............x..x..x.....xx...x.......x.x",
			"xx......x..x.x...x....x.........x.x.x......x....x....xxx..xx.xx.....x.............x........x..x..",
			".........x.x.............x...x....x.x..x.....x...x.x.xxxx..x....x..xx........x..xx........xx..xx.",
			"...x...x...............x...........x......x....xx....x......x......xx.x..x....xxx...xx..x.x.x.x..",
			"....x.....x..x..xx..........x.x..x......x....x.x..x....x..........x.xx...xxxx.....xxxx.......xx..",
			"......x........xx..x..........xxx..xxx...x........x......x...x.....x..x...xx....x..x.....x.x.x...",
			"..x.x...x..x.x.x.......x.........xx...x..........x..x...x..x....xx..x.....xxxx....xx....xxx......",
			"..xx..xx.x..x....x....x....xx............x...xx.x.......x..x.x..........x.....x...x.x..x......x..",
			"........x...xxx...x.x....xx......x....x.x.....x......xxx..x........x...x.x.xx.x....x..x..xx..x...",
			"................x...x.xx...xx......xx.x.x....x.x....x......x...x.x.x....x.....xxx.x..x.....x..x..",
			".........x..x...x...xx....x.xx.....x...x.....x...xxx....xx....xx......x.xx...x..x..x..x.x.x......",
			"x..x...x..x.x.....x...xx...x...........xx....x........xx......xxx.x.x.x.......x.x.....x......x...",
			"x.......x........x...x..x..xx..x........x..........x...xx....x.xx..xx......x......x............xx",
			"xxx..x.x....x..x...x...x....xx..xx.....x....xx.x...xx......x...x.xx.x............x......xx.....x.",
			"......x...x.....xx.x...xx.........x.......x.xx..xx.x.x..x...xx............x.....x.x...x....x.x...",
			"........x...x........x....x.......x..xx.x.....x......x...........x..x...........x..x.x..x.....x.x",
			"x....x.......xxx.........x..........x.xx......x.x.....xx..x..x..x......x...x.x........x..x.x..x..",
			".......xxx.x........x..x.x..xxx.x..x..x....x.......x........x.x..x....x...xx.x......x...x.....xxx",
			".x.x...x..x.xx.........x.x....x...xx........x.x....x...x.xx.xx......xxx..x......x.x..xx.x....xxx.",
			"...........xxx........x.......x...x....x.xx.x.......x...xx..x.x......x.x..x...x...x..............",
			".x.x.x......x..x.....x..x...........x....x...xxx.x......xx.....x.....x.....x..x.......x....x.....",
			".x.xx..xx.........x......xxx.x..x.......x.....x......xx.....x...x..x...........x..x.x.....x......",
			".........x.....x....x....x...x.x..x...x........x....x..........x.......x..................x......",
			"..x.x.....x..........xx...x....x..x.........x...xxx.x......xx....xx.........x......x.............",
			"x..x..x....xx...xx.........x....x...x....x..x..............x..x......x...........x.xxx..x..x..x..",
			"....xx..x.x...x.......x...xx.x......x.xx.x....xx....xx..x..x..x........x............xx...........",
			".x.......x..x......x...x...x........x.....xx........x..xx..x.xx.x............x...xx..xxx....x....",
			".........xx.x.x.x.xx.x.....x.....x...xxx.xx.x.....x....xx...............x..x...x......x...x......",
			".xx.x............x...x.xx.x..x.............x..xx..x.........x..x......xx.......x..xx.x.........x.",
			".x...xx..x.x.....x..xx...x.x...............x..xx............xx..........................x...xx.xx",
			"x.........x....xx....x........x..x............x..x..x..x.................x.xx...x.......x........",
			".x.x.........x.x....x.xx..x......x.xx.x.x....xx.x.x..x..........x.x.....x.....x...xx......xx.....",
			"....x......x....x.x..x......x...x.x..x...x...........x.......x.x..xx..x...x......x...x..xx.....xx",
			"....x....xx.......x.x..xx...x......x.............x....x....x......x...x....x..x..xx.x....x.x.x.x.",
			"...x..xx.x........x..x.......x...........x.x.........x..x.x...x...........x....x...x.xx....x.....",
			"x.........x......................x....x..x......xx....x.x....x..x..xxx.x..x.xx...x...x........x..",
			".........xxx...x...x..........xx....xx.......x...x..........xx....x...................x..xx.....x",
			"x.......x...x..x.xx...x....x.x....x..x.xxx...x.....x.......xx..x....xxx.........x..x.............",
			"........x.........x.x......xx.............xx..........x...x...x.x..x.x.x.xx...xxxx.....x.x...x..x",
			".xx..x...xx...xx.....x.....x.xx...x.....x.......xx...x.x.x...x.xx...x.x......xxx.xx.........x...x",
			"x........xx...........x.x..x.xx.......xx................x....xxxx...x..x...........x.......x...xx",
			"x....x...x....xx....x..x...........x..x..x.....x.x..xxx.x..x..x....x....xxx.x...x.x........x.....",
			"xxxx.x...x....x.x..x......x.xx....x...xxx.x....x.....xx...x...........x..x.........x...........x.",
			"x.x..xx...........xxx.........xx...........x..x.x.x....x.....xxx..xx........xx...x..........x.x.x",
			"...x.x.x.x......x...x.x.x..x.x.......x........x..x..x....xx.x......xx....x....x.......x...xx....x",
			"x...xx..xx...x...x.x.......x.xx.x.x.x....x.xxx.x....x....x...x.x....x..xx.........x..x..x........",
			"...x..x..x.x.....xx.x.......x..x..x..........xxx.x..x.......xxxx......x.......x..........x.x.....",
			"....x......x....xx....x.....xx........xx...x.x..x..x.........xx..x...x.x.xx....x.......xx..x...xx",
			".....x...xxx..xxxx.xx...........x............x...x...........x........x.xx..........x.x.xx.x.....",
			"x...x..xxx.x.x...........x......x..xx..x.x....x....x...x.....x.xx.x...x....x.xx..x.....x.........",
			"x..x.x..x.....x.x..x..............x....x.x.x......xx..x..x...x.x.......x..x...x.xxxxx..x......xx.",
			"...x..........x..x.....xx......x.....x.x....x...x..x....x..x..x.x............x....x....x...xx..x.",
			".x..x.......x.xx....x......x.......xx.x..x.....x..xxx......x.....xx.....x....x......x..x....x....",
			"........xx..x.x...x...x........xxx.....x.xx..xx.xx.......xxx...xx..x.x..xx...x.....x.....x...x..x",
			".x.....x.x....x...xx.....x.x.xx.xxx....xx....xx....x....x.x.x.x.x..........xx.....x.xx....x.x....",
			".....x.x............x..xx...x.....x.....x............x.....x....x..x..x..........x....xx.xx......",
			".x.x.......x.xx.x....x.x.......x..........x...x.....xx..x.....x...x.x....xx..xx..x.x..x.x.x.xx.x.",
			"..........x....x...x........xx.x.x..x........x...x..........x.................x.x..x..xx..x....x.",
			"xx.................x.................x........x.x............x..xxx....x...x.x....xxx...xxx...xx.",
			"..x.x......x.........xxxx..x.x......x.x..xx..............xxx.....x..x........x.....xx............",
			"....x.x..x..xx..x..........x..x.....x...x..x.....x.x.x.........x......x.......x.xxxxx...x.xxx....",
			"xx..xxxx...........x..x.xx.x.x..........x.x..xx.xx....x...xx....xx....x.x.......xxx.x...x..x...x.",
			"...xxx.x..x.x.....x.....x..x.x.....x...x..x.xx............x..x..x.x......x............x.x.......x",
			".x.........x..x.x.x....x..........x.x.x....x.....x.x.x.x...xxx.........x....x..xx.....x.....Px..x",
			".....x....x............................x...x........xx.......x.....x.........x.........xxx..P....",
			".....x.......x...........x..........xxx...x....x..x.x....x....x..x..x....x..x.....xx.xx......x..x",
			"......x......x.xx...x.......x.x....xx..x....x.x..x......x..x.xx.x..x....xx.x.....x...............",
			".....xx.xx.....x......x.x..x......xx..xxx.x.xx.x.x.x...x.......x....xx.x..xxxx.x...x...x........x" };

		pripremiTest( P, ploca, 97 );
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
