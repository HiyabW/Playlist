# Playlist Program C++
This repository contains an Xcode project and its files for the Playlist Program C++, a program that creates a playlist and includes several customization operations to organize and customize to the user’s liking through the usage of data structures

Traversing through a linked list, the program accomplishes is capable of performing the following tasks:<br/>

Option (a): Adding a song<br/>
Option (d): Removing a song<br/>
Option (c): Changing position of a song<br/>
Option (s): Output songs by specific artist<br/>
Option (t): Output total time of playlist in seconds<br/>
Option (o): Output full playlist<br/>
Option (q): Quit<br/>

## Playlist.h
The PlaylistNode class and Playlist class are contained in this file. Playlist.h contains all of the project's function declarations

The following functions are needed for the project to function accordingly:

### For the PlaylistNode class...
    PlaylistNode()
    PlaylistNode(string, string, string, int)
    void InsertAfter(PlaylistNode*)
    void SetNext(PlaylistNode*)
    string GetID()
    string GetSongName()
    string GetArtistName()
    int GetSongLength()
    PlaylistNode* GetNext()
    void PrintPlaylistNode()


### For the Playlist class...
    Playlist()
    void AddSong(string, string , string, int)
    void RemoveSong(string )
    bool ChangePosition(int, int)
    void SongsByArtist(string)
    int TotalTime()
    void PrintList()
    bool isEmpty()
    int size()
    
## Playlist.cpp
Contains all of the project's function definitions so the functions operate appropriately

## Main.cpp
Contains the main program users will interact with. Prints the menu and loops until q (quit) is entered.
