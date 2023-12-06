#include "PlaylistNode.h"

PlaylistNode::PlaylistNode(){ //define PlaylistNode() constructor 
   
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodePtr = nullptr;
   
}

PlaylistNode::PlaylistNode(string userID, string song, string artist, int length){ //define PlaylistNode() constructor 
   
   uniqueID = userID;
   songName = song;
   artistName = artist;
   songLength = length;
   nextNodePtr = nullptr;
   
   
}

string PlaylistNode::GetID(){ //define GetID()
   return uniqueID;
}

string PlaylistNode::GetSongName(){ //define GetSongName()
   return songName;
}

string PlaylistNode::GetArtistName(){ //define GetArtistName()
    return artistName;
}

int PlaylistNode::GetSongLength(){ //define GetSongLength()
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext(){ //define GetNext()
   return nextNodePtr;
}
      
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr){ //define InsertAfter(PlaylistNode* nodePtr)
   PlaylistNode* tmp = nextNodePtr;
   nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmp;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr){ //define SetNext(PlaylistNode* nodePtr)
   nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode(){ //define PrintPlaylistNode()
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
