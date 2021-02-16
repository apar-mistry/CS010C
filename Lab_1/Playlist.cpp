//A collaboration between Abhinav Allam, Naveen Joby, & Apar Mistry
#include <iostream>
#include <string>
#include "Playlist.h"
using namespace std;
//PlaylistNode class definitions
PlaylistNode::PlaylistNode()
{ //Default constructor
    UniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}
PlaylistNode::PlaylistNode(string ID, string name, string singer, int len)
{ //Parameterized constructor
    UniqueID = ID;
    songName = name;
    artistName = singer;
    songLength = len;
    nextNodePtr = nullptr;
}
void PlaylistNode::InsertAfter(PlaylistNode *nextNode)
{
    PlaylistNode *placeHolder = nextNodePtr;
    nextNodePtr = nextNode;
    nextNode->SetNext(placeHolder);
}
void PlaylistNode::SetNext(PlaylistNode *song)
{
    nextNodePtr = song;
}
int PlaylistNode::GetSongLength()
{
    return songLength;
}
string PlaylistNode::GetID()
{
    return UniqueID;
}
string PlaylistNode::GetSongName()
{
    return songName;
}
string PlaylistNode::GetArtistName()
{
    return artistName;
}
PlaylistNode *PlaylistNode::GetNext()
{
    return nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << GetID() << endl;
    cout << "Song Name: " << GetSongName() << endl;
    cout << "Artist Name: " << GetArtistName() << endl;
    cout << "Song Length (in seconds): " << GetSongLength() << endl;
}

//Playlist Class definitions
Playlist::Playlist()
{ //making the actual linked list for the playlist
    head = nullptr;
    tail = nullptr;
}
void Playlist::printPlaylist(string playlistName)
{
    
    cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;
    if (isEmpty())
    {
        cout << "Playlist is empty" << endl;
        cout << endl;
        return;
    }
    else{
    int pos = 1;
    PlaylistNode *node = head;
    while (node)
    {
        cout << pos << "." << endl;
        node->PrintPlaylistNode();
        cout << endl;

        pos++;
        node = node->GetNext();
    }
}
}
bool Playlist::isEmpty() const
{
    return !head;
}
void Playlist::printArtistSong(string name)
{
    int pos = 1;
    PlaylistNode *node = head;
    while (node != nullptr)
    {
        if (node->GetArtistName() == name)
        { //seeing if name matches the node's name
            cout << pos << "." << endl;
            node->PrintPlaylistNode();
            cout << endl;
        }
        pos++; //so the position can be updated
        node = node->GetNext();
    }
}
void Playlist::remove(string ID)
{
    if (isEmpty())
    {
        cout << "Playlist is empty, hence nothing can be removed." << endl;
        return;
    }
    else if (ID == head->GetID())
    { //for head
        string name = head->GetSongName();
        head = head->GetNext();
        cout << '\"' << name << '"' << " removed." << endl; //In order to get quotation marks in the output, stackoverflow was used
        return;
    }
    else
    {
        PlaylistNode *preNode = head;
        PlaylistNode *node = head->GetNext(); //already checked head, not efficient to check it again
        while (node != nullptr && node->GetID() != ID)
        { //to get the right node to delete
            preNode = node;
            node = node->GetNext();
        }
        if (node != nullptr)
        {                                      //a matching node was found
            string name = node->GetSongName(); //getting name for the print statement
            preNode->SetNext(node->GetNext());
            if (node->GetNext() == nullptr)
                tail = preNode;
            cout << '\"' << name << '"' << " removed." << endl; //In order to get quotation marks in the output, stackoverflow was used
            return;
        }
    }
}
void Playlist::playlistLength()
{
    int sum = 0;
    PlaylistNode *node = head;
    while (node)
    {
        sum += node->GetSongLength();
        node = node->GetNext();
    }
    cout << "Total time: " << sum << " seconds" << endl;
}

void Playlist::add_song(PlaylistNode *song)
{
    if (head == nullptr && tail == nullptr)
    { //if it's an empty playlist
        head = song;
        tail = song;
    }
    else
    {
        tail->SetNext(song);
        tail = song;
    }
}
//new version

void Playlist::changePosition(){
    int initIndex =1;
    int currPos = 0;
    int newPos = 0;

    cout << "Enter song's current position:" << endl;
    cin >> currPos;
    cout << "Enter new position for song:" << endl;
    cin >> newPos;

    PlaylistNode* prevNode = nullptr;
    PlaylistNode* currNode = head;
    if(currPos < 1){
        cout << "Invalid current position." << endl;
        return;
    }    

    while(initIndex < currPos){ //purpose of this loop is to find the node aka currNode that needs to be moved
        if(currNode != nullptr){
            prevNode = currNode;
            currNode = currNode->GetNext();
            initIndex++;
            if(currNode == nullptr){
                cout << "Invalid current position." << endl;
                return;
            }
        }
        else{
            cout << "Invalid current position." << endl;
            return;
        }
    }
    string songName = currNode->GetSongName();
    if(prevNode == nullptr){//means currNode is head
        head = currNode ->GetNext();
    }
    else prevNode->SetNext(currNode->GetNext());

    if(currNode->GetNext() == nullptr){ //means it's tail
        tail = prevNode;
    }

    if(newPos <= 1){ //The <= ensures any value below and including 1 automatically moves currNode to head 
        if(isEmpty() == true){
            tail = currNode;
        }

        currNode->SetNext(head); //taking the spot of head
        head = currNode; //setting head as currNode
        cout << '"' << songName << '"' << " moved to position 1" << endl;
    }
    else{ //if the value is being inserted at an index other than head
        initIndex = 2;
        PlaylistNode* prevNode1;
        PlaylistNode* postNode;
        prevNode1 = head;
        postNode = head->GetNext();

        while(initIndex < newPos && postNode != nullptr){//finding node that currNode is taking it's spot
            prevNode1 = postNode;
            postNode = postNode->GetNext();
            initIndex++;
        }
        

        //now starting inserting and adjusting process
        prevNode1->SetNext(currNode);
        currNode->SetNext(postNode);
        if(!postNode){//setting tail to be currNode
            tail = currNode;
        }
        cout << '"' << songName << '"' << " moved to position " << initIndex << endl;
    }
    

}


// void Playlist::changePosition() 
// {
//     int currPos = 0;
//     int newPos = 0;
//     cout << "Enter song's current position: " << endl;
//     cin >> currPos;
//     cout << "Enter new position for song: " << endl;
//     cin >> newPos;

//     if (currPos == newPos || currPos < 1)
//     {
//         return;
//     }

//     int length = 0;
//     PlaylistNode *curr = head;
//     while (curr != nullptr)
//     {
//         length++;
//         curr = curr->GetNext();
//     }
//     cout << "Length: " << length << endl;
//     int currIndex = 1;

//     if (newPos <= 1) //below minimum number
//     {
//         curr = head;
//         while (curr != nullptr)
//         {
//             cout << "less than 1 pre curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//             if (currIndex == currPos) //finding the original position of the songs current position.
//             {
//                 string currID = curr->GetID();
//                 PlaylistNode *temp = curr;
//                 cout << "less than 1 found curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//                 remove(currID);
//                 PlaylistNode *temp2 = head;
//                 head = temp;
//                 head->SetNext(temp2);
//                 break;
//             }
//             else //continues if not current position till the current position is found.
//             {
//                 curr = curr->GetNext();
//                 currIndex++;
//             }
//         }
//     }
//     else if (newPos > 1 && newPos < length) //default case(any normal number)
//     {
//         curr = head;
//         while (curr != nullptr)
//         {
//             cout << "less than 1 pre curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//             if (currIndex == currPos) //finding the original position of the songs current position.
//             {
//                 string currID = curr->GetID();
//                 PlaylistNode *temp = curr;
//                 cout << "less than 1 found curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//                 remove(currID);
//                 PlaylistNode *temp2 = head;
//                 head = temp;
//                 head->SetNext(temp2);
//                 break;
//             }
//             else //continues if not current position till the current position is found.
//             {
//                 curr = curr->GetNext();
//                 currIndex++;
//             }
//         }
//     }
//     else // this should be for cases that are above length(n)
//     {
//         // tail->next should be set to the new  node that is there
//         curr = head;
//         while (curr != nullptr)
//         {
//             cout << "greater than length case pre curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//             if (currIndex == currPos) //checking if the current song is found
//             {
//                 string currID = curr->GetID();
//                 PlaylistNode *temp = curr;
//                 cout << "greater than length found curr index: CurrentPos" << currPos << " : CurrIndex " << currIndex << endl;
//                 remove(currID);
//                 PlaylistNode *temp2 = tail;
//                 tail = temp;
//                 temp2->SetNext(temp);
//                 temp->SetNext(nullptr);

//                 break;
//             }
//             else //continuing if not found
//             {
//                 curr = curr->GetNext();
//                 currIndex++;
//             }
//         }
//     }
// }