#include <iostream>
#include <string>

using namespace std;

enum orjentacija { horizontalna, vertikalna };
enum strana { plava, crvena };

struct Figurica
{
	int r, s;
	strana str;
	orjentacija orj;
	
	Figurica();
	Figurica( int hash );
	operator int();

	void operator++();
	void operator--();
	void operator++(int);
	void operator--(int);
	void operator>>( int phi );

	friend bool operator==( const Figurica &A, const Figurica &B );
};

class Ploca
{
	int N;
	Figurica f;
	bool kamencic[ 101 ][ 101 ];

	void staviFiguricu();
	bool moze( Figurica x );
public:
	Ploca( int N );
	
	int operator()( const pair<int, int> &x );
	pair<int, int> operator*();
	string operator~();
	
	virtual void operator++();
	virtual void operator--();
	virtual void operator++(int);
	virtual void operator--(int);

	virtual Ploca &operator>>( int phi );
	
	friend int operator==( const Ploca &P, const Ploca &Q );
	
	bool operator!();
};

int operator==( const Ploca &P, const Ploca &Q );
bool operator==( const Figurica &A, const Figurica &B );
