#include <iostream>
#include <string>
#include "Useful.h"

int key;

void adjust_str(std::string & str)
{
	const int adj = key-Useful::mod(str.size(),key);

	for(int i=0 ; i < adj ; i++)
		str+="x";
}

int main()
{
	/*
	std::cin>>key;
	std::string str;
	std::cin>>str;
	*/

	key = 5;
	std::string str = "abcdefghijklmnopqrstuvwxy";

	/* Ajustamos el string */

	if( Useful::mod(str.size(),key) != 0)
		adjust_str(str);


	std::cout << str << std::endl;


	/*creamos los limites*/
	const int num_limit = str.size()/key-1;

	int * limiters = new int[num_limit];

	for(int i=1 ; i<=num_limit ; i++)
	{
		limiters[i-1] += (i)*key ;
		//std::cout << limiters[i-1] << std::endl;
	}

	std::string str1;

	/*RECORRIDO*/

	bool block = true;
	u_int cont = key;
	u_int jump = 1;
	bool toLeft = true;
	u_int it=0;

	for(int i=0 ; i<key ; i++)
	{
		for(int j= (toLeft?1+it:num_limit-it) ; toLeft?(j<=num_limit-1-it):j>1+it ; toLeft?j++:j-- )
		{
			if(block)
			{
				for(int k=0 ; k<cont ; k++)
				{
					str1 += str[limiters[num_limit-j]+(toLeft?k+it:-k-1-it)];
					std::cout << str1[str1.size()-1] << std::endl;
				}
				block = not block;
				std::cout << "---------------------------------------" << std::endl;
			}
			str1 += str[limiters[num_limit-j]+(toLeft?-jump:jump-1)];

			std::cout << str1[str1.size()-1] <<std::endl;

		}
		std::cout << "=======================================" << std::endl;
		block = not block;
		toLeft = not toLeft;

		if(! Useful::isEven(i))
		{
			it++;
			jump++;
			cont-=2;
		}
	}





	return 0;
}
