//a collaboration between abhinav and apar

#include"AVLTree.h"
#include"Node.h"
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
 
AVLTree::AVLTree() : root(0) {}
 
void AVLTree::insert(const string &val) {
    if (root == 0) { //if empty AVL tree
        root = new Node(val);
        return;
    }
   
    Node* valParent = InSearch(val, root); //search for node with val within tree
    Node* child = new Node(val); //new 
    child->parent = valParent; //parent of child is the one right above it
   
    if (val < valParent->data) { //if less than parent, set parent's child to be node
        valParent->left = child;
    }
    else if (val > valParent->data) { // greater than val
        valParent->right = child;
    }
    else {
        return;
    }
   
    Node* temp = findUnbalancedNode(child); //seeing if child is an unbalanced node
     if (temp) { //if unbalanced
        rotate(temp); //do the rotation
    }
}
 
Node* AVLTree::InSearch(const string &val, Node* node) const {
    if (node->data == val) { //if we find a match
        return node;
    }
    if (val < node->data) { //to the left of current node
        if (node->left) { //if there is a left node
            return InSearch(val, node->left);
        }
        else { //otherwise parent found
            return node;
        }
    }
    else {
        if (node->right) { //if there is a child to the right
            return InSearch(val, node->right);
        }
        return node; //parent found
    }
}
 
int AVLTree::balanceFactor(Node* node) {
    if (node == 0) {
        return 0;
    }
    return height(node->left) - height(node->right);
}
 
void AVLTree::printBalanceFactors() {
    printBalanceFactors(root);
    cout << endl;
}
 
void AVLTree::printBalanceFactors(Node* node) {
    if(node) {
        printBalanceFactors(node->left);
        cout << node->data << "(" << balanceFactor(node) << "), ";
        printBalanceFactors(node->right);
    }
}
 
void AVLTree::visualizeTree(const string &outputFilename) {
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tpng " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());      
}
 
 
void AVLTree::visualizeTree(ofstream &outFS, Node *n) {
    if(n){
        if(n->left){
            visualizeTree(outFS,n->left);
            outFS << n->data << " -> " << n->left->data <<";"<< endl;    
        }
 
        if(n->right){
            visualizeTree(outFS,n->right);
            outFS << n->data << " -> " << n->right->data <<";"<< endl;    
        }
    }
}
 
int AVLTree::height(Node* node) const {
    if (node == 0) {
        return -1;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    else {
        return rightHeight + 1;
    }
}
 
Node* AVLTree::findUnbalancedNode(Node* node) {
    if (node == 0) {
        return 0;
    }
   
    int bFactor = balanceFactor(node);
    if (bFactor == -2 || bFactor == 2) { //if unbalanced aka not -1 , 1 or 0
        return node;
    }
    else {
        return findUnbalancedNode(node->parent); // go back and find parent
    }
}
 
Node* AVLTree::rotateRight(Node* node) {
    Node* leftRightChild = node->left->right; //node's left child's right child
    if(node->parent != NULL) { //if parent of node is not null
        if(node->parent->left == node) { //bingo!!
            node->parent->left = node->left; //switch with lesser value 
            if(node->left != NULL) { 
                node->left->parent = node->parent; //let left child's parent  be the parent of the node
            }
        }
        else if(node->parent->right == node) { //if right child of node = node
            node->parent->right = node->left; //node's left child is the right child of node's parent
            if(node->left != NULL) { //if left has  child
                node->left->parent = node->parent; // parent of left is the parent of the node
            }
        }
    }
    else {
        root = node->left;
        root->parent = NULL;
    }
    node->left->right = node;
    if(node != NULL) {
        node->parent = node->left;
    }
    node->left = leftRightChild;
    if(leftRightChild != NULL) {
        leftRightChild->parent = node;
    }
    return node->parent;
}
 
Node* AVLTree::rotateLeft(Node* node) {
    Node* rightLeftChild = node->right->left;
    if (node->parent != 0) {
        if (node->parent->right == node) {
            node->parent->right = node->right;
            if (node->right != 0) {
                node->right->parent = node->parent;
            }
        }
        else if (node->parent->left == node) {
            node->parent->left = node->right;
            if (node->right != 0) {
                node->right->parent = node->parent;
            }
        }
    }
    else {
        root = node->right;
        root->parent = 0;
    }
   
    node->right->left = node;
    if (node != 0) {
        node->parent = node->right;
    }
    node->right = rightLeftChild;
    if (rightLeftChild) {
        rightLeftChild->parent = node;
    }
    return node->parent;
}
 
void AVLTree::rotate(Node* node) {
    int bFactor = balanceFactor(node);
    int childBFactor1 = balanceFactor(node->left);
    int childBFactor2 = balanceFactor(node->right);
    if (bFactor == 2) { //if node is unbalanced
        if (childBFactor1 == 1 || childBFactor2 == 1) { //if one child node is balanced
            rotateRight(node); //rotate right
        }
        else {
            rotateLeft(node->left); //rotate left otherwise the left child of the node
            rotateRight(node); //then rotate right everything
        }
    }
    else {
        if (childBFactor1 == -1 || childBFactor2 == -1) { //if bfactor isn't 2  but childs' bfactor = -1
            rotateLeft(node); //rotate leftwise
        }
        else {
            rotateRight(node->right); //rotate right the right child's nodes
            rotateLeft(node); //rotate left
        }
    }
}