#include "Tree.h"

using namespace std;

Node::Node() {
    this -> mainterm = {};
    this -> contpages = NULL;
    this -> pages = nullptr;
    this -> subterms = nullptr;
    this -> left = nullptr;
    this -> right = nullptr;
}

//Crea los demás términos
Node::Node(string m, int c, Node* p, Node* s){
    this -> mainterm = m;
    this -> contpages = c;
    this -> pages = p;
    this -> subterms = s;
    this -> left = nullptr;
    this -> right = nullptr;
}

Node *mainTree = nullptr;


void insertNode (Node *&mainTree, string m, int c, Node* p, Node* s){
    Node* new_Node=new Node(m,c,p,s);
    if (mainTree==NULL){
        mainTree = new_Node;
    }
    else {
        string maintermRoot = mainTree->mainterm;
        if ((m.compare(maintermRoot))==-1){
            insertNode(mainTree->left,m,c,p,s);
        }
        else {
            insertNode(mainTree->right,m,c,p,s);
        }
    }
}

void seeMainTree (Node *mainTree){
    if (mainTree == NULL){
        return;
    }
    else{
        seeMainTree(mainTree->left);
        cout<<mainTree->mainterm<<" ";
        seeMainTree(mainTree->pages);
        seeMainTree(mainTree->subterms);


        seeMainTree(mainTree->right);
    }
}


