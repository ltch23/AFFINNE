#include "Transmitter.h"
#include "Useful.h"
#include "Euclides.h"

Transmitter::Transmitter(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

void Transmitter::adjust_indexes( u_int x , u_int* n )
{
	for(int i=x ; i<key ; i++)
		n[i]++;
};

void Transmitter::key_generation( std::string & str , u_int & A , u_int & B )
{
	std::string str1;
	u_int size = str.size();
	u_int cont = 0;


	/*Generando la matriz que usaremos para rutas*/
	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size ; j++)
			str1 += str[(((i*size+j )*key) + i)%size];


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

	////////////////////////////////////////////////////////////////////////////

	//std::cout << last << std::endl;

	if(last != size-1)
	{
		//std::cout << "Soy diferente" << std::endl;
		int i = size-1 ;
		u_int currentPos = i;
		bool sum = true;
		char tmp;
		int laps = 0;

		for(int it = 0 ; laps < key/2 ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( Useful::isEven(j) )
				{
					for( int k=0 ; k<key-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str1[currentPos] ;
						currentPos = sum ? currentPos + size : currentPos - size ; 
					}
				}
				else
				{
					for( int k=0 ; k<size-1-last-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str1[currentPos] ;
						currentPos = sum ? (( k==size-1-last -1-1-it ) ? currentPos+size : currentPos+1 ) : currentPos-1;
					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << "" << std::endl;
			}
			laps++;
		}



		if( ! Useful::isEven(key))
		{
			for(int j=0 ;  j<size-last -key ; j++)
				std::cout << str1[currentPos--];
			std::cout << std::endl;
		}
		std::cout << "=======================================" << std::endl;
	}
};

void Transmitter::cesar_cipher ( std::string & str )
{
	for( int i=0 ; i < str.size() ; i++ )
		str[i] = alphabet[ Useful::mod( alphabet.find( str[i] ) + key , alphabet.size() ) ];
};

void Transmitter::reverse_cipher( std::string & str )
{
	for( int i=0 ; i<str.size() ; i++ )
		str[i] = alphabet[ alphabet.size() - alphabet.find( str[i] ) - 1 ];
};

void Transmitter::rcesar_cipher( std::string & str )
{
	reverse_cipher(str);
	cesar_cipher(str);
};

void Transmitter::rail_cipher( std::string & str )
{
	u_int * n = new u_int[key];
	const int seg = key-1;

	bool upFlag = false;

	u_int currentPos = 0;

	for( int i=0 ; i<=str.size()/seg && currentPos<str.size() ; i++ )
	{	
		for( int j=0 ; j<seg && currentPos<str.size() ; j++ )
		{
			//const int idx = i*seg + j
			char tmp = str[currentPos];

			str.erase(str.begin() + currentPos);
			str.insert(str.begin() + n[ upFlag ? seg - Useful::mod(currentPos,seg) : Useful::mod(currentPos,seg) ], tmp );

			adjust_indexes( upFlag ? seg - Useful::mod(currentPos,seg): Useful::mod(currentPos,seg) , n );
			currentPos++;
		}
		upFlag = not upFlag;
	}

	delete n;
};

void Transmitter::route_cipher( std::string & str )
{
	//adjust_string( str , key );

	std::string res;

	int x[2] = { int(str.size())/key-1 , key-1 }; // cada cuatro iteraciones se le disminuirá en dos

	int currentPos = str.size()-1;

	for( int i=0 ; i<( Useful::isEven(key) ? key/2 : (key-1)/2 ) ; i++ ) 	// # de capas
	{
		for( int j=0 ; j<4 ; j++ )									// # de flechas , siempre es 4
		{
			if( Useful::isEven(j) )
			{
				int idx;

				for(int k=0 ; k<x[0] ; k++)
				{
					idx =  j==0 ? currentPos-k*key : currentPos+k*key;
					res += str[idx];
				}

				if( x[0] == 0 )
				{
					res += str[currentPos];
					currentPos--;
				}

				else
					currentPos = idx + ( j==0 ? -key : key);

			}

			else
			{
				int idx;
				for(int k=0 ; k<x[1] ; k++)
				{
					idx =  j==1 ? currentPos-k : currentPos+k;
					res += str[idx];;
				}
				currentPos = idx + ( j==1 ? -1 : -key );
			}

		}
		x[0]-=2;
		x[1]-=2;
	}

	if( Useful::isEven(key) )
		str = res;
	else
		str = res + str[currentPos];
	
};

void Transmitter::affinne_cipher( std::string & str , u_int A , u_int B)
{
	//long long A = Euclides::BinaryMCD(key,alphabet.size());
	//long long A = 1;
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ Useful::mod(alphabet.find(str[i])*A + key , alphabet.size() )];
}

Transmitter::~Transmitter(){};