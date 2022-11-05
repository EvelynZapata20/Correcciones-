#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include <algorithm>
#include "Tree.h"
using namespace std;

void lectura();
void split(string);

void lectura(){
    ifstream indice;
    string texto;

    indice.open("C:\\Users\\Usuario\\CLionProjects\\Taller 2 Datos\\Indice.txt",ios::in);

    if (indice.fail()){
        cout<<"Error leyendo el archivo";
        exit(1);
    }

    while (!indice.eof()){
        getline(indice,texto);
        //cout<<texto<<endl;
        split(texto);
    }
    indice.close();
}

void split(string text){

    string numeros = "0123456789";
    int sw = -1;
    int index;
    string tipo;
    string termino;
    int pag;
    string paginas;

    if (text[0]=='m'){
        tipo = "Termino";
    }
    else{
        tipo = "Subtermino";
    }

    for(char c : text) {
        sw = numeros.find(c);
        if (sw != -1) {
            index = text.find(c);
            pag = text[index];
            termino = text.substr(1, index - 1);
            //paginas = text.substr(index+1,2);
            for (int j = index + 1; j < text.length(); j += 2) {
                paginas = text.substr(j, 2);
                Node *subTree = new Node;
                if (tipo == "Termino") {
                    Node *pagTree = nullptr;
                    insertNode(pagTree, paginas, NULL, NULL, NULL);
                    insertNode(mainTree, termino, pag, pagTree, subTree);
                } else {
                    Node *pagTree = nullptr;
                    insertNode(pagTree, paginas, NULL, NULL, NULL);
                    insertNode(subTree, termino, pag, pagTree, NULL);
                }
            }
                //cout<<"La palabra "<<termino<<" es un "<<tipo<<" y aparece en  "<<pag<<" paginas asi: "<< paginas<<endl;


            break;
        }
    }
}