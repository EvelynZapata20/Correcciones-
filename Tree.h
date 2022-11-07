#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

class Nodo{    

	public:
        Nodo *der;
        Nodo *izq;
        Nodo *pag;
        Nodo *sub;
        string dato;
        string numPag;

		Nodo();	
		Nodo(string, string, Nodo*, Nodo*);
		void agregarNodo(Nodo*&, string, string, Nodo*&, Nodo*&);
		void imprimir (Nodo*);
        void impPag (Nodo*);
        void buscar(Nodo*, string);
        void buscarSub(Nodo*, string);
};
