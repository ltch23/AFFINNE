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

	void adjust_limiters( int, int* );

public:
	/*	Crypto Algorithms	*/
	void cesar_decipher( std::string & );
	void reverse_decipher( std::string & );
	void rcesar_decipher( std::string & );
	void rail_decipher( std::string & );
	void route_decipher(std::string & );
	void affinne_decipher( std::string & , int , int );

	Receiver( int , std::string );

	~Receiver();

};

#endif // RECEIVER_H