# Playlist Program C++
This repository contains an Xcode project and its files for the Playlist Program C++, a program that creates a playlist and includes several customization operations to organize and customize to the user’s liking through the usage of data structures

Traversing through a linked list, the program accomplishes is capable of performing the following tasks:

Option (a): Adding a song
Option (d): Removing a song
Option (c): Changing position of a song
Option (s): Output songs by specific artist
Option (t): Output total time of playlist in seconds
Option (o): Output full playlist
Option (q): Quit

## Playlist.h
The PlaylistNode class and Playlist class are contained in this file. Playlist.h contains all of the project's function declarations

The following functions are needed for the project to function accordingly:

### For the PlaylistNode class...<br/>
    PlaylistNode()<br/>
    PlaylistNode(string, string, string, int)<br/>
    void InsertAfter(PlaylistNode*)<br/>
    void SetNext(PlaylistNode*)<br/>
    string GetID()<br/>
    string GetSongName()<br/>
    string GetArtistName()<br/>
    int GetSongLength()<br/>
    PlaylistNode* GetNext()<br/>
    void PrintPlaylistNode()<br/>


### For the Playlist class...<br/>
    Playlist()<br/>
    void AddSong(string, string , string, int)<br/>
    void RemoveSong(string )<br/>
    bool ChangePosition(int, int)<br/>
    void SongsByArtist(string)<br/>
    int TotalTime()<br/>
    void PrintList()<br/>
    bool isEmpty()<br/>
    int size()<br/>
    
## Playlist.cpp
Contains all of the project's function definitions

## Main.cpp
Contains the main program users will interact with. Prints the menu and loops until q (quit) is entered.
