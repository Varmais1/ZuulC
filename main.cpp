#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "items.h"
#include <map>

void lowercase(char sentence[]);


int main() {
  Room* currentRoom;
  vector<Item*> Inventory;
  char roomName[40];
  char itemName[40];
  strcpy(roomName, "Entrance");
  strcpy(itemName, "flask");
  Room* entrance = new Room(roomName);
  Item* flask = new Item(itemName);
  entrance->addItem(flask);
  bool run = true;
  char command[40];
  while(run == true) {
    cout << "Type in quit in order to stop the program." << endl;
    cin.get(command,40);
    cin.ignore();
    lowercase(command);
    if(strcmp(command, "quit") == 0) {
      run = false;
    }

  }
  return 0;
}


//makes every letter in a string lowercase, also gets rid of all special characters
void lowercase(char sentence[]) {
  //iterating variable
   int i = 0;
   //go through the char array
   while(true) {
     int charVal = (int) sentence[i];
     //if the letter is capital, make it lowercase using ASCII
     if(65<=charVal && charVal <= 90) {
       sentence[i] = (char)(charVal+32);
     }
     //if the character is the null character, 
     else if(sentence[i] == '\0') {
       break;
     }
     //increment the variable
     i++;
   }

   
 }
