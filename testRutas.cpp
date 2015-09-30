#include <iostream>
#include <string>
#include "Useful.h"

const int key = 3;

void adjust_str(std::string & str)
{
	const int adj = key-Useful::mod(str.size(),key);

	for(int i=0 ; i < adj ; i++)
		str+="x";
}

int main()
{
	std::string str("DESCIFRANDO");

	if( Useful::mod(str.size(),key) != 0)
		adjust_str(str);

	std::string str1;

	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<str.size() ; j++)
			str1 += str[ (Useful::mod(((i*str.size()+j )*key)+i , str.size() ];


	std::cout << str1 << std::endl;
	return 0;
}