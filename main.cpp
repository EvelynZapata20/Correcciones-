#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "File.h"

using namespace std;

void Menu();
string nomPropio(string);
Nodo *arbol;
File *archivo = new File();

int main(){

	Menu();	
	getch();
	return 0;
}


void Menu(){

	int opcion;
	string dato;
	
	do{
		cout<<"\n==== Menu Principal ====\n";
		cout<<"1. Agregar elementos al arbol. "<<endl;
		cout<<"2. Imprimir Arbol"<<endl;
		cout<<"3. Buscar Termino"<<endl;
		cout<<"4. Buscar Subtermino"<<endl;
        cout<<"5. Salir.\n"<<endl;
		cout<<"Opcion: ";		
		cin>>opcion;
		
		
		switch(opcion){
			case 1:	arbol =	archivo->lectura();
					break;
			case 2: cout<<"---- Imprimiendo Arbol ----\n\n"<<endl;
                    arbol->imprimir(arbol);
                    cout<<"\n";
                    system("pause");
                    break;
			case 3: cout<<"Ingrese termino a buscar:"<<endl;
					cin>>dato;
					dato=nomPropio(dato);
					arbol->buscar(arbol, dato);					
					break;
			case 4: cout<<"Ingrese subtermino a buscar:"<<endl;
					cin>>dato;
					dato=nomPropio(dato);
					arbol->buscarSub(arbol, "\t"+dato);					
					break;
			case 5: cout<<"Cerrando programa!\n";
					break;
			break;
		}
		system("pause");
		system("cls");
	}while(opcion != 5);
}

string nomPropio(string dato){
	dato[0]= toupper (dato[0]);
	for (int i = 1; i < dato.length() ; i++){
		dato[i]= tolower (dato[i]);
	}
	return dato;
}
