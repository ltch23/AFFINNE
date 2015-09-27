#include "Transmitter.h"

Transmitter::Transmitter(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

u_int Transmitter::help( u_int idx )
{
	/* actua como modulo*/
	return idx-(idx/alphabet.size())*alphabet.size();
};

void Transmitter::adjust_indexes( u_int x , u_int* n )
{
	for(int i=x ; i<key ; i++)
		n[i]++;
};

bool Transmitter::isEven( int n )
{
	if( n&1 == 1 )
		return false;
	return true;
};


void Transmitter::cesar_cipher ( std::string & str )
{
	for( int i=0 ; i < str.size() ; i++ )
		str[i] = alphabet[ help( alphabet.find( str[i] ) + key  ) ];
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
			//const int idx = i*seg + j;
			char tmp = str[currentPos];

			str.erase(str.begin() + currentPos);
			str.insert(str.begin() + n[ upFlag ? seg - currentPos%seg : currentPos%seg ], tmp );

			adjust_indexes( upFlag ? seg - currentPos%seg: currentPos%seg , n );
			//std::cout << currentPos << std::endl;
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

	for( int i=0 ; i<( isEven(key) ? key/2 : (key-1)/2 ) ; i++ ) 	// # de capas
	{
		for( int j=0 ; j<4 ; j++ )									// # de flechas , siempre es 4
		{
			if( isEven(j) )
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

	if( isEven(key) )
		str = res;
	else
		str = res + str[currentPos];
	
};

void Transmitter::affinne_cipher( std::string & str)
{
	//long long A = Euclides::BinaryMCD(key,alphabet.size());
	long long A = 1;
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ help(alphabet.find(str[i])*A + key )];
}

Transmitter::~Transmitter(){};