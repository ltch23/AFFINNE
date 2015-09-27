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
			
		}
	}

	return 0;
}