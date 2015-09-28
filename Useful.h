
#ifndef USEFUL_H
#define USEFUL_H

class Useful
{

public:
	static bool isEven( int );
	static int mod( int , int );
};

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

#endif // USEFUL_H