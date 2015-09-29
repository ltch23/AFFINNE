#include "KeyGenerator.h"
#include <iostream>
#include "Euclides.h"

void KeyGenerator::keyGenerator_RailAndRoutes( std::string & alphabet , std::string & str , u_int key , u_int & A , u_int & B )
{
	std::string str1;
	u_int size = str.size();
	u_int cont = 0;


	/*Generando la matriz que usaremos para rutas*/
	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size ; j++)
			str1 += str[ (Useful::mod(((i*size+j )*key) + i,size)) ];

/*
	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str1[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}
*/

/*	GENERACION CLAVE A 	*/
	/*Empezamos con la ultima fila*/

	bool Afounded = false;

	for( int i=key-1 ; i<size && !Afounded; i=i+2*key-2 )
	{
		A = ( alphabet.find(str[i]) + alphabet.find( str1[size*(key-1)+i] ) );
		if( Euclides::BinaryMCD( A,alphabet . size() ) == 1 )
			Afounded = true;
		cont++;
	}

	/*Recorreremos tomando como pivote los picos de la ultima fila*/
	for( int i=key-1 ; i<size ; i=i+2*key-2 )
	{
		/*IZQUIERDA : 	
		En el primer caso iremos 'key' veces, despues solo 'key-1' dado que 
		cuando recorrimos hacia la izquierda ya tocamos el pico de la fila */
		for(int j=1 ; i==key-1 ? (j<key && i-j<size && !Afounded ):(j<key-1 && i-j<size-1 && !Afounded) ; j++)
		{
			A = ( alphabet.find( str[i-j] ) + alphabet.find( str1[size*(key-1-j)+i-j] ) );
			if( Euclides::BinaryMCD( A,alphabet . size() ) == 1 )
				Afounded = true;
			cont++;
		}
		/*DERECHA:
		Siempre recorremos 'key' veces*/
		for(int j=1 ; j<key && i+j<size && !Afounded ; j++)
		{
			A = ( alphabet.find( str[i+j] ) + alphabet.find( str1[size*(key-1-j)+i+j] ) );
			if( Euclides::BinaryMCD( A,alphabet . size() ) == 1 )
				Afounded = true;
			cont++;
		}
	}

	/*si no hemos recorrido toda la palabra*/
	if(cont<size)
	{
		u_int aux = size-cont;
		for(int i=size-1 ; i>=cont && !Afounded ; i--)
		{
			A = ( alphabet.find( str[i] ) + alphabet.find( str1[aux*size+i] ) );
			if( Euclides::BinaryMCD( A,alphabet . size() ) == 1 )
				Afounded = true;
			aux--;
		}
	}

	if( !Afounded )
		throw "No se puede generar la  clave A con ese mensaje . =( ";

/*****************************************************************************/

/*	GENERACION CLAVE B 	*/
	u_int last = 0;
	for( int i=key-1 ; i<size ; i+=2*key-2 )
	{
		last = i ;
		u_int currentPos = i;
		bool sum = true;
		char tmp;
		int laps = 0;

		for(int it = 0 ; laps < key/2 ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( Useful::isEven(j) )
					for( int k=0 ; k<key-1-it ; k++ )
					{
						std::swap(tmp,str1[currentPos]);
						currentPos = sum ? currentPos + size : currentPos - size ; 
					}

				else
					for( int k=0 ; (i == key-1) ? (k<key-1-it) : (k<2*key-2-it -1) ; k++ )
					{
						std::swap(tmp,str1[currentPos]);

						if(i == key-1)
							currentPos = sum ? (k==key-1-it -1 ? currentPos+size :currentPos+1) : currentPos-1 ;
						else
							currentPos = sum ? (( k==2*key-2-it-1 -1 ) ? currentPos+size : currentPos+1 ) : currentPos-1;
					}
				sum = (j==0 || j==1) ? false : true;  
			}
			laps++;
		}

		if( ! Useful::isEven(key))
			for(int j=0 ; i==key-1 ? j<1 : j<key-1 ; j++)
			{
				std::swap(tmp,str1[currentPos]);
				currentPos--;
			}

		str1[i] = tmp;

		for(int j=0 ; j<key ; j++)
			B += alphabet.find( str1[i+j*(size-1)] );
	}




	////////////////////////////////////////////////////////////////////////////

	std::cout << size-last-1<< std::endl;
	if(last != size-1)
	{
		int i = size-1 ;
		u_int currentPos = i;
		bool sum = true;

		char tmp;

		int vueltas = 0;
		int numAux= size-last-1;
		Useful::isEven(numAux)?(numAux==0? numAux=1:numAux=numAux/2):(numAux=(numAux/2)+1);
		int contadorx = 0;
		int total = (size-last-1)*key;

		for(int it = 0 ; vueltas < numAux && contadorx < total ; it=it+2)
		{
			for(int j=0 ; j<4 && contadorx < total ; j++)
			{
				if( Useful::isEven(j) )
				{
					for( int k=0 ; k<key-1-it && contadorx < total ; k++ )
					{
						std::swap(tmp,str1[currentPos]);
						currentPos = sum ? currentPos + size : currentPos - size ; 
						contadorx++;
					}
				}
				else
				{
					for( int k=0 ; k<size-1-last-1-it && contadorx < total ; k++ )
					{
						std::swap(tmp,str1[currentPos]);
						currentPos = sum ? (( k==size-1-last -1-1-it ) ? currentPos+size : currentPos+1 ) : currentPos-1;
						contadorx++;
					}
				}
				sum = (j==0 || j==1) ? false : true;  
			}
			vueltas++;
		}

		if( ! Useful::isEven(key))
		{
			for(int j=0 ;  j<size-last && contadorx < total ; j++)
			{
				std::swap(tmp,str1[currentPos]);
				currentPos--;
				contadorx++;
			}
		}

		std::swap(tmp,str1[i]);

		for(int j=0 ; j<size-1-last && j<key; j++)
			B += alphabet.find( str1[i+j*(size-1)] );
	}
/*
	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str1[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}
*/
};