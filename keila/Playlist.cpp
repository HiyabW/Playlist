//collaborated with hiyab woldegebriel
#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;

PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string id, string name, string artist, int length) {
    uniqueID = id;
    songName = name;
    artistName = artist;
    songLength = length;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr){
    nextNodePtr = nodePtr;
}

PlaylistNode* PlaylistNode::GetNext(){
    return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){
    nodePtr->SetNext(this->GetNext());
    this->SetNext(nodePtr);
}

string PlaylistNode::GetID(){
    return uniqueID;
}

string PlaylistNode::GetSongName(){
    return songName;
}

string PlaylistNode::GetArtistName(){
    return artistName;
}

int PlaylistNode::GetSongLength(){
    return songLength;
}

void PlaylistNode::PrintPlaylistNode(){
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength;
}





Playlist::Playlist(){
    head = 0;
    tail = 0;
}

void Playlist::AddSong(string id, string song, string artist, int length) {
    PlaylistNode* newNode = new PlaylistNode(id, song, artist, length);
    if (head == 0) {
        head = newNode;
        tail = newNode;
    }
    
    else {
        tail->InsertAfter(newNode);
        tail = newNode;
    }
}


void Playlist::RemoveSong(string id){
    PlaylistNode* curr = head;
    PlaylistNode* prev = 0;
    
    PlaylistNode* temp = curr;
    
    if (head == 0) {
        cout << "Playlist is empty" << endl << endl;
        return;
    }
    
    if (head == tail) {
        if (curr->GetID() == id) {
            delete head;
            head = 0;
            tail = 0;
            cout << "\"" << curr->GetSongName() << "\" removed." << endl << endl;
            return;
        }
        //maybe need an else
    }
    
    if (head->GetID() == id) {
        head = head->GetNext();
        delete temp;
        cout << "\"" << curr->GetSongName() << "\" removed." << endl << endl;
        return;
    }
    
    prev = head;
    curr = head->GetNext();
    while (curr != 0) {
        
        if (curr->GetID() == id) {
            
            if (curr == tail) {
                tail = prev;
                delete curr;
                cout << "\"" << curr->GetSongName() << "\" removed." << endl;
                return;
            }
            
            else {
                prev->SetNext(curr->GetNext());
                delete curr;
                cout << "\"" << curr->GetSongName() << "\" removed." << endl;
                return;
                
            }
        }
        
        prev = curr;
        curr = curr->GetNext();
        
    }
}

int Playlist::size() {
    PlaylistNode* temp;
    int i = 0;
    
    for (temp = head; temp != 0; temp = temp->GetNext()) {
        i++;
    }
    
    return i;
}

bool Playlist::ChangePosition(int oldPos, int newPos) {
    
    int length = 0;
    
    if (head == NULL)
    {
        cout << "Playlist is empty" << endl << endl;
        return false;
    }
    
    if(newPos < 1)
    {
        newPos = 1;
    }
    
    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;
    
    while(curr != nullptr)
    {
        length++;
        curr = curr->GetNext();
    }
    curr = head;
    
    if(newPos > length)
    {
        newPos = length;
    }
    
    int pos;
    if (head == tail)
    {
        cout << "Only one song" << endl;
        return false;
    }
    
    for (pos = 1; curr != NULL && pos < oldPos; pos++)
    {
        prev = curr;
        curr = curr->GetNext();
    }
    if (curr != NULL)
    {
        string currentSong = curr->GetSongName();
        
        
        if (prev == NULL){
            head = curr->GetNext();
        }
        else
        {
            prev->SetNext(curr->GetNext());
        }
        
        if (curr == tail) {
            tail = prev;
        }
        
        PlaylistNode* curr1 = curr;
        prev = NULL;
        curr = head;
        
        for (pos = 1; curr != NULL && pos < newPos; pos++)
        {
            prev = curr;
            curr = curr->GetNext();
        }
        
        
        if (prev == NULL)
        {
            curr1->SetNext(head);
            head = curr1;
        }
        else{
            prev->InsertAfter(curr1);
        }
        
        if (curr == NULL)
        {
            tail = curr1;
        }
        
        
        cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
        return true;
        
    }
    else
    {
        cout << "Song's current position is invalid" << endl << endl;
        return false;
    }
//
//    if (head == 0 || head == tail) {
//        return;
//    }
//
//    if (newPos < 1) {
//        newPos = 1;
//    }
//
//    if (newPos > this->size()) {
//        newPos = this->size();
//    }
//
//    PlaylistNode* temp;
//    PlaylistNode* prev;
//
//
//    int i = 1;
//
//
//    for (temp = head; temp != 0; temp = temp->GetNext()) {
//
//        if (i == oldPos) {
//
//            if (temp == head) {
//                head = head->GetNext();
//            }
//
//            else if (temp == tail) {
//                prev->SetNext(0);
//                tail = prev;
//            }
//
//            else {
//                prev->SetNext(temp->GetNext());
//            }
//
//            break;
//        }
//        prev = temp;
//        temp = temp->GetNext();
//    }
//
//    if (oldPos < newPos) {
//        newPos--;
//    }
//
//    for (temp = head; temp != 0; temp = temp->GetNext()) {
//
//    }
    
    
}


void Playlist::SongsByArtist(string artist) {
    if (head == NULL){
        cout << "Playlist is empty" << endl << endl;
    }
    else{
        PlaylistNode* curr = head;
        int i = 1;
        while (curr->GetNext() != NULL){
            if (curr->GetArtistName() == artist){
                cout << i << "." << endl;
                curr->PrintPlaylistNode();
                cout << endl << endl;
            }
            curr = curr->GetNext();
            i++;
        }
        if(curr->GetArtistName() == artist){
        cout << i << "." << endl;
        curr->PrintPlaylistNode();
            
        }
        
    }
    

}
int Playlist::TotalTime() {
    int total = 0;
    PlaylistNode* curr = head;
    
    while (curr != NULL)
    {
        total += curr->GetSongLength();
        curr = curr->GetNext();
    }
    
    return total;
}
void Playlist::PrintList() {
    if (head == 0) {
        cout << "Playlist is empty" << endl;
    }
    
    else {
        PlaylistNode* curr = head;
        int i = 1;
        while (curr->GetNext() != 0)
        {
            cout << i++ << "." << endl;
            curr->PrintPlaylistNode();
            curr = curr->GetNext();
            cout << endl << endl;
        }
        cout << i++ << "." << endl;
        curr->PrintPlaylistNode();
        cout << endl;
    }
    
}

bool Playlist::isEmpty() {
    if (head == 0) {
        return false;
    }
    return true;
}
