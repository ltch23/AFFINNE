#include <iostream>
#include <string>
#include <utility>


bool isEven(int n)
{
	if(n&1 == 1)
		return false;
	return true;
}

int main()
{
	std::string alphabet("ABCDEFGHIJKLMN0PQRSTUVXYZ")
	std::string strVallas("ABCDEFGHIJ");
	std::string str;
	u_int key = 3;

	u_int size = strVallas.size();
	u_int contVallas = 0;

	for(int i=0 ; i<key ; i++)
		for(int j=0 ; j<size ; j++)
			str += strVallas[(((i*size+j )*key) + i)%size];



	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;


	for( int i=key-1 ; i<size ; i=i+2*key-2 )
	{
		std::cout << strVallas[i] << "  con  " << str[size*(key-1)+i] << std::endl;
		contVallas++;
	}

	std::cout << "=======================================" << std::endl;

	for( int i=key-1 ; i<size ; i=i+2*key-2 )
	{
		for(int j=1 ; i==key-1 ? (j<key && i-j<size):(j<key-1 && i-j<size-1) ; j++)
		{
			std::cout << strVallas[i-j] << "  con  " << str[size*(key-1-j)+i-j] << std::endl;
			contVallas++;
		}

	std::cout << "=======================================" << std::endl;

		for(int j=1 ; j<key && i+j<size; j++)
		{
			std::cout << strVallas[i+j] << "  con  " << str[size*(key-1-j)+i+j] << std::endl;
			contVallas++;
		}

	std::cout << "=======================================" << std::endl;
	}

	if(contVallas<size)
	{
		u_int aux = size-contVallas;
		for(int i=size-1 ; i>=contVallas ; i--)
		{
			std::cout << strVallas[i] << "  con  " << str[aux*size+i] << std::endl;
			aux--;
		}
	}


	u_int last = 0;
	for( int i=key-1 ; i<size ; i+=2*key-2 )
	{
		last = i ;
		u_int currentPos = i;
		bool sum = true;
		char tmp;
		int vueltas = 0;

		for(int it = 0 ; vueltas < key/2 ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( isEven(j) )
				{
					for( int k=0 ; k<key-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str[currentPos] ;

						std::swap(tmp,str[currentPos]);

						currentPos = sum ? currentPos + size : currentPos - size ; 
					}
				}
				else
				{
					for( int k=0 ; (i == key-1) ? (k<key-1-it) : (k<2*key-2-it -1) ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str[currentPos] ;

						std::swap(tmp,str[currentPos]);

						if(i == key-1)
							currentPos = sum ? (k==key-1-it -1 ? currentPos+size :currentPos+1) : currentPos-1 ;

						else
						{
							//std::cout << "He entrado aqui" << std::endl;
							currentPos = sum ? (( k==2*key-2-it-1 -1 ) ? currentPos+size : currentPos+1 ) : currentPos-1;
						}

					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << std::endl;
			}
			vueltas++;
		}
		//std::cout << currentPos << std::endl;

		if( ! isEven(key))
		{
			for(int j=0 ; i==key-1 ? j<1 : j<key-1 ; j++)
			{
				std::swap(tmp,str[currentPos]);

				std::cout << str[currentPos--];
			}
			std::cout << std::endl;
		}

		str[i] = tmp;

		std::cout << "=======================================" << std::endl;

	}



	std::cout << std::endl;
	for(int i=0 ; i<key ; i++)
	{
		std::cout << "	";	
		for(int j=0 ; j<size ; j++)
		{
			std::cout << str[i*size+j] << " ";
			if(i*size+j == i*size + key-1 || i*size+j == i*size + (key-1) + 2*key-2 )
				std::cout << "| ";
		}
		std::cout << std::endl;
	}

	////////////////////////////////////////////////////////////////////////////

	//std::cout << last << std::endl;

	if(last != size-1)
	{
		//std::cout << "Soy diferente" << std::endl;
		int i = size-1 ;
		u_int currentPos = i;
		bool sum = true;
		char tmp;
		int vueltas = 0;

		for(int it = 0 ; vueltas < key/2 ; it=it+2)
		{
			for(int j=0 ; j<4 ; j++)
			{
				if( isEven(j) )
				{
					for( int k=0 ; k<key-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str[currentPos] ;
						currentPos = sum ? currentPos + size : currentPos - size ; 
					}
				}
				else
				{
					for( int k=0 ; k<size-1-last-1-it ; k++ )
					{
						//std::cout << currentPos << std::endl;
						std::cout << str[currentPos] ;
						currentPos = sum ? (( k==size-1-last -1-1-it ) ? currentPos+size : currentPos+1 ) : currentPos-1;
					}
				}
				sum = (j==0 || j==1) ? false : true;  
				std::cout << "" << std::endl;
			}
			vueltas++;
		}



		if( ! isEven(key))
		{
			for(int j=0 ;  j<size-last -key ; j++)
				std::cout << str[currentPos--];
			std::cout << std::endl;
		}
		std::cout << "=======================================" << std::endl;
	}

	


	//std::cout << strMatriz << std::endl;
	return 0;
}