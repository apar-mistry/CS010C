//
//  stack.h
//  
//
//  Created by Apar Mistry and Abhinav Allam on 1/22/21.
//

#ifndef stack_h
#define stack_h
#include <stdexcept>
using namespace std;

template<typename T>
class stack {
private:
    static const int MAX_SIZE = 20;
    T data[MAX_SIZE];
    int size;
public:
    stack() { //default constructor. Nothing in the stack
        size = 0;
    }

    void push(T val) {
        //This if is to make sure element added doesn't cause an overflow
        if (size == MAX_SIZE) throw overflow_error("Called push on full stack.");
        //since elements fill up size - 1 indeces add at size
        data[size] = val;
        size += 1;
    }


    bool empty() {
        return size == 0;
    }

    void pop() {
        if (!empty()) {
            size -= 1;
        } else {
            throw out_of_range("Called pop on empty stack.");
        }
    }

    T top() {
        if (!empty()) {
            return data[(unsigned)size - 1];
        } else {
            throw out_of_range("Called top on empty stack.");
        }
    }
};

#endif /* stack_h */
