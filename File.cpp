#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <algorithm>
#include "File.h"
//#include "Tree.h"
using namespace std;

string numeros = "0123456789";
string dato;
Nodo* apSub;
Nodo* empty;

File::File(){}

void File::lectura(){
    ifstream file;
    string texto;

    file.open("Indice.txt",ios::in);

    if (file.fail()){
        cout<<"Error leyendo el archivo";
        exit(1);
    }

    Nodo *arbol = new Nodo;

    while (!file.eof()){
        getline(file,texto);        
        split(arbol, texto);       
    }
    file.close();
    
    cout<<"---- Imprimiendo Arbol ----\n"<<endl;
    arbol->imprimir(arbol);
    //arbol->imprimir(arbol->buscarSub(arbol,"Aves"));
}

void File::split(Nodo* arbol, string text){
 
    int sw = -1;
    int index;  
    string termino;    
    string pag;
    Nodo* apPag = new Nodo();
      
    //if (text[0]=='m'){
        for(char c : text){
        sw = numeros.find(c);
            if (sw!=-1){              
                index = text.find(c);
                pag = text[index];
                termino = text.substr(1,index-1);

                for(int j = index+1; j < text.length(); j+=2){   
                    arbol->agregarNodo(apPag, "<" + text.substr(j,2) + "> " , {}, empty, empty);      
                }  
                break;
            }
        }    
   
    if (text[0]=='m'){ 
        
        Nodo *subTerminos = new Nodo;
        apSub = subTerminos;        
        dato = termino; 

        arbol->agregarNodo(arbol, dato, pag, apSub, apPag);        
      
    }else{
        arbol->agregarNodo(apSub, "\t"+termino, pag, empty, apPag);       
    }
    
}
