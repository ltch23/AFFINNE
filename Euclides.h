#ifndef EUCLIDES_H
#define EUCLIDES_H

#include <vector>
#include <iostream>
#include "Useful.h"

class Euclides
{
public:
	static long long MCD( long long , long long );
	static long long MCD ( long long , long long , std::vector<long long>& );
	static long long BinaryMCD( long long , long long );
	static long long MenorResto( long long , long long );
	static void extended( long long , long long );
	//static long long extended_inv(long long , long long );
	static int extended_inv(int , int );
};

#endif // EUCLIDES_H
