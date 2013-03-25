#include "ploca.h"
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

Ploca::Ploca( int N )
{
	Ploca::N = N;
	for( int r = 0; r < N; ++r )
		for( int s = 0; s < N; ++s )
			kamencic[ r ][ s ] = false;
	
	f.r = 0; f.s = 0;
	f.orj = horizontalna;
	f.str = plava;
}

bool Ploca::moze( Figurica x )
{
	if( !( 0 <= x.r && x.r < N && 0 <= x.s && x.s < N ) || kamencic[ x.r ][ x.s ] )
		return false;
	if( x.orj == horizontalna )
	{
		if( !( 0 <= x.r && x.r < N && 0 <= x.s+1 && x.s+1 < N ) || kamencic[ x.r ][ x.s+1 ] )
			return false;
	}
	else
	{
		if( !( 0 <= x.r+1 && x.r+1 < N && 0 <= x.s && x.s < N ) || kamencic[ x.r+1 ][ x.s ] )
			return false;
	}

	return true;
}

int Ploca::operator()( const pair<int, int> &x )
{
	if( f.r == x.first-1 && f.s == x.second-1 )
		return 2;
	if( f.orj == horizontalna && f.r == x.first-1 && f.s+1 == x.second-1 )
		return 2;
	if( f.orj == vertikalna && f.r+1 == x.first-1 && f.s == x.second-1 )
		return 2;

	kamencic[ x.first-1 ][ x.second-1 ] = !kamencic[ x.first-1 ][ x.second-1 ];
	return kamencic[ x.first-1 ][ x.second-1 ];
}

pair<int, int> Ploca::operator*()
{
	return make_pair( f.r+1, f.s+1 );
}

string Ploca::operator~()
{
	if( f.str == plava )
		return string( "plava" );
	else
		return string( "crvena" );
}

void Ploca::operator++()
{
	Figurica x = f;
	++x;
	
	if( moze( x ) )
		f = x;
}

void Ploca::operator--()
{
	Figurica x = f;
	--x;
	
	if( moze( x ) )
		f = x;
}

void Ploca::operator++(int)
{
	Figurica x = f;
	x++;
	
	if( moze( x ) )
		f = x;
}

void Ploca::operator--(int)
{
	Figurica x = f;
	x--;
	
	if( moze( x ) )
		f = x;
}

Ploca &Ploca::operator>>( int phi )
{
	Figurica x = f;
	x >> phi;
	
	if( moze( x ) )
		f = x;
	
	return *this;
}

void Figurica::operator++()
{
	str = strana(!str);
	
	if( orj == horizontalna )
		s += 2;
	else
		s += 1;
}

void Figurica::operator--()
{
	str = strana(!str);
	if( orj == horizontalna )
		s -= 2;
	else
		s -= 1;
}

void Figurica::operator++(int)
{
	str = strana(!str);
	
	if( orj == horizontalna )
		r -= 1;
	else
		r -= 2;	
}

void Figurica::operator--(int)
{
	str = strana(!str);
	
	if( orj == horizontalna )
		r += 1;
	else
		r += 2;	
}

void Figurica::operator>>( int phi )
{
	if( phi != 90 && phi != 180 && phi != 270 )
		return;

	if( orj == horizontalna )
	{
		if( phi == 90 )
			orj = vertikalna;
		else if( phi == 180 )
			--s;
		else if( phi == 270 )
			--r, orj = vertikalna;
	}
	else
	{
		if( phi == 90 )
			--s, orj = horizontalna;
		else if( phi == 180 )
			--r;
		else if( phi == 270 )
			orj = horizontalna;
	}
}


int operator==( const Ploca &P, const Ploca &Q )
{
	if( P.N != Q.N )
		return 0;
		
	int koliko = 0;
	for( int r = 0; r < P.N; ++r )
		for( int s = 0; s < P.N; ++s )
			if( P.kamencic[ r ][ s ] && Q.kamencic[ r ][ s ] )
				++koliko;
				
	return koliko;
}

Figurica::Figurica() 
{
	r = s = 0;
	orj = horizontalna;
	str = plava;
}

Figurica::Figurica( int hash )
{
	str = strana(hash % 2); hash /= 2;
	orj = orjentacija(hash % 2); hash /= 2;
	s   = hash % 100; hash /= 100;
	r   = hash;
}

Figurica::operator int()
{
	int hash = r;
	hash = 100*hash + s;
	hash = 2*hash + orj;
	hash = 2*hash + str;
}

bool operator==( const Figurica &A, const Figurica &B )
{
	return A.r == B.r && A.s == B.s && A.orj == B.orj && A.str == B.str;
}

bool Ploca::operator!()
{
	vector<int> opCode( 100*100*2*2, -2 ), parent( 100*100*2*2, -2 );
	queue<int> Q;

	Figurica init;
	
	Q.push( f ); parent[ f ] = -1;
	while( !Q.empty() )
	{
		Figurica x = Q.front(); Q.pop();
		if( x == init )
			break;
		
		vector<Figurica> novi( 7, x );
		++novi[ 0 ]; --novi[ 1 ]; novi[ 2 ]++; novi[ 3 ]--;
		for( int phi = 90; phi < 360; phi += 90 )
			novi[ 3+phi/90 ] >> phi;

		for( int i = 0; i < 7; ++i )
			if( moze( novi[ i ] ) && parent[ novi[ i ] ] == -2 )
			{
				opCode[ novi[ i ] ] = i; parent[ novi[ i ] ] = x;
				Q.push( novi[ i ] );
			}
	}
	
	if( parent[ init ] == -2 )
		return false;
		
	stack<int> S;
	while( parent[ init ] != -1 )
	{
		S.push( opCode[ init ] );
		init = parent[ init ];
	}
	
	while( !S.empty() )
	{
		switch( S.top() )
		{
			case 0: ++(*this); break;
			case 1: --(*this); break;
			case 2: (*this)++; break;
			case 3: (*this)--; break;
			case 4: (*this)>>90; break;
			case 5: (*this)>>180; break;
			case 6: (*this)>>270; break;
		}
		
		S.pop();
	}
}
