//A collaboration between Abhinav Allam and Apar Mistry
#include "Heap.h"
#include <iostream>
#include <algorithm>
using namespace std;

Heap::Heap() {
	numItems = 0;
}


void Heap::dequeue(){
	if(numItems > 0){
		if(numItems != 1){
			arr[0] = arr[numItems -1];
		}
		numItems--;
		trickleDown(0);
	}
}



void Heap::trickleDown(int index){
	  if (numItems < index * 2 + 2) // No children (base case)
    {
        return;
    }
    else if (numItems == index * 2 + 2) // 1 child (base case)
    {
        if (arr[index]->getPriority() < arr[numItems - 1]->getPriority())
        {
            swap(index, numItems - 1);
        }
    }
    else // 2 children (do recursion)
    {
        PrintJob* leftChild = arr[index * 2 + 1];
        PrintJob* rightChild = arr[index * 2 + 2];

        if (leftChild->getPriority() > rightChild->getPriority())
        {
            // Left child is greater, compare it to index
            if (arr[index]->getPriority() < arr[index * 2 + 1]->getPriority())
            {
                swap(index, index * 2 + 1);
            }

            trickleDown(index * 2 + 1);
        }
        else
        {
            // Right child is greater, compare it to index
            if (arr[index]->getPriority() < arr[index * 2 + 2]->getPriority())
            {
                swap(index, index * 2 + 2);
            }

            trickleDown(index * 2 + 2);
        }
    }
}

void Heap::swap(int first, int second){
	PrintJob* temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}