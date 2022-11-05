#ifndef TALLER_2___DATOS_TREE_H
#define TALLER_2___DATOS_TREE_H

#include<string>
using namespace std;

class Node{
public:
    string mainterm;
    int contpages;
    Node *pages;
    Node *subterms;
    Node *left;
    Node *right;

    Node();
    Node(string m, int c,Node* p, Node* s);
    Node *createNode(string, int);
    void insertNode(Node *&, string, int);
    void seeMainTree(Node *);
};


#endif //TALLER_2___DATOS_TREE_H
