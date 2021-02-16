//
//  IntList.h
//  
//
//  Created by Apar Mistry and Abhinav Allam on 1/12/21.
//

#ifndef IntList_h
#define IntList_h

#include <ostream>

using namespace std;
struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList{
private:
    IntNode* dummyHead;
    IntNode* dummyTail;
public:
    IntList();//default constructor - empty list with dummy values //done
    ~IntList();//Destructor abhi
    void pop_front();//abhi
    void push_front(int value);//done
    void push_back(int value);//done
    void pop_back();//abhi
    bool empty() const; //done
    friend ostream & operator<<(ostream &out, const IntList &rhs); //done
    void printReverse() const; //done
};

#endif /* IntList_h */
