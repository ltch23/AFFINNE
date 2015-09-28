#include "Receiver.h"
#include "Transmitter.h"
//#include "Euclides.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	int key = 5;
	std::string alphabet("abcdefghijklmnopqrstuvwxyz .;");

	//Receiver bob( key , alphabet );
	Transmitter alice( key , alphabet );

	std::string message ="clave5luistontong";

	alice.rail_cipher(message);

	std::cout << message << std::endl;

	//bob.rail_decipher(message);

	std::cout << message << std::endl;




	std::string clave("ccccccccccccccccccccccc");

	u_int A,B;

	try
	{
		alice.key_generation(clave, A , B);
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}

	std::cout << "El programa continua" << std::endl;
/*
	alice.route_cipher(message);
	std::cout << message << std::endl;

	bob.route_decipher(message);
	std::cout << message << std::endl;
*/
	return 0;
};