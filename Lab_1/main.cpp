
//A collaboration between Abhinav Allam, Naveen Joby, & Apar Mistry
#include <iostream>
#include <string>
#include "Playlist.h"
using namespace std;
Playlist* pList;

void menu(string title){
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl; 
    cout << endl;
    cout << "Choose an option:";
    cout << endl;

    string choice;

	

	getline(cin, choice);
    
    	if(choice == "q") return;
    else if(choice == "o"){
        pList->printPlaylist(title);
        menu(title);
    }
    else if(choice == "a"){
        cout << "ADD SONG" << endl;
        string id;
        string name;
        string artist;
        int length;

        cout << "Enter song's unique ID:" << endl;
        getline(cin, id);
        cout << "Enter song's name:" << endl;
        getline(cin, name);
        cout << "Enter artist's name:" << endl;
        getline(cin, artist);
        cout << "Enter song's length (in seconds):" << endl;
        cin >> length;
        cin.ignore();

        PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
        pList->add_song(newNode);
        cout << endl;
        
        menu(title);
    }
    else if(choice == "c"){
        cout << "CHANGE POSITION OF SONG" << endl;
		pList->changePosition();
        cout << endl;
        cin.ignore();
		menu(title);
    }
    else if (choice == "t") {
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        pList->playlistLength();
        cout << endl;
        menu(title);
    }
    else if (choice == "s") // Output songs by specific artist
    {
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        string artist;
        getline(cin, artist);
        cout << endl;
        pList->printArtistSong(artist);
        menu(title);
    }
     else if (choice == "d") // Remove song
    {
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        string id;
        getline(cin, id);
        pList->remove(id);
        cout << endl;
        
        menu(title);
    }
    else{
        menu(title);
    }


}
int main(){
    
    string name;
    cout << "Enter playlist's title:" << endl;
    getline(cin, name); //needed a refresh on getline so I referenced geeksforgeeks
    cout << endl;
    pList = new Playlist();
    menu(name);
    return -1;
}

// 	PlaylistNode *addedNode; //variable option a
// 	string tempID; //variable option a and option d
// 	string sName;  //variable option a 
// 	string aName;  //variable option a
// 	int sLength;   //variable option a
// 	string artName; //variable option s


// switch(choice[0]) {
// 		cout << endl;
// 	case 'a':
// 		cin.ignore();
//         cout << "ADD SONG" << endl;
// 		cout << "Enter song's unique ID:" << endl;
// 		cin >> tempID;
// 		cout << "Enter song's name:" << endl;
// 		getline(cin, sName);
// 		cout << "Enter artist's name:" << endl;
// 		getline(cin, aName);
// 		cout << "Enter song's length (in seconds):" << endl;
// 		cin >> sLength;
// 		addedNode = new PlaylistNode(tempID, sName, aName, sLength);
// 		cout << "add success" << endl;
// 		pList->add_song(addedNode);
// 		menu(title);
// 	case 'd':

// 		cout << "REMOVE SONG" << endl;
// 		cout << "Enter song's unique ID:" << endl;
// 		cin >> tempID;
// 		cin.ignore();
// 		cout << "delete success" << endl;
// 		pList->remove(tempID);
// 		menu(title);
// 	case 'c':

// 		cout << "CHANGE POSITION OF SONG" << endl;
// 		cin.ignore();
// 		cout << "change success" << endl;
// 		pList->changePosition();
// 		menu(title);
// 	case 's':
// 		cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
// 		cout << "Enter artist's name:" << endl;
// 		getline(cin, artName);
// 		cin.ignore();
// 		cout << "songs by artist success" << endl;
// 		pList->printArtistSong(artName);
// 	case 't':
// 		cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
// 		cout << "timeOutput success" << endl;
// 		pList->playlistLength();
// 		menu(title);
// 	case 'o':
// 		cin.ignore();
//         cout << title << " - OUTPUT FULL PLAYLIST" << endl;
// 		cout << "fullPlaylist success" << endl;
// 		pList->printPlaylist(title);
// 		menu(title);
// 	case 'q':
// 	default:
// 		exit(1);
// 	}
