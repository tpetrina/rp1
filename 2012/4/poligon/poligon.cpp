#include "poligon.h"
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

Poligon::Poligon()
{
	for( int r = 0; r < 8; ++r )
		for( int s = 0; s < 8; ++s )
			prepreka[ r ][ s ] = false;
			
	pozicije.r[ 0 ] = 0; pozicije.s[ 0 ] = 0;
	pozicije.r[ 1 ] = 0; pozicije.s[ 1 ] = 1;
	pozicije.r[ 2 ] = 1; pozicije.s[ 2 ] = 0;
	pozicije.r[ 3 ] = 1; pozicije.s[ 3 ] = 1;
}

bool Poligon::operator[]( const pair<int, int> &x )
{
	for( int i = 0; i < 4; ++i )
		if( pozicije.r[ i ] == x.first-1 && pozicije.s[ i ] == x.second-1 )
			return false;
			
	prepreka[ x.first-1 ][ x.second-1 ] = !prepreka[ x.first-1 ][ x.second-1 ];
	return true;
}

pair<int, int> Poligon::operator()( string s ) const
{
	int pas = -1;
	sscanf( s.c_str(), "%d", &pas );
	char ss[ 15 ];
	sprintf( ss, "%d", pas );
	
	if( !( 1 <= pas && pas <= 4 ) || string( ss ) != s )
		return make_pair( 0, 0 );
	else
		return make_pair( pozicije.r[ pas-1 ]+1, pozicije.s[ pas-1 ]+1 );
}

Poligon &Poligon::operator>( const pair<int, int> &x )
{
	pozicije.idiDesno( x, prepreka );
	return *this;
}

Poligon &Poligon::operator^( const pair<int, int> &x )
{
	pozicije.idiGore( x, prepreka );
	return *this;
}

pair<int, int> Poligon::trciDoDrugogPsa( int pas, int delta_r, int delta_s )
{
	int r = pozicije.r[ pas ], s = pozicije.s[ pas ];
	set<pair<int, int> > S;
	
	for( int i = 0; i < 4; ++i )
		if( i != pas )
			S.insert( make_pair( pozicije.r[ i ], pozicije.s[ i ] ) );
			
	pair<int, int> sol( 0, 0 );
	while( 1 )
	{
		r += delta_r; s += delta_s;
		
		if( !( 0 <= r && r <= 7 && 0 <= s && s <= 7 ) || prepreka[ r ][ s ] )
			break;
			
		if( S.find( make_pair( r, s ) ) != S.end() )
			sol = make_pair( r, s );
	}
	
	return sol;
}

void Poligon::operator++()
{
	for( int pas = 0; pas < 4; ++pas )
	{
		pair<int, int> p = trciDoDrugogPsa( pas, 0, 1 );
		if( p.first != 0 )
		{
			pozicije.r[ pas ] = p.first; pozicije.s[ pas ] = p.second;
			break;
		}
	}
}

void Poligon::operator--()
{
	for( int pas = 0; pas < 4; ++pas )
	{
		pair<int, int> p = trciDoDrugogPsa( pas, 0, -1 );
		if( p.first != 0 )
		{
			pozicije.r[ pas ] = p.first; pozicije.s[ pas ] = p.second;
			break;
		}
	}
}

void Poligon::operator++(int)
{
	for( int pas = 0; pas < 4; ++pas )
	{
		pair<int, int> p = trciDoDrugogPsa( pas, -1, 0 );
		if( p.first != 0 )
		{
			pozicije.r[ pas ] = p.first; pozicije.s[ pas ] = p.second;
			break;
		}
	}
}

void Poligon::operator--(int)
{
	for( int pas = 0; pas < 4; ++pas )
	{
		pair<int, int> p = trciDoDrugogPsa( pas, 1, 0 );
		if( p.first != 0 )
		{
			pozicije.r[ pas ] = p.first; pozicije.s[ pas ] = p.second;
			break;
		}
	}
}

bool operator==( const Poligon &P, const Poligon &Q )
{
	set<pair<int, int> > SP, SQ;
	
	for( int pas = 0; pas < 4; ++pas )
		SP.insert( make_pair( P.pozicije.r[ pas ], P.pozicije.s[ pas ] ) ), 
		SQ.insert( make_pair( Q.pozicije.r[ pas ], Q.pozicije.s[ pas ] ) );
		
	return SP == SQ;
}

void Pozicije::idiDesno( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] )
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
	
void Pozicije::idiGore( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] )
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

bool Poligon::operator!()
{
	int brojPomaka[ 4 ][ 8 ][ 8 ] = { 0 }, opCode[ 4 ][ 8 ][ 8 ];
	pair<int, int> back[ 4 ][ 8 ][ 8 ];

	// za svakog psa nadji koliko mu koraka min. treba do pozicije (r, s)
	Pozicije nova = pozicije;
	for( int pas = 0; pas < 4; ++pas )
	{
		queue<pair<int, int> > Q;
		Q.push( make_pair( pozicije.r[pas], pozicije.s[pas] ) ); 
		brojPomaka[ pas ][ pozicije.r[ pas ] ][ pozicije.s[ pas ] ] = 1;
		back[ pas ][ pozicije.r[ pas ] ][ pozicije.s[ pas ] ] = make_pair( -1, -1 );

		while( !Q.empty() )
		{
			int r = Q.front().first, s = Q.front().second;
			Q.pop();

			for( int n = -7; n <= 7; ++n )
			{
				nova.r[ pas ] = r; nova.s[ pas ] = s;
				nova.idiDesno( make_pair( pas+1, n ), prepreka );

				if( brojPomaka[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] == 0 )
				{
					Q.push( make_pair( nova.r[ pas ], nova.s[ pas ] ) );
					brojPomaka[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = brojPomaka[ pas ][ r ][ s ] + 1;
					opCode[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = n+7;
					back[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = make_pair( r, s );						
				}
			}

			for( int n = -7; n <= 7; ++n )
			{
				nova.r[ pas ] = r; nova.s[ pas ] = s;
				nova.idiGore( make_pair( pas+1, n ), prepreka );

				if( brojPomaka[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] == 0 )
				{
					Q.push( make_pair( nova.r[ pas ], nova.s[ pas ] ) );
					brojPomaka[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = brojPomaka[ pas ][ r ][ s ] + 1;
					opCode[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = 15 + n+7;
					back[ pas ][ nova.r[ pas ] ][ nova.s[ pas ] ] = make_pair( r, s );						
				}
			}
		}
	}

	// nadji optimalni 2x2 kvadrat
	int minUkupanBrojPomaka = -1, minR[ 4 ], minS[ 4 ];
	for( int r = 0; r < 7; ++r )
		for( int s = 0; s < 7; ++s )
		{
			pair<int, int> perm[] = { make_pair( 0, 0 ), make_pair( 0, 1 ), make_pair( 1, 0 ), make_pair( 1, 1 ) };
			while( 1 )
			{
				// pas p ide na lokaciju (r,s)+perm[p]
				int ukupanBrojKoraka = 0;
				bool OK = true;
				for( int pas = 0; pas < 4; ++pas )
					if( brojPomaka[ pas ][ r+perm[pas].first ][ s+perm[pas].second ] == 0 )
						OK = false;
					else
						ukupanBrojKoraka += brojPomaka[ pas ][ r+perm[pas].first ][ s+perm[pas].second ]-1;

				if( OK && ( minUkupanBrojPomaka == -1 || ukupanBrojKoraka < minUkupanBrojPomaka ) )
				{
					minUkupanBrojPomaka = ukupanBrojKoraka;
					for( int pas = 0; pas < 4; ++pas )
						minR[ pas ] = r+perm[pas].first, minS[ pas ] = s+perm[pas].second;
				}

				if( !next_permutation( perm, perm + 4 ) )
					break;
			}	
		}
	
	if( minUkupanBrojPomaka == -1 )
		return false;

	// dovedi pse na mjesta minR, minS
	for( int pas = 0; pas < 4; ++pas )
	{
		int r = minR[ pas ], s = minS[ pas ];
		stack<int> S;
		while( back[ pas ][ r ][ s ] != make_pair( -1, -1 ) )
		{
			S.push( opCode[ pas ][ r ][ s ] );
			int rTemp = back[ pas ][ r ][ s ].first;
			s = back[ pas ][ r ][ s ].second, r = rTemp;
		}

		while( !S.empty() )
		{
			int move = S.top(); S.pop();
			if( move < 15 )
				(*this) > make_pair( pas+1, move - 7 );
			else
				move -= 15,
				(*this) ^ make_pair( pas+1, move - 7 );
		}
	}

	return true;
}
