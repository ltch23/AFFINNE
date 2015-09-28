#include "Receiver.h"
#include "Useful.h"

Receiver::Receiver(int key , std::string alphabet)
{
	this -> key = key;
	this -> alphabet = alphabet;
};

void Receiver::cesar_decipher ( std::string & str )
{
	for( int i=0 ; i < str.size() ; i++ )
		str[i] = alphabet[ Useful::mod( int(alphabet.find( str[i] )) - key , alphabet.size() ) ];
};

void Receiver::reverse_decipher( std::string & str )
{
	for( int i=0 ; i<str.size() ; i++ )
		str[i] = alphabet[ alphabet.size() - int(alphabet.find( str[i] )) - 1 ];
};

void Receiver::rcesar_decipher( std::string & str )
{
	cesar_decipher(str);
	reverse_decipher(str);
};

void Receiver::adjust_limiters( int n , int *limiters )
{
	for(int i=1 ; i<n ;i++)
		limiters[i]++;
}

void Receiver::rail_decipher( std::string & str )
{
	
	int seg = str.size()/(key-1);
	int* limiters = new int[key];

	limiters[0] = 0;
	limiters[1] = Useful::isEven(seg) ? seg/2 : seg/2 +1 ;
	limiters[key-1] = str.size() - seg/2;

	for(int i=2 ; i<key-1 ; i++)
		limiters[i] = limiters[i-1]+(limiters[key-1]-limiters[1])/(key-2);
	
	bool toRight = true;

	for(int i=0 ; i<seg ; i++)
	{
			if(toRight)
				for(int j=0 ; j<key-1 ; j++)
				{	
					char tmp = str[limiters[j]];
					str.erase(str.begin()+limiters[j]);
					str.insert(str.begin()+limiters[0],tmp);
					if(j!=0)
						limiters[0]++;
					limiters[j]++;
					adjust_limiters(j,limiters);
				}

			else
				for(int j=key-1 ; j>0 ; j--)
				{
					char tmp = str[limiters[j]];
					str.erase(str.begin()+limiters[j]);
					str.insert(str.begin()+limiters[0],tmp);
					limiters[0]++;
					limiters[j]++;
					adjust_limiters(j,limiters);
				}
		
		toRight = not toRight;

	}
	delete [] limiters;
};

void Receiver::route_decipher( std::string & str )
{
	int row = str.size()/key;

	int x[2] = { int(str.size())/key-1 , key-1 }; // cada cuatro iteraciones se le disminuirá en dos

	int currentPos = 0;

	int * limiters = new int[key];

	for(int i=0 ; i<row ; i++)
	{
		char tmp = str[currentPos];
		str.erase(str.begin()+currentPos);
		str.insert(str.begin()+limiters[i],tmp);
		currentPos++;
		limiters[i]=currentPos;
	}
	for(int i=0 ; i<key-1 ; i++)
	{
		char tmp = str[currentPos];
		str.erase(str.begin()+currentPos);
		str.insert(str.begin(),tmp);
		currentPos++;
		for(int j=1 ; j<key ; j++)
			limiters[i]+=limiters[0];
	}
	for(int i=0 ; i<key ; i++)
		std::cout << limiters[i] << std::endl;
};

void Receiver::affinne_decipher( std::string & str , int A_i , int B )
{
	for(int i=0 ; i<str.size() ; i++)
		str[i] = alphabet[ Useful::mod( (alphabet.find(str[i]) - B)*A_i, alphabet.size() )];
};

Receiver::~Receiver() {};