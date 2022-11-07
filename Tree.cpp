#include<iostream>
#include<conio.h>
#include<stdlib.h>
//#include "File.h"
#include "Tree.h"

using namespace std;

Nodo::Nodo(){ // Constructor de un Nodo vacío
	this->dato = "";
    this->numPag = "";
	this->der = nullptr;
	this->izq = nullptr;
    this->sub = nullptr;
    this->pag = nullptr;
}

Nodo::Nodo(string dato, string n, Nodo* sub, Nodo* pag){ // Constructor de un Nodo con todos sus datos
	this->dato = dato;
    this->numPag = n;
	this->der = nullptr;
	this->izq = nullptr;
    this->sub = sub;
    this->pag = pag;
}


// Agrega un nuevo Nodo invocando al Constructor Nodo según los valores recibidos
void Nodo::agregarNodo(Nodo *&arbol, string dato, string n, Nodo *&subTer, Nodo *&pag){
	if(arbol == NULL){//verificando que arbol este vacio.
		Nodo *nuevoNodo = new Nodo(dato, n, subTer, pag);//agregando la raiz al nuevo Nodo.
		arbol = nuevoNodo;
	}else{
		string ValorDeRaiz = arbol->dato;//Es para saber que valor tiene la RAIZ.
		if(dato < ValorDeRaiz){//Cuando el Valor es menor va al lado izquierdo.
			agregarNodo(arbol->izq, dato, n, subTer, pag);//Agregando al lado izquierdo.
		}else{
			agregarNodo(arbol->der, dato, n, subTer, pag);//Agregando al lado derecho.
		}
	}
}

// Recorre recursivamente el arbol para imprimir los Términos, Subtérminos y Páginas de manera ordenada
void Nodo::imprimir (Nodo *arbol){	
    if (arbol == NULL){
        return; 
    }
    else{				
        imprimir(arbol->izq);
			if(arbol->dato!=""){	
        	cout<<arbol->dato<<" | "<<arbol->numPag<<" | ";
			impPag(arbol->pag); // Llama a la función para imprimir las páginas enviando el respectivo Nodo
			cout<<endl;
			imprimir(arbol->sub); // Se invoca a si misma enviando el Nodo de los Subtérminos		
		}
        imprimir(arbol->der);
    }
}


// Función que imprime las paginas de forma ordenada utilizando la recursividad
void Nodo::impPag (Nodo *arbol){
    if (arbol == NULL){
        return; 
	}else{		
		impPag(arbol->izq);
		if(arbol->dato!=""){			
			cout<<arbol->dato;
		}
		impPag(arbol->der);
			
	}
}


// Imprime el Término buscado y con sus Subtérminos y atributos
void Nodo::buscar(Nodo *arbol, string dato){
    if (arbol == NULL){
       return;
    }
    else if(arbol->dato == dato){
        	cout<<arbol->dato<<" | "<<arbol->numPag<<" | ";
			impPag(arbol->pag); // Llama a la función para imprimir las páginas
			cout<<endl;
			imprimir(arbol->sub); // Se invoca a si misma enviando el Nodo de los Subtérminos		
			cout<<endl;
			return;
    }
    else if(dato < arbol->dato){
        return buscar(arbol->izq, dato);
    }
    else {
        return buscar(arbol->der, dato);
    }
}

// Imprime el subtérmino buscado y sus atributos
void Nodo::buscarSub(Nodo *arbol, string dato){
	//string termino;
	if (arbol == NULL){
        return; 
    }
    else{		
		buscarSub(arbol->izq, dato);
		buscar(arbol->sub, dato);
		buscarSub(arbol->der, dato);
	}
		
}
