#include <iostream>
#include <string>

using namespace std;

class Poligon;

struct Pozicije
{
	int r[ 4 ], s[ 4 ];

	void idiDesno( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] );
	void idiGore( const pair<int, int> &x, bool prepreka[ 8 ][ 8 ] );
};

class Poligon
{
	Pozicije pozicije;
	bool prepreka[ 8 ][ 8 ];
	pair<int, int> trciDoDrugogPsa( int pas, int delta_r, int delta_s );
	
public:
	Poligon();
	
	bool operator[]( const pair<int, int> &x );
	pair<int, int> operator()( string s ) const;
	
	virtual Poligon &operator>( const pair<int, int> &x );
	virtual Poligon &operator^( const pair<int, int> &x );
	
	friend bool operator==( const Poligon &P, const Poligon &Q );
	
	void operator++();
	void operator--();
	void operator++(int);
	void operator--(int);

	bool operator!();
};

bool operator==( const Poligon &P, const Poligon &Q );
