#ifndef EUCLIDES_H
#define EUCLIDES_H

#include <vector>
#include <iostream>

class Euclides
{
public:
	static long long MCD( long long , long long );
	static long long MCD ( long long , long long , std::vector<long long>& );
	static long long BinaryMCD( long long , long long );
	static long long MenorResto( long long , long long );
	static void extended( long long , long long );
	static long long extended_inv(long long , long long );
};

long long Euclides::MCD( long long a , long long b )
{
	long long q = a/b;
	long long r = a - b*q;

	while( r>0 )
	{
		a = b;
		b = r;
		q = a/b;
		r = a - b*q;
	}

	return b;
};

long long Euclides::MCD( long long a , long long b , std::vector<long long>& Q)
{
	long long q = a/b;
	long long r = a - b*q;

	Q.push_back(q);

	while( r>0 )
	{
		a = b;
		b = r;
		q = a/b;
		r = a - b*q;
		Q.push_back(q);
	}

	return b;
};

long long Euclides::BinaryMCD( long long a , long long b )
{
	long long g = 1;

	while( (a&1)!=1 && (b&1)!=1 )
	{
		a=a>>1;
		b=b>>1;
		g=g<<1;
	}

	while( a!= 0 )
	{
		while((a&1)!=1)
			a=a>>1;

		while((b&1)!=1)
			b=b>>1;

		long long t= b>a ? b-a : a-b;

		if( a>=b )
			a=t;
		else
			b=t;
	}

	return g*b;
};

long long Euclides::MenorResto( long long a , long long b )
{
	long long c , d ,r ;

	if(a==0)
		c=b;
	else
	{
		c=a;
		d=b;
		while(d!=0)
		{
			std::cout << "1" << std::endl;
			r= c-d*int(c/d+1/2);
			c=d;
			d=r;
		}
	}

	return c>0?c:-c;

};

void Euclides::extended( long long a , long long b )
{
	long long r,s,t;

	long long r1 = a;
	long long r2 = b;
	long long s1 = 1;
	long long s2 = 0;
	long long t1 = 0;
	long long t2 = 1;

	while(r2>0)
	{
		long long q = r1/r2;

		r = r1 - q*r2;
		r1 = r2;
		r2 = r;

		s = s1 - q*s2;
		s1 = s2;
		s2 = s;

		t = t1 - q*t2;
		t1 = t2;
		t2 = t;
	}

	return;
};

long long mod( long long a , long long b )
{
	if(a>b)
		return a%b;
	else
		return b%a;
};

long long Euclides::extended_inv( long long a , long long b )
{

	std::vector<long long> Q;

	long long r = MCD( a , b , Q );

	if(r!=1)
		throw "Resto diferente de 1";
	else
	{
		int s2 = 0 , s1 = 1 ;
		long long inv = 0;

		for(int i=0 ; i < Q.size() ; i++)
		{
			inv = mod(s2 - s1*Q[i],b);
			/*std::cout << s2 << "-" << s1 << "*" << Q[i] << std::endl;
			std::cout << inv << std::endl;*/
			s2 = s1;
			s1 = inv;
		}

	return inv ;

	}
};

#endif // EUCLIDES_H
