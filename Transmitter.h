#ifndef EMISOR_H
#define EMISOR_H

#include <string>
#include <fstream>			//std::ofstream std::ifstream
#include <algorithm>		//std::remove
#include <iostream>			

class Emisor
{
private:

	int clave;
	std::string alfabeto;

	unsigned int help( unsigned int );
	void adjust_string( std::string & , int );
	void adjust_indexes( unsigned int , unsigned int* );
	bool isPair( int );

public:
	/*	Crypto Algorithms	*/
	void cesar_cipher( std::string & );
	void reverse_cipher( std::string & );
	void rcesar_cipher( std::string & );
	void rail_cipher( std::string & );
	void route_cipher( std::string & );
	void afinne_cipher( std::string & );


	Emisor( int , std::string );

	/* Mode of use */

	~Transmitter();

};

#endif // EMISOR_H
