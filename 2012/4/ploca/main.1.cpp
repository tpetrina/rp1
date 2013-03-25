#include <iostream>
#include "ploca.h"

using namespace std;

void ispisiPlocu( Ploca &P, int N )
{
	pair<int, int> x = *P;
	cout << "(" << x.first << ", " << x.second << ") ";
	cout << ~P << " ";

	if( x.first + 1 <= N )
	{
		if( P( make_pair( x.first+1, x.second ) ) == 2 )
			cout << "vertikalna";
		else
		{
			P( make_pair( x.first+1, x.second ) );
			cout << "horizontalna";
		}
	}
	else
		cout << "horizontalna";

	cout << endl;
}


int main( void )
{
	int N = 8;

	Ploca P( N );
	ispisiPlocu( P, N );
	++P; ispisiPlocu( P, N );
	P--; ispisiPlocu( P, N );
	++P; ispisiPlocu( P, N );
	--P; ispisiPlocu( P, N );
	P--; ispisiPlocu( P, N );
	P++; ispisiPlocu( P, N );
	P++; ispisiPlocu( P, N );
	--P; ispisiPlocu( P, N );

	return 0;
}
