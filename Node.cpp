//
//a collaboration between abhinav and apar
//

#include "Node.h"

Node::Node(string str){
    data = str;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
    count = 0;
    height = 0;
};

