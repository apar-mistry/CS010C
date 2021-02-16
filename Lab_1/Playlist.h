//A collaboration between Abhinav Allam, Naveen Joby, & Apar Mistry

#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;
class PlaylistNode{
    private:
        string UniqueID;
		string songName;
		string artistName;
		int songLength;
		PlaylistNode *nextNodePtr;

	public:
		PlaylistNode(); 
        PlaylistNode(string ID, string name, string singer, int len);
        void InsertAfter(PlaylistNode*);
        void SetNext(PlaylistNode*);
		int GetSongLength();
        string GetID();
		string GetSongName();
		string GetArtistName();
		PlaylistNode* GetNext();
        void PrintPlaylistNode();
};

class Playlist {
    private:
        PlaylistNode* head;
        PlaylistNode* tail;
	public:
        Playlist();
        void printPlaylist(string playlistName); //done
        bool isEmpty() const;//done
        void printArtistSong(string name);//done
        void remove(string ID);//done
        void playlistLength();//done
		void changePosition();
        void add_song(PlaylistNode* song);//done
};

#endif

