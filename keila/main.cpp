#include <iostream>
#include "Playlist.h"
#include <string>

using namespace std;

void printMenu(string title){
    cout << endl << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
}


int main(){
    Playlist list;
    
    string title;
    string id;
    string song;
    string artist;
    int length;
    int oldPos;
    int newPos;
    char choice;
    
    cout << "Enter playlist's title:";
    cout << endl;
    getline(cin, title);
    
    do
    {
        
        printMenu(title);
        cout << "Choose an option:";
        cin >> choice;
        if (choice == 'q') {
            cout << endl;
        }
        cin.ignore();
        
        if (choice == 'a'){
            cout << "\nADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> id;
            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, song);
            cout << "Enter artist's name:" << endl;
            getline(cin, artist);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;
            list.AddSong(id, song, artist, length);
        }
        
        else if (choice == 'd'){
            cout << "\nREMOVE SONG" << endl;
            cout << "Enter song's unique ID:";
            cout << endl;
            cin >> id;
            list.RemoveSong(id);
        }
        
        else if (choice == 'c'){
            cout << "\nCHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;
            list.ChangePosition(oldPos, newPos);
        }
        
        else if (choice == 's'){
            cout << "\nOUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" ;
            getline(cin, artist);
            cout << endl <<endl;
            list.SongsByArtist(artist);
        }
        
        else if (choice == 't'){
            cout << "\nOUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: "<< list.TotalTime() << " seconds" << endl;
        }
        
        else if (choice == 'o'){
            cout << endl << title << " - OUTPUT FULL PLAYLIST" << endl;
            list.PrintList();
        }
        
        else if (choice != 'q'){
            cout << "Invalid menu choice! Please try again." << endl;
        }
        
    } while (choice != 'q');
    
    return 0;
}
