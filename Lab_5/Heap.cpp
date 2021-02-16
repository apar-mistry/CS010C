//A collaboration between Abhinav Allam and Apar Mistry
#include "Heap.h"
#include <iostream>
#include <algorithm>
using namespace std;

Heap::Heap() {
	numItems = 0;
}

void Heap::enqueue( PrintJob* job){
	if(numItems != MAX_HEAP_SIZE){
		if(numItems == 0){
			arr[numItems] = job;
			numItems++;
		}
		else{
			int currIndex = numItems;
			//fixing heap aka bubble up 
            while (currIndex > 0 && arr[(currIndex - 1) / 2]->getPriority() < job->getPriority()) //making sure arr[currIndex -1/2] is a child of the job and lower in priority
            {
                arr[currIndex] = arr[(currIndex - 1) / 2]; //swapping what's at the end with it's own parent
                currIndex = (currIndex - 1) / 2; //update currIndex val to go up to the parent value and reiterate till either condition becomes false
            }
            arr[currIndex] = job; //whatever currIndex is led to caused by bubbling up is the correct spot for job
            numItems++; //updating count
		}
	}
}

void Heap::dequeue(){
	if(numItems == 0){//is empty so error
		cout << "Cannot dequeue an empty heap." << endl;
		return;
	}
	if(numItems > 0){
		if(numItems != 1){
			arr[0] = arr[numItems -1]; //promoting end of array to the root
		}
		numItems--;
		trickleDown(0);
	}
}


void Heap::print(){
	if(numItems == 0){
		cout << "Heap is empty." << endl;
	}
	
	else{
		cout <<"Priority: " << highest()->getPriority();
		cout << ", Job Number: " << highest()->getJobNumber();
        cout << ", Number of Pages: " << highest()->getPages() << endl; 
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
PrintJob* Heap::highest(){
	if(numItems == 0)return nullptr;
	
	return arr[0];
	
}
