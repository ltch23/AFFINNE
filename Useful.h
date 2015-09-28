
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
	if(a==0)
		return 0;
	if(a>0)
		return b - (a/b) * b;
	if(a<0)
		return b + (a/b) * b;
};

#endif // USEFUL_H