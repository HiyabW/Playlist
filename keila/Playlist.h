#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_
#include <iostream>
using namespace std;




class PlaylistNode{
    
private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;
    
public:
    
    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode*);
    void SetNext(PlaylistNode*);
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();
    void PrintPlaylistNode();
};


class Playlist{
private:
    PlaylistNode* head;
    PlaylistNode* tail;
    
public:
    Playlist();
    void AddSong(string, string , string, int);
    void RemoveSong(string );
    bool ChangePosition(int, int);
    void SongsByArtist(string);
    int TotalTime();
    void PrintList();
    bool isEmpty();
    int size();
    
};
#endif


