//a collaboration between abhinav and apar


#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class AVLTree {
    private:
        Node *root;
    private:
        void rotate(Node* );
        Node* rotateLeft(Node* );
        Node* rotateRight(Node* );
        void printBalanceFactors(Node *);
        void visualizeTree(ofstream &, Node *);
        int height(Node*) const;
        Node* findUnbalancedNode(Node* );
    
    public:
        AVLTree();
        void insert(const string & );
        int balanceFactor(Node* );
        void printBalanceFactors();
        void visualizeTree(const string &);
        Node *InSearch(const string &, Node*) const;
};
    
