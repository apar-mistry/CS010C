//A collaboration between Abhinav Allam and Apar Mistry
#include "WordLadder.h"

#include <fstream>
#include <iostream>
#include <queue>
#include <string>
using namespace std;


//private member functions----------
bool WordLadder::inList(const string &str){
    for(list<string>::iterator x = dict.begin(); x != dict.end(); x++){
        if(str == *x){ //checks if what string the iterator is on is equal to the parameter
            return true;
        }
    }
    return false;
}

bool WordLadder::oneLetterOff(const string &s1, const string &s2){
    int diffCount = 0;
    for(unsigned i = 0; i < 5; ++i){
        if(s1[i] != s2[i]){ //treat words as array of chars and then compare each character
            diffCount++;
        }
    }
    return diffCount == 1;
}

void WordLadder::outputNoLadder(const string &outputFile)
{
    ofstream outFS(outputFile);

    if (!outFS.is_open())
    {
        cout << "Error opening output file " << outputFile << endl;
        return;
    }

    outFS << "No Word Ladder Found." << endl;
    outFS.close();
}

void WordLadder::outputLadder(const string &outputFile, stack<string> ladder)
{
    ofstream outFS(outputFile);

    if (!outFS.is_open())
    {
        cout << "Error opening output file " << outputFile << endl;
        return;
    }

    stack<string> reverse = stack<string>();
    while (!ladder.empty())
    {
        reverse.push(ladder.top());
        ladder.pop();
    }

    while (!reverse.empty())
    {
        outFS << reverse.top() << endl;
        reverse.pop();
    }

    outFS.close();
    return;
}


//public member functions-----------

WordLadder::WordLadder(const string &fileName){
    ifstream inFS;
    inFS.open(fileName);
    if (!inFS.is_open()) //if file doesn't open properly
    {
        cout << "Error found while opening " << fileName << "." << endl;
        return;
    }
    dict = list<string>();
    string dictEntry;
    while(getline(inFS, dictEntry)){ //starts reading file
        if(!dictEntry.empty()){
            if(dictEntry.length() != 5){
                cout << "Error, dictionary entry "<< dictEntry<< " must have 5 letters" << endl;
                return;
            }
            dict.push_back(dictEntry);
        }   
    }
    inFS.close();
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile)
{

    if (start == end)
    {
        stack<string> oneWordStack = stack<string>();
        oneWordStack.push(start);
        outputLadder(outputFile, oneWordStack);
        return;
    }

    
    if (!inList(start)|| !inList(end))
    {
        // Starting word not in dictionary
        cout << "The words are not in the dictionary." << endl;
        return;
    }


    stack<string> initStack = stack<string>();
    initStack.push(start);

    queue<stack<string> > wordQueue = queue<stack<string> >();
    wordQueue.push(initStack);

    while (!wordQueue.empty())
    {
        stack<string> currStack = wordQueue.front();
        string topWord = currStack.top();
        list<string>::iterator it = dict.begin();
        while (it != dict.end())
        {
            string str = *it;
            
            if (oneLetterOff(str, topWord)) //if str is a viable candidate for ladder
            {
                // Copy currStack and put word
                stack<string> newLadder = stack<string>(currStack);
                newLadder.push(str);
                wordQueue.push(newLadder);

                // Remove word from dictionary
                it = dict.erase(it);

                if (str == end)
                {
                    outputLadder(outputFile, newLadder); //end game!!!
                    return;
                }
            }
            else //onto the next
            {
                it++;
            }
        }

        wordQueue.pop(); //pop the old
    }
    // Did not find a ladder
    outputNoLadder(outputFile);
}


