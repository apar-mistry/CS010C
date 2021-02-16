
//A collaboration between Abhinav Allam & Apar Mistry
//I Abhinav Allam, utilized cppreference.com for the Vector class
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;


template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned val = index;
    for(unsigned int i = index+1; i < vals.size(); ++i){
        if(vals.at(i) < vals.at(val)) val = i;
    }
    return val;
}


template <typename T>
void selection_sort(vector<T> &vals){ //referenced zybooks for algorithm to come up with this function
    for(unsigned i = 0; i + 1 < vals.size(); ++i){
        unsigned minValInd = min_index(vals, i);
        T swapVal = vals.at(i);
        vals.at(i) = vals.at(minValInd);
        vals.at(minValInd) = swapVal;
    }
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template <typename T>
T getElement(vector<T> vals, int index) { //Created function usng cplusplus.com (http::www.cplusplus.com/doc/tutorial/exceptions/)
    if(index < 0 || (unsigned)index  > vals.size()) {
        throw out_of_range("out of range exception occured");
    }
    return vals.at(index);
}


int main(){
    int case1;
    cout << "Which case are we testing?" << endl;
    cin >> case1;
    if(case1 == 1){    
        
        //Part B
        srand(time(0));
        vector<char> vals = createVector();
        char curChar;
        int index;
        int numOfRuns = 10;
        while(--numOfRuns >= 0){
            cout << "Enter a number: " << endl;
            cin >> index;
            try{
                curChar = getElement(vals,index);
                cout << "Element located at " << index << ": is " << curChar << endl;
            } catch (out_of_range& errorout) {
                cout << errorout.what() << endl; //referenced cplusplus.com for .what()
            }
        }
        return 0;
        } 
    else if(case1 == 2){
        //Part C       (https://cal-linux.com/tutorials/vectors.html)
        vector<int> vals_1;
        vector<string> vals_2;
        vector <double> vals_3;
        
        vals_1.push_back(0);
        vals_1.push_back(5);
        vals_1.push_back(-3);
        vals_1.push_back(2);
        vals_1.push_back(9);
        cout << "Original Int vector: " << endl;
         for(unsigned i = 0;  i < vals_1.size(); i++) {
            cout << vals_1.at(i) << endl;
        }
        cout << endl;
        selection_sort(vals_1);
        cout << "Integer sort completed" << endl;
        cout << "New vector: " << endl;
        for(unsigned j = 0;  j < vals_1.size(); j++) {
            cout << vals_1.at(j) << endl;
        }
        cout << endl;
        //bot the original and sorted integer vector should be printed at this point. Heading to the string vector.

        vals_2.push_back("apar");
        vals_2.push_back("abhinav");
        vals_2.push_back("testing");
        vals_2.push_back("functions");
        vals_2.push_back("selection");
        
        cout << "Testing on vector of strings" << endl;
        cout << "Original vector:" << endl;
        for (unsigned i = 0; i < vals_2.size(); i++)
        {
            cout << vals_2.at(i) << endl;
        }
        cout << endl;
        cout << "Now doing selection sort: " << endl;
        selection_sort(vals_2);
        for (unsigned i = 0; i < vals_2.size(); i++)
        {
            cout << vals_2.at(i) << endl;
        }
        cout << endl;
        
        vals_3.push_back(-2.9);
        vals_3.push_back(.5);
        vals_3.push_back(8.9);
        vals_3.push_back(6.58);
        vals_3.push_back(-55.7);
        cout << "Testing on vector of doubles" << endl;
        cout << "Original vector:" << endl;
        for (unsigned i = 0; i < vals_3.size(); i++)
        {
            cout << vals_3.at(i) << endl;
        }
        cout << endl;
        cout << "Now doing selection sort: " << endl;
        selection_sort(vals_3);
        for (unsigned i = 0; i < vals_3.size(); i++)
        {
            cout << vals_3.at(i) << endl;
        }
        cout << endl;
    } 
}
