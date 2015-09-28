#include "Useful.h"

bool Useful::isEven( int n )
{
	if( n&1 == 1 )
		return false;
	return true;
};

int Useful::mod( int a , int b )
{
	int q = a/b;

	if (a<0)
		q--;

	return a-(b*q) == b  ? 0 : a-(b*q);
};
