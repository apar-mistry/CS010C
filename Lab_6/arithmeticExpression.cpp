// A collaboration between Abhinav Allam and Apar Mistry
#include "arithmeticExpression.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

using namespace std;


//public member functions
arithmeticExpression::arithmeticExpression(const string &exprParam){
    root = 0;
    infixExpression = exprParam;
}

void arithmeticExpression::buildTree(){ //to do 
    infixExpression = infix_to_postfix();
    stack <TreeNode*> s;
    
    for(unsigned i = 0; i < infixExpression.length(); i++){ //goes through the length of the expression
        TreeNode* node = new TreeNode(infixExpression.at(i), 'a' + i);
        if(priority(infixExpression.at(i)) == 0){//means its not an operator 
            s.push(node); //push onto the stack
        }
        else{ //means its an operator
            node -> right = s.top(); //second val is right
            s.pop();
            node -> left = s.top(); //first val is left
            s.pop();
            s.push(node); //push the operator
            
        }
    }
    root = s.top();
}

void arithmeticExpression::infix(){
    infix(root);
}

void arithmeticExpression::postfix(){
    postfix(root);
}

void:: arithmeticExpression::prefix(){
    prefix(root);
}

void arithmeticExpression::visualizeTree(const string &outputFilename){
    ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}



//private functions
int arithmeticExpression::priority(char op){
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}

string arithmeticExpression::infix_to_postfix(){
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}

void arithmeticExpression::infix(TreeNode *node){
     if (node != 0)
    {
        if (node->left != 0)
        {
            cout << '(';
        }

        infix(node->left);
        cout << node->data;
        infix(node->right);

        if (node->left != 0)
        {
            cout << ')';
        }
    }

}

void arithmeticExpression::postfix(TreeNode *node){
	if (node == 0) {
		return;
	}

	postfix(node->left);
	postfix(node->right);
	cout << node->data;
}


void arithmeticExpression::prefix(TreeNode *node){
    if (node == 0) {
		return;
	}
	cout << node->data;
	prefix(node->left);
	prefix(node->right);
}

void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *node){ //to do 
    if(node != nullptr ){
        if(node -> left != nullptr){
            out << node->key << " [ label = " << "\"" << node->data << "\"" << "];" << endl;
			out << node->left->key << " [ label = " << "\"" << node->left->data << "\"" << "];" << endl;
			out << node->key << " -> " << node->left->key << endl;
            if(node->right!= nullptr){
                out << node -> right ->key << " [ label = " << "\"" << node->right -> data << "\"" << "];" << endl;
                out << node->key << " -> " << node -> right ->key << endl;
                visualizeTree(out, node->left);
                visualizeTree(out, node->right);
            }
            else visualizeTree(out, node->left);
        }
        else{
            if(node->right != nullptr){
                out << node->key << " [ label = " << "\"" << node->data << "\"" << "];" << endl;
			    out << node->right->key << " [ label = " << "\"" << node->right->data << "\"" << "];" << endl;
			    out << node->key << " -> " << node->right->key << endl;
                visualizeTree(out, node->right);
            }
        }
    }
}