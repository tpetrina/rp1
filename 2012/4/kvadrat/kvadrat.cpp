#include "kvadrat.h"
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

Kvadrat::Kvadrat()
{
	for( int i = 0; i < 16; ++i )
		M[ i ] = i+1;
}

Kvadrat::Kvadrat( ull u )
{
	for( int i = 0; i < 16; ++i )
		M[ i ] = u % 16 + 1, u /= 16;
}

int &Kvadrat::operator()( int r, int s )
{
	return M[ 4*(r-1) + s-1 ];
}

const int &Kvadrat::operator()( int r, int s ) const
{
	return M[ 4*(r-1) + s-1 ];
}

pair<int, int> Kvadrat::operator[]( string s ) const
{
	int br = 0;
	sscanf( s.c_str(), "%d", &br );
	
	char cc[ 15 ];
	sprintf( cc, "%d", br );
	
	if( strcmp( s.c_str(), cc ) != 0 )
		return make_pair( 0, 0 );
		
	for( int i = 0; i < 16; ++i )
		if( M[ i ] == br )
			return make_pair( (i/4)+1, (i%4)+1 );

	return make_pair( 0, 0 );		
}

pair<int, int> Kvadrat::operator[]( const char *s ) const
{
	return operator[]( string( s ) );
}
	
int operator==( const Kvadrat &K, const Kvadrat &L )
{
	int brIstih = 0;
	for( int i = 0; i < 16; ++i )
		if( K.M[ i ] == L.M[ i ] )
			++brIstih;
			
	return brIstih;
}

void Kvadrat::rot( int perm[], int duljina )
{
	int temp = M[ perm[ duljina-1 ] ];
	for( int i = duljina-1; i > 0; --i )
		M[ perm[ i ] ] = M[ perm[ i-1 ] ];
	M[ perm[ 0 ] ] = temp;
}

void Kvadrat::operator++()
{
	int perm[] = { 0, 1, 2, 3, 7, 11, 15, 14, 13, 12, 8, 4 };
	rot( perm, 12 );
}

void Kvadrat::operator--()
{
	int perm[] = { 4, 8, 12, 13, 14, 15, 11, 7, 3, 2, 1, 0 };
	rot( perm, 12 );
}

void Kvadrat::operator++(int)
{
	int perm[] = { 5, 6, 10, 9 };
	rot( perm, 4 );
}

void Kvadrat::operator--(int)
{
	int perm[] = { 9, 10, 6, 5 };
	rot( perm, 4 );
}

Kvadrat &Kvadrat::operator>( const pair<int, int> &x )
{
	int perm[ 4 ];
	for( int i = 0; i < 4; ++i )
		perm[ i ] = (x.first-1)*4 + i;
	
	for( int i = 0; i < x.second; ++i )
		rot( perm, 4 );

	return *this;
}

Kvadrat &Kvadrat::operator^( const pair<int, int> &x )
{
	int perm[ 4 ];
	for( int i = 0; i < 4; ++i )
		perm[ i ] = 4*(3-i) + x.first-1;
	
	for( int i = 0; i < x.second; ++i )
		rot( perm, 4 );
	
	return *this;
}

Kvadrat::operator ull()
{
	ull rez = 0, pot = 1;
	
	for( int i = 0; i < 16; ++i )
		rez = rez + pot*(M[ i ]-1), pot *= 16;
		
	return rez;
}

void Kvadrat::operator!()
{
	int fixed[5][5] = { { 0 } };
	int redoslijed[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 10, 14, 11, 12 };

	// dovodi brojeve na njihovo mjesto po gornjem redoslijedu
	for( int i = 0; i < 14; ++i )
	{
		int broj = redoslijed[ i ];
		fixed[ (broj-1)/4+1 ][ (broj-1)%4+1 ] = broj;

		// za svaki broj je dovoljno <= 4 poteza
		bfs4( fixed );
	}
	
	// popravi 15 <--> 16 rucno ako treba [hint: meet in the middle :)]
	if( (*this)( 4, 4 ) == 15 )
	{
		(*this) > make_pair( 4, 1 );
		(*this) ^ make_pair( 2, 3 );
		(*this) > make_pair( 4, 1 );
		(*this) ^ make_pair( 2, 1 );

		(*this) > make_pair( 4, 2 );			
		(*this) ^ make_pair( 2, 3 );
		(*this) > make_pair( 4, 1 );
		(*this) ^ make_pair( 2, 1 );
	}
}

void Kvadrat::bfs4( int fixed[5][5] )
{
	// Koristenjem najvise 4 poteza, dovedi tablicu iz trenutnog stanja u ono u
	// kojem su fiksirani svi brojevi u tablici fixed
	vector<int> back[ 5 ]; back[ 0 ].push_back( 0 );
	vector<ull> pos[ 5 ]; pos[ 0 ].push_back( *this );
	int pot[] = { 1, 24, 24*24, 24*24*24, 24*24*24*24 };
	
	for( int n = 0; n < 4; ++n )
		for( int i = 0; i < pos[ n ].size(); ++i )
		{
			// generiraj sve moguce poteze na kvadratu pos[ n ][ i ]
			for( int r = 1; r <= 4; ++r )
				for( int k = 1; k <= 3; ++k )
				{
					Kvadrat K = pos[ n ][ i ];
					K > make_pair( r, k ); // uoci: ovi se ne broje jer nisu na this!
					
					pos[ n+1 ].push_back( K );
					back[ n+1 ].push_back( 24*back[ n ][ i ] + (r-1)*3 + k-1 );
				}
				
			for( int s = 1; s <= 4; ++s )
				for( int k = 1; k <= 3; ++k )
				{
					Kvadrat K = pos[ n ][ i ];
					K ^ make_pair( s, k ); // uoci: ovi se ne broje jer nisu na this!

					pos[ n+1 ].push_back( K );
					back[ n+1 ].push_back( 24*back[ n ][ i ] + 12+(s-1)*3 + k-1 );
				}
		}
		
	// provjeri da postoji potez sa fiksiranom tablicom
	bool done = false;
	for( int n = 0; n <= 4 && !done; ++n )
		for( int i = 0; i < pos[ n ].size() && !done; ++i )
		{
			int ok = true;
			Kvadrat K = pos[ n ][ i ];
			
			for( int r = 1; r <= 4 && ok; ++r )
				for( int s = 1; s <= 4 && ok; ++s )
					if( fixed[ r ][ s ] != 0 && K( r, s ) != fixed[ r ][ s ] )
						ok = false;
						
			if( ok )
			{
				// nasli smo ga --> rekonstuiraj i izvrsi poteze na this
				for( int nn = 0; nn < n; ++nn )
				{
					int potez = (back[ n ][ i ] / pot[ n-nn-1 ]) % 24;
					
					if( potez < 12 )
						(*this) > make_pair( potez/3 + 1, potez%3 + 1 );
					else
					{
						potez -= 12;
						(*this) ^ make_pair( potez/3 + 1, potez%3 + 1 );
					}
				}
				done = true;
			}			
		}
}
