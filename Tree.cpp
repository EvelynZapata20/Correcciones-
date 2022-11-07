#include<iostream>
#include<conio.h>
#include<stdlib.h>
//#include "File.h"
#include "Tree.h"

using namespace std;

Nodo::Nodo(){
	this->dato = "";
    this->numPag = "";
	this->der = nullptr;
	this->izq = nullptr;
    this->sub = nullptr;
    this->pag = nullptr;
}

Nodo::Nodo(string dato, string n, Nodo* sub, Nodo* pag){
	this->dato = dato;
    this->numPag = n;
	this->der = nullptr;
	this->izq = nullptr;
    this->sub = sub;
    this->pag = pag;
}

void Nodo::agregarNodo(Nodo *&arbol, string dato, string n, Nodo *&subTer, Nodo *&pag){
	//cout<<("Ingresa a agregarNodo")<<endl;
	if(arbol == NULL){//verificando que arbol este vacio.
		Nodo *nuevoNodo = new Nodo(dato, n, subTer, pag);//agregando la raiz al nuevo Nodo.
		arbol = nuevoNodo;
		//cout<<("Nodo raiz creado")<<endl;
	}else{
		string ValorDeRaiz = arbol->dato;//Es para saber que valor tiene la RAIZ.
		if(dato < ValorDeRaiz){//Cuando el Valor es menor va al lado izquierdo.
			agregarNodo(arbol->izq, dato, n, subTer, pag);//Agregando al lado izquierdo.
			//cout<<("Nodo izquierdo creado")<<endl;
		}else{
			agregarNodo(arbol->der, dato, n, subTer, pag);//Agregando al lado derecho.
			//cout<<("Nodo derecho creado")<<endl;
		}
	}
}

void Nodo::imprimir (Nodo *arbol){	
    if (arbol == NULL){
        return;
    }
    else{
		
		//imprimir(arbol->sub);			
        imprimir(arbol->izq);
		imprimir(arbol->sub);		
		
		if(arbol->dato!=""){		
        	cout<<arbol->dato<<" | "<<arbol->numPag<<" | ";
			impPag(arbol->pag);
			cout<<endl;
		}
        imprimir(arbol->der);
		//cout<<arbol->dato<<" | "<<arbol->numPag<<" | "<<endl;
    }
}

void Nodo::impPag (Nodo *arbol){
	//cout<<"entra a paginas "<< arbol<<endl;
	//string pagi=p;
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

void Nodo::buscar(Nodo *arbol, string dato){
    if (arbol == NULL){
       cout<<"Arbol vacio"<<endl;
    }
    else if(arbol->dato == dato){
        cout<<arbol->dato<<" | "<<arbol->numPag<<" | "<<arbol->sub<< endl;
    }
    else if(dato < arbol->dato){
        return buscar(arbol->izq, dato);
    }
    else {
        return buscar(arbol->der, dato);
    }
}

Nodo* Nodo::buscarSub(Nodo *arbol, string dato){
    if (arbol == NULL){
		//cout<<"NULL en buscarSub: " <<endl;
        return {};
    }
    else if(arbol->dato == dato){
		//cout<<"Funcion buscarSub: "<< arbol->sub <<" para "<< arbol->dato<<endl;
        return arbol->sub;
    }
    else if(dato < arbol->dato){
		//cout<<"Buscando por la izquierda: "<< arbol->dato<<endl;
        return buscarSub(arbol->izq, dato);
    }
    else {
		//cout<<"Buscando por la derecha: "<< arbol->dato<<endl;
        return buscarSub(arbol->der, dato);
    }
}
