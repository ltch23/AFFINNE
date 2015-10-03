#include <iostream>
#include <string>
#include "Useful.h"

int key;

void adjust_str(std::string & str)
{
	// ajustaremos en caso que mod sea diferente de 0 , sino lo es regresa como estaba
	int mod=Useful::mod(str.size(),key);
	if(mod!=0)
	{
	const int adj = key- Useful::mod(str.size(),key);
	for(int i=0 ; i < adj ; i++)
	str+="x";
	}
}

int main(int argc, char const *argv[])
{

	std::string str("luistequieremuchopatusabejeje");
	key = 5;
	adjust_str(str);
	std::string str1;

	unsigned int size = str.size();
	unsigned int contVallas = 0;
	//usamos contadorx para rstringrir que solo ingrese size veces al programa
	unsigned int contadorx=0;
	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size/key ; j++)
			str1 += str[ (((i*(size)+j )*key) + i)%(size)];


		std::cout << str1 << std::endl;

		std::string str2;

		int i=(size/key)-1; 
		unsigned int currentPos = i;
		bool sum = true;
		
		int vueltas = 0;
		//lo demas es muy parecido al key generator solo varia key por size/key
		for(int it = 0 ; vueltas < (key/2) ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( Useful::isEven(j) )
				{
					for( int k=0 ; k<key-1-it  && contadorx < size; k++ )
					{
						std::cout << str1[currentPos] ;
						str2 += str1[currentPos];
						currentPos = sum ? currentPos + (size/key) : currentPos - (size/key) ; 
						contadorx++;
					}
				}
				else
				{
					for( int k=0 ; k <(size/key)-1-it && contadorx < size; k++ )
					{
						std::cout << str1[currentPos] ;
						str2 += str1[currentPos];
						currentPos = sum ? (k==(size/key)-1-it-1 ? currentPos+(size/key) :currentPos+1) : currentPos-1 ;
						contadorx++;
					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << std::endl;
			}
			vueltas++;
		}
		std::cout<<"**************************************************"<<std::endl;
		
		//usamos el buen conocido key cuando es impar y mejor al size/key
		if( ! Useful::isEven(key)&& key<=size/key)
		{
			for(int j=0 ;  j<((size/key)/2)-1 ; j++)
			{
				str2 += str1[currentPos];
				std::cout << str1[currentPos--]<<std::endl;
			}
		}

	std::cout << str2 << std::endl;

	//por lo demas ahi esta =)
	return 0;
}
