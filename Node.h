
//a collaboration between abhinav and apar

#ifndef AVLTREE_NODE_H
#define AVLTREE_NODE_H
#include <string>

using namespace std;

class Node
{
    public:
        Node(string);
        string data;
		Node* left;
		Node* right;
		Node* parent;
        int count;
        int height;

};
#endif //AVLTREE_NODE_H
