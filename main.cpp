#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "File.h"
//#include "Tree.h"

using namespace std;

void Menu();
//Nodo *arbol = new Nodo("Hormiga","7");
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
		cout<<"1. Agregar elementos al arbol. "<<endl;
		cout<<"2. Imprimir Arbol"<<endl;
		cout<<"3. Buscar Dato"<<endl;
        cout<<"4. Salir."<<endl;
		cout<<"\nOpcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:	archivo->lectura();/*					
                    arbol->agregarNodo(arbol,"Hormiga","7");
                    arbol->agregarNodo(arbol,"Gato","4");
                    arbol->agregarNodo(arbol,"Perro","5");
                    arbol->agregarNodo(arbol,"Oveja","3");
                    arbol->agregarNodo(arbol,"Vaca","8");
                    arbol->agregarNodo(arbol,"Abeja","6");
                    arbol->agregarNodo(arbol,"Buho","2");
                    arbol->agregarNodo(arbol,"Tigre","1");
                    //*/
					break;
			case 2: cout<<"---- Imprimiendo Arbol ----\n\n"<<endl;
                    arbol->imprimir(arbol);
                    cout<<"\n";
                    system("pause");
                    break;
			case 3: cout<<"Ingrese valor a buscar:"<<endl;
					cin>>dato;
					arbol->buscar(arbol, dato);					
					break;
        break;
		}
		system("pause");
		system("cls");
	}while(opcion != 4);
}
