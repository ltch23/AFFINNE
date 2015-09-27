#ifndef TRANSMITTER_H
#define TRANSMITTER_H

#include <string>
#include <iostream>			

class Transmitter
{
private:

	int key;
	std::string alphabet;

	u_int mod( u_int );
	void adjust_indexes( u_int , u_int* );
	bool isEven( int );

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
