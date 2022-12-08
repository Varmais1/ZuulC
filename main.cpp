#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "items.h"
#include <map>

const char north[6] = {'n','o','r','t','h','\0'};
const char south[6] = {'s','o','u','t','h','\0'};
const char east[5] = {'e','a','s','t','\0'};
const char west[5] = {'w','e','s','t','\0'};

void lowercase(char sentence[]);

int main() {
  Room* currentRoom;
  vector<Item*> Inventory;
  char roomName[40];
  char itemName[40];
  strcpy(roomName, "Entrance");
  strcpy(itemName, "flask");
  Room* entrance = new Room(roomName);
  currentRoom = entrance;
  Item* flask = new Item(itemName);
  entrance->addItem(flask);
  strcpy(roomName, "lab");
  Room* lab = new Room(roomName);
  entrance->setExit(north, lab);
  lab->setExit(south, entrance);
  strcpy(roomName, "track");
  Room* track = new Room(roomName);
  entrance->setExit(south,track);
  track->setExit(north,entrance);
  strcpy(roomName, "upperforum");
  Room* upperforum = new Room(roomName);
  entrance->setExit(west, upperforum);
  upperforum->setExit(east, entrance);
  strcpy(roomName, "lowerforum");
  Room* lowerforum = new Room(roomName);
  entrance->setExit(east, lowerforum);
  lowerforum->setExit(west, entrance);
  strcpy(roomName, "uppercommons");
  Room* uppercommons = new Room(roomName);
  lab->setExit(west, uppercommons);
  uppercommons->setExit(east, lab);
  upperforum->setExit(north, uppercommons);
  uppercommons->setExit(south, upperforum);
  strcpy(roomName, "gym");
  Room* gym = new Room(roomName);
  track->setExit(west, gym);
  gym->setExit(east, track);
  upperforum->setExit(south, gym);
  gym->setExit(north,upperforum);




    
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
