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
   getline(cin, option); 
   if ( option == 'a' ) { 
     //add song 
   } 
   if ( option == 'b') { 
     // remove song 
   } 
   if (option == 'c') { 
     // change position - can skip 
      } 
   if (option == 's') { 
     // OutputByArtist
   } 
   if (option == 't') {
     // Output song time
   } 
   if (option == 'o') { 
     // Output full playlist 
   } 
   if (option == 'q' ) { 
     break; 
     // quit 
   } 
   
}

int main() {
   string playlistTitle; 
   cout << "Enter the playlist's title:" << endl; 
   getline(cin, playlistTitle);   
  PrintMenu(playlistTitle); 
   
   return 0;
}
}
