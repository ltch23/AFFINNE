#include "receptor.h"
#include <string>
#include <iostream>


using namespace std;

string descifrado(string mensaje, int a_clave){

    int columnas = a_clave;
    int cont =1;
    string respuesta;
    respuesta.append(mensaje.size(),'*');

    int r=0, pb = mensaje.size()-1,pf = 0, c=0 , cantidad=columnas;
	
	while(mensaje.size()>0){
    for(r+=columnas-1,c=0; r<pb+1; r+=columnas){
        respuesta[r]=mensaje[c];
        mensaje.erase(c,1);
    }
    // cout<<"1"<<endl;
     // cout<<respuesta<<endl;

    for(r=pb-1,c=0;r>pb-cantidad; r--,c++){
        respuesta[r]=mensaje[c];
    }
     // cout<<"2"<<endl;
     // cout<<respuesta<<endl;
    mensaje.erase(0,c);
    pb-=(cantidad);
    cantidad--;

    for(r= pb -(columnas-1),c=0;mensaje.size()>0 && r>pf;r-=(columnas)){
        respuesta[r]=mensaje[c];
        mensaje.erase(c,1);
    }
     // cout<<"3"<<endl;
     // cout<<respuesta<<endl;

    for(r=pf,c=0; r<pf+(cantidad) && mensaje.size()>0;r++,c++){
        respuesta[r]=mensaje[c];
    }
    mensaje.erase(0,c);
    pf+=columnas+1;
     // cout<<"4"<<endl;
     // cout<<respuesta<<endl;
    pb-=1;
    cantidad--;
}
    int h = respuesta.find('*');
    while(h!=string::npos){
        respuesta.erase(h,1);
        h=respuesta.find('*');
    }
    return respuesta;

}

int main()

{int num=3;
string str="ghifcbade"; //mensaje cifrado
int size=str.size();
string str1;
cout<<" mensaje:  "<<str<<endl;
string rpta1;
rpta1=descifrado(str,num);

	for(int i=0 ; i<3 ; i++)
		for(int j=0 ; j<3 ; j++)
		{
			str1 += rpta1[ (((i*(size)+j )*num) + i)%(size)];
		}

cout<<" desc  "<<str1<<endl;
	
	return 0;
}



