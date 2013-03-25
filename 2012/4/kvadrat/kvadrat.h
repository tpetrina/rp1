#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ull;

class Kvadrat
{
private:
	int M[ 16 ];
	void rot( int perm[], int duljina );
	void bfs4( int fixed[5][5] );
	
public:
	Kvadrat();
	Kvadrat( ull u );	
	
	virtual Kvadrat &operator>( const pair<int, int> &x );
	virtual Kvadrat &operator^( const pair<int, int> &x );

	int &operator()( int r, int s );
	const int &operator()( int r, int s ) const;

	friend int operator==( const Kvadrat &K, const Kvadrat &L );
	
	pair<int, int> operator[]( string s ) const;
	pair<int, int> operator[]( const char *s ) const;
	
	void operator++();
	void operator--();
	void operator++(int);
	void operator--(int);

	operator ull();
	void operator!();
};

int operator==( const Kvadrat &K, const Kvadrat &L );
