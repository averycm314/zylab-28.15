//URL for Github repository: 
//Team member 1: Avery Morris - averycm314
//Team member 2: Claire Fitzgerald - clairefitzgerald

#include <iostream> 
using namespace std; 

int main() { 

 void PrintMenu(string playlistTitle) {
   cout << endl << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl;
   
}
PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
    if (option == 'a') {
      string userID;
      string userSong;
      string userArtist;
      int userSongLength;
      
      if (headNode == nullptr)
         headNode = new PlaylistNode();
      
      PlaylistNode* currentNode = nullptr;
      PlaylistNode* lastNode = headNode;
      
      while (lastNode->GetNext() != nullptr) {
         lastNode = lastNode->GetNext();
      }

      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      getline(cin, userID);
      
      cout << "Enter song's name:" << endl;
      getline(cin, userSong);
      
      cout << "Enter artist's name:" << endl;
      getline(cin, userArtist);
      
      cout << "Enter song's length (in seconds):" << endl;
      cin >> userSongLength;

      currentNode = new PlaylistNode(userID, userSong, userArtist, userSongLength);
      lastNode->InsertAfter(currentNode);
   }

   if (option == 'd') {
      cout << "REMOVE SONG" << endl;
      string removeID;
      cout << "Enter song's unique ID:" << endl;
      cin >> removeID;
   
      PlaylistNode* previousNode = nullptr;
      PlaylistNode* currentNode = headNode;
   
      while (currentNode != nullptr && currentNode->GetID() != removeID) {
         previousNode = currentNode;
         currentNode = currentNode->GetNext();
      }
   
      if (currentNode == nullptr)
         cout << "\"" << removeID << "\" not found." << endl;
      else {
         if (previousNode != nullptr)
            previousNode->SetNext(currentNode->GetNext());
         else
            headNode = currentNode->GetNext();
   
         cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
         delete currentNode;
      }
   }


   if (option == 'c') {
      int currPos;
      int newPos;
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> currPos;
      cout << "Enter new position for song:" << endl;
      cin >> newPos;

      if (currPos < 1 || newPos < 1) {
         cout << "Invalid positions. Positions must be greater than or equal to 1." << endl;
      } else {
         PlaylistNode* previousNode = nullptr;
         PlaylistNode* currentNode = headNode;
         int currentPosition = 1;

         while (currentNode != nullptr && currentPosition != currPos) {
            previousNode = currentNode;
            currentNode = currentNode->GetNext();
            currentPosition++;
         }

         if (currentNode == nullptr) {
            cout << "Invalid current position. Song not found." << endl;
         } else {
            if (previousNode != nullptr) {
               previousNode->SetNext(currentNode->GetNext());
            } else {
               headNode = currentNode->GetNext();
            }

            currentPosition = 1;
            PlaylistNode* insertPrevious = nullptr;
            PlaylistNode* insertNext = headNode;

            while (insertNext != nullptr && currentPosition != newPos) {
               insertPrevious = insertNext;
               insertNext = insertNext->GetNext();
               currentPosition++;
            }

            if (insertPrevious != nullptr) {
               insertPrevious->InsertAfter(currentNode);
            } else {
               currentNode->SetNext(headNode);
               headNode = currentNode;
            }

            cout << "\"" << currentNode->GetSongName() << "\" moved to position " << newPos << endl;
         }
      }
   }

   if (option == 's') {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      string artistName;
      cout << "Enter artist's name:" << endl;
      getline(cin, artistName);

      int i = 1;
      PlaylistNode* currentNode = headNode;
      currentNode = currentNode->GetNext();
      while (currentNode != nullptr) {
         if (currentNode->GetArtistName() == artistName) {
            cout << endl << i << "." << endl;
            currentNode->PrintPlaylistNode();
         }
         i++;
         currentNode = currentNode->GetNext();
      }
   }
   if (option == 't') {
      cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
      int ttime = 0;
      PlaylistNode* currentNode = headNode;

      while (currentNode != nullptr) {
         ttime += currentNode->GetSongLength();
         currentNode = currentNode->GetNext();
      }

      cout << "Total time: " << ttime << " seconds" << endl;
   }

   if (option == 'o') {
      cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
      if (headNode == nullptr) {
         cout << "Playlist is empty" << endl;
      } 
      else {
         int i = 1;
         PlaylistNode* currentNode = headNode;
         currentNode = currentNode->GetNext();
         while (currentNode != nullptr) {
            cout << i << "." << endl;
            currentNode->PrintPlaylistNode();
            currentNode = currentNode->GetNext();
            i++;
            if (currentNode != nullptr)
               cout << endl;
         }
      }
   }

   return headNode;
}
   
}

int main() {
   string playlistTitle;
   char choice;
   PlaylistNode* headNode = nullptr;
   
   cout <<"Enter playlist's title:" << endl;
   getline(cin, playlistTitle);

   do{
      PrintMenu(playlistTitle);
      cout << endl << "Choose an option:" << endl;
      cin >> choice;
      cin.ignore();
      
      headNode = ExecuteMenu(choice, playlistTitle, headNode);
   } while(choice != 'q');
   
   return 0;
}
