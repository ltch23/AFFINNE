#include "Receiver.h"
#include "Transmitter.h"
#include "KeyGenerator.h"
#include "Euclides.h"

#include <iostream>
#include <string>
#include <fstream>

int main()
{
	int key ;
	std::string clave;
	
	std::cout << "Clave num: " << std::endl;
	std::cin>>key;

	std::cout << "Clave str: " << std::endl;
	std::cin>>clave;

	std::string alphabet("abcdefghijklmnopqrstuvwxyz");

	Transmitter alice( key , alphabet );
	Receiver bob( key , alphabet );

	std::string message ;
	std::cin>>message;


	u_int A,B=0;

	try
	{
		KeyGenerator::keyGenerator_RailAndRoutes(alphabet , clave , key , A , B);
	}
	catch(const char* error)
	{
		std::cerr << error << std::endl;
	}

	std::cout << A << "  " << B << std::endl;

	int A_i = Euclides::extended_inv( A , alphabet.size());

	std::cout << A_i << std::endl;
	
	int opc;
	std::cout << "cifrar (1) o decifrar (2) : "<< std::endl;
	std::cin>>opc;

	if(opc==1)
		alice.affinne_cipher( message , A , B );

	else if(opc==2)
		bob.affinne_decipher( message , A_i , B );

	std::cout << message << std::endl;




	std::cout << "El programa continua" << std::endl;
/*
	alice.route_cipher(message);
	std::cout << message << std::endl;

	bob.route_decipher(message);
	std::cout << message << std::endl;
*/
	return 0;
};