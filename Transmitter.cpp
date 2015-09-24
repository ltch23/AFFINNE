#include "Transmitter.h"

Transmitter::Transmitter(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

unsigned int Transmitter::help( unsigned int idx )
{
	/* actua como modulo*/
	return idx-(idx/alphabet.size())*alphabet.size();
};

void Transmitter::adjust_indexes( unsigned int x , unsigned int* n )
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

	adjust_string( str , key -1 );

	unsigned int * n = new unsigned int[key];
	const int seg = key-1;

	bool upFlag = false;

	for( int i=0 ; i<str.size()/seg ; i++ )
	{	
		for( int j=0 ; j < seg ; j++ )
		{
			const int idx = i*seg + j;
			char tmp = str[idx];

			str.erase(str.begin() + idx);
			str.insert(str.begin() + n[ upFlag ? seg - idx%seg : idx%seg ], tmp );

			adjust_indexes( upFlag ? seg - idx%seg: idx%seg , n );
		}
		upFlag = not upFlag;
	}

	delete n;
};



void Transmitter::route_cipher( std::string & str )
{
	adjust_string( str , key );

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

void Transmitter::afinne_cipher( std::string & str)
{
	long long A = Euclides::BinaryMCD(key,alphabet.size());
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ help(alphabet.find(str[i])*A + key )];
}

Transmitter::~Transmitter(){};