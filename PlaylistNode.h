#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
#include <string>
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
  PlaylistNode(string uniqueID, string songName, string artistName, int songLength);

  string GetID();
  string GetSongName();
  string GetArtistName();
  int GetSongLength();
  PlaylistNode* GetNext();

  void InsertAfter(PlaylistNode* nodePtr);
  void SetNext(PlaylistNode* nodePtr);
  void PrintPlaylistNode();
};

#endif
