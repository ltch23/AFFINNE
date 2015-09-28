#include <iostream>

int main(int argc, char const *argv[])
{
	int g = 1;
	int x;
	std::cin>>x;
	int y;
	std::cin>>y;

	while( (x&1)!=1 && (y&1)!=1 )
	{
		x>>=1;
		y>>=1;
		g<<=1;
	}
	int u = x;
	int v = y;

	int A=1;
	int B=0;
	int C=0;
	int D=1;

	while( (u&1)!=1 )
	{
		u>>=1;
		if(A==B && A== 0%2)
		{
			A>>=1;
			B>>=1;
		}
		else
		{
			A=(A+y)/2;
			B=(B-x)/2;
		}
	}

	while( (v&1)!=1 )
	{
		v>>=1;
		if(C==D && C== 0%2)
		{
			C>>=1;
			D>>=1;
		}
		else
		{
			C=(C+y)/2;
			D=(D-x)/2;
		}
	}

	return 0;
}