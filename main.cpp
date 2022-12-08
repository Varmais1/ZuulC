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
  map<const char*, Room*> currentExits;
  vector<Item*> Inventory;
  char roomName[40];
  char itemName[40];
  strcpy(roomName, "Entrance");
  strcpy(itemName, "flask");
  Room* entrance = new Room(roomName);
  currentRoom = entrance;


  Item* flask = new Item(itemName);
  entrance->addItem(flask);


  strcpy(roomName, "Lab");
  Room* lab = new Room(roomName);
  entrance->setExit(north, lab);
  lab->setExit(south, entrance);


  strcpy(roomName, "Track");
  Room* track = new Room(roomName);
  entrance->setExit(south,track);
  track->setExit(north,entrance);


  strcpy(roomName, "Upper Forum");
  Room* upperforum = new Room(roomName);
  entrance->setExit(west, upperforum);
  upperforum->setExit(east, entrance);


  strcpy(roomName, "Lower Forum");
  Room* lowerforum = new Room(roomName);
  entrance->setExit(east, lowerforum);
  lowerforum->setExit(west, entrance);


  strcpy(roomName, "Upper Commons");
  Room* uppercommons = new Room(roomName);
  lab->setExit(west, uppercommons);
  uppercommons->setExit(east, lab);
  upperforum->setExit(north, uppercommons);
  uppercommons->setExit(south, upperforum);


  strcpy(roomName, "Gym");
  Room* gym = new Room(roomName);
  track->setExit(west, gym);
  gym->setExit(east, track);
  upperforum->setExit(south, gym);
  gym->setExit(north,upperforum);

  strcpy(roomName, "Lower Commons");
  Room* lowercommons = new Room(roomName);
  lab->setExit(east, lowercommons);
  lowercommons->setExit(west, lab);
  lowerforum->setExit(north, lowercommons);
  lowercommons->setExit(south, lowerforum);


  strcpy(roomName, "Field");
  Room* field = new Room(roomName);
  field->setExit(west, track);
  track->setExit(east, field);
  field->setExit(north, lowerforum);
  lowerforum->setExit(south, field);

  strcpy(roomName, "Cafeteria");
  Room* cafeteria = new Room(roomName);
  uppercommons->setExit(west, cafeteria);
  cafeteria->setExit(east, uppercommons);

  strcpy(roomName, "Bathroom");
  Room* bathroom = new Room(roomName);
  gym->setExit(west, bathroom);
  bathroom->setExit(east, gym);

  strcpy(roomName, "Library");
  Room* library = new Room(roomName);
  field->setExit(east, library);
  library->setExit(west, field);

  strcpy(roomName, "Theatre");
  Room* theatre = new Room(roomName);
  lowercommons->setExit(east, theatre);
  theatre->setExit(west, lowercommons);

  strcpy(roomName, "Pub");
  Room* pub = new Room(roomName);
  cafeteria->setExit(south, pub);
  pub->setExit(north, cafeteria);
  upperforum->setExit(west, pub);
  pub->setExit(east, upperforum);
  bathroom->setExit(north, pub);
  pub->setExit(south,bathroom);


  strcpy(roomName, "Office");
  Room* office = new Room(roomName);
  lowerforum->setExit(east, office);
  office->setExit(west, lowerforum);
  library->setExit(north, office);
  office->setExit(south, library);
  theatre->setExit(south, office);
  office->setExit(north, theatre);
  
  currentRoom = entrance;
  currentExits = entrance->getExits();

    
  bool run = true;
  char command[40];
  while(run == true) {
    cout << endl;
    cout << "You are currently in the " << currentRoom->getTitle() << "." << endl;
    for(auto itr = currentExits.begin(); itr != currentExits.end(); itr++) {
      cout << "To the " << itr->first << " there is the " << (*itr->second).getTitle() << "." << endl;
    }
    cout << "Type in quit in order to stop the program." << endl;
    cin.get(command,40);
    cin.ignore();
    lowercase(command);
    if(strcmp(command, "quit") == 0) {
      run = false;
    }
    else if(strcmp(command,north) == 0) {
      bool exists = false;
      for(auto itr = currentExits.begin(); itr != currentExits.end(); itr++) {
	if(strcmp(itr->first,north) == 0) {
	  currentRoom = itr->second;
	  currentExits = itr->second->getExits();
	  exists = true;
	  break;
	}
      }
      if(exists == false) {
	cout << "There is no room that is directly north of this room." << endl;
      }
    }
    else if(strcmp(command,south) == 0) {
      bool exists = false;
      for(auto itr = currentExits.begin(); itr != currentExits.end(); itr++) {
	if(strcmp(itr->first, south) == 0) {
	  currentRoom = itr->second;
	  currentExits = itr->second->getExits();
	  exists = true;
	  break;
        }
      }
      if(exists == false) {
	cout << "There is no room that is directly south of this room." << endl;
      }
    }
    else if(strcmp(command, west) == 0) {
      bool exists = false;
      for(auto itr = currentExits.begin(); itr != currentExits.end(); itr++) {
	if(strcmp(itr->first, west) == 0) {
	  currentRoom = itr->second;
	  currentExits = itr->second->getExits();
	  exists = true;
	  break;
	}
      }
      if(exists == false) {
	cout << "There is no room that is directly west of this room." << endl;
      }
    }
    else if(strcmp(command, east) == 0) {
      bool exists = false;
      for(auto itr = currentExits.begin(); itr != currentExits.end(); itr++) {
	if(strcmp(itr->first, east) == 0) {
	  currentRoom = itr->second;
	  currentExits = itr->second->getExits();
	  exists = true;
	  break;
	}
      }
      if(exists == false) {
	cout << "There is no room that is directly east of this room." << endl;
      }
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
