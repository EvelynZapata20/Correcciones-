#include <iostream>
#include "Tree.cpp"
#include "Tree.h"
#include "File.cpp"

using namespace std;

int main() {
    int dato, opcion;
    string word;

    do {
        cout << ".:MENU:." << endl;
        cout << "1. Insertar un nuevo nodo" << endl;
        cout << "2. Imprimir arbol" << endl;
        cout << "3. Leer archivo" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion:" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nHello: ";
            case 2:
                seeMainTree(mainTree);
                //seeMainTree(mainTree->pages);
            case 3:
                lectura();
                system("pause");
        }
    } while (opcion!=4);
}