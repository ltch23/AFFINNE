#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <string>
#include <iostream>			

class Transmitter
{
private:

	int key;
	std::string alphabet;

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
	void affinne_cipher( std::string & );


	Transmitter( int , std::string );

	/* Mode of use */

	~Transmitter();

};

#endif // TRANSMITTER_H
