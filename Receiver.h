#ifndef RECEIVER_H
#define RECEIVER_H

#include <string>
#include <fstream>
#include <iostream>

class Receiver
{
private:

	int key;
	std::string alphabet;

	unsigned int help( int );
	void adjust_string( std::string & );
	void adjust_indexes( unsigned int , unsigned int* );
	void adjust_limiters( int, int* );
	bool isPair(int n);

public:
	/*	Crypto Algorithms	*/
	void cesar_decipher( std::string & );
	void reverse_decipher( std::string & );
	void rcesar_decipher( std::string & );
	void rail_decipher( std::string & );
	void route_decipher(std::string & );
	void afinne_decipher( std::string & );

	Receiver( int , std::string );

	~Receiver();

};

#endif // RECEIVER_H