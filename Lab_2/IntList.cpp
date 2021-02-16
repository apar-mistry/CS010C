//
//  IntList.cpp
//  
//
//  Created by Abhinav Allam and Apar Mistry on 1/12/21.
//

#include <stdio.h>
#include "IntList.h"
#include <ostream>
#include <iostream>
using namespace std;

IntList::IntList(){
    dummyHead = new IntNode(0);
    dummyTail = new IntNode(0);
    
    
    dummyHead-> next = dummyTail;
    dummyTail -> prev = dummyHead;
    
    
}


IntList::~IntList() {
    IntNode* looper = dummyHead;
    while(looper != dummyTail) {
        IntNode* delNode = looper;
        looper = looper->next;
        delete delNode;
    }
    delete looper;
        
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode* temp = dummyHead->next;
        dummyHead->next = temp->next;
        temp->next->prev = dummyHead;
        delete temp;
    }
}

void IntList::pop_back() {
    if (!empty()) {
        IntNode* temp = dummyTail->prev;
        dummyTail->prev = temp->prev;
        temp->prev->next = dummyTail;
        delete temp;
    }
}


void IntList::push_back(int value){
    IntNode* node = new IntNode(value);
    IntNode* dummytPrev = dummyTail -> prev;
    dummyTail -> prev = node;
    node -> next = dummyTail;
    dummytPrev -> next = node;
    node -> prev = dummytPrev;
}
void IntList::push_front(int value){
    IntNode* node = new IntNode(value);
    IntNode* dummyNext = dummyHead -> next;
    dummyHead-> next = node;
    dummyNext -> prev = node;
    node -> prev = dummyHead;
    node -> next = dummyNext;
    
}
bool IntList::empty() const{
    return dummyHead->next == dummyTail && dummyTail -> prev == dummyHead;
}
void IntList::printReverse() const{
    if(!empty()){
        IntNode* node = dummyTail -> prev;
        if(node->prev == dummyHead){ //if there's one node
            cout << node->data;
            return;
        }
        else{
            while(node != dummyHead){
                if(node -> prev == dummyHead){ //checking to see if it is the first node
                    cout << node->data;
                }
                else{
                    cout << node->data << " ";
                }
                node = node->prev;
            }
        }
    }
}
ostream & operator<<(ostream &out, const IntList &rhs){
    if(!rhs.empty()){
        IntNode* node = rhs.dummyHead -> next;
        while(node != rhs.dummyTail){
            if(node -> next == rhs.dummyTail){ //last element
                out << node -> data;
            }
            else{
                out << node->data << " ";
            }
            node = node->next;
        }
    }
    return out;
}

