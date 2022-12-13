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
const char look[5] = {'l','o','o','k','\0'};
const char take[5] = {'t','a','k','e','\0'};
const char drop[5] = {'d','r','o','p','\0'};



void lowercase(char sentence[]);

int main() {
  Room* currentRoom;
  map<const char*, Room*> currentExits;
  vector<Item*> Inventory;
  char roomName[40];
  char itemName[150];
  strcpy(roomName, "Entrance");
  strcpy(itemName, "Backpack");
  Room* entrance = new Room(roomName);
  currentRoom = entrance;


  Item* backpack = new Item(itemName);
  Inventory.push_back(backpack);

  strcpy(itemName, "Security Card");
  Item* secCard = new Item(itemName);
  entrance->addItem(secCard);

  strcpy(roomName, "Lab");
  Room* lab = new Room(roomName);
  entrance->setExit(north, lab);
  lab->setExit(south, entrance);
  strcpy(itemName, "Computer");
  Item* computer = new Item(itemName);
  lab->addItem(computer);

  strcpy(roomName, "Track");
  Room* track = new Room(roomName);
  entrance->setExit(south,track);
  track->setExit(north,entrance);
  strcpy(itemName, "QR Code Sticker");
  Item* qrCode = new Item(itemName);
  track->addItem(qrCode);


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
  strcpy(itemName, "Phone");
  Item* phone = new Item(itemName);
  uppercommons->addItem(phone);

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
  strcpy(itemName, "USB");
  Item* USB = new Item(itemName);
  library->addItem(USB);

  strcpy(roomName, "Theatre");
  Room* theatre = new Room(roomName);
  lowercommons->setExit(east, theatre);
  theatre->setExit(west, lowercommons);
  strcpy(itemName, "Projector");
  Item* projector = new Item(itemName);
  theatre->addItem(projector);
  
  strcpy(roomName, "Pub");
  Room* pub = new Room(roomName);
  cafeteria->setExit(south, pub);
  pub->setExit(north, cafeteria);
  upperforum->setExit(west, pub);
  pub->setExit(east, upperforum);
  bathroom->setExit(north, pub);
  pub->setExit(south,bathroom);
  strcpy(itemName, "Student ID");
  Item* studentID = new Item(itemName);
  pub->addItem(studentID);

  

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
  bool hasComputer = false;
  bool hasBackpack = false;
  bool hasStudentID = false;
  bool hasSecurityCard = false;
  bool hasUSB = false;

  cout << "You are in a school, and you need to check your personal email to know where to go after school." << endl;
  cout << "The school only allows school emails to be accessed on school computers, and you need to use a special computer to access your email." << endl;
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
    else if(strcmp(command, look) == 0) {
      currentRoom->printItems();
    }
    else if(strcmp(command, take)==0) {
      cout << "Which item would you like to take?" << endl;
      cin.get(itemName, 150);
      cin.ignore();
      Item* temp = currentRoom->takeItem(itemName);
      if(temp != nullptr) {
	Inventory.push_back(temp);
      }
    }
    else if(strcmp(command, drop) == 0) {
      cout << "Which item would you like to drop?" << endl;
      cin.get(itemName,150);
      cin.ignore();
      bool haveItem = false;
      for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
	if(strcmp((*i)->getTitle(), itemName) == 0) {
	  currentRoom->addItem(*i);
	  Inventory.erase(i);
	  haveItem = true;
	  break;
	}
      }
      if(haveItem == false) {
	cout << "You do not have that item." << endl;
      }
      
    }
    if(hasSecurityCard == false) {
    for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
      if(strcmp((*i)->getTitle(), "Security Card") == 0) {
	hasSecurityCard = true;
      }
    }
    }
    if(hasBackpack == false) {
      for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
	if(strcmp((*i)->getTitle(), "Backpack") == 0) {
	  hasBackpack = true;
	}
      }
    }
    if(hasStudentID == false) {
      for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
	if(strcmp((*i)->getTitle(), "Student ID") == 0) {
	  hasStudentID = true;
	}
      }
    }
    if(hasComputer == false) {
      for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
	if(strcmp((*i)->getTitle(), "Computer") == 0) {
	  hasComputer = true;
	}
      }
    }
    if(hasUSB == false) {
      for(auto i = Inventory.begin(); i != Inventory.end(); i++) {
	if(strcmp((*i)->getTitle(), "USB") == 0) {
	  hasUSB = true;
	}
      }
    }
    if(hasSecurityCard && hasBackpack && hasStudentID && hasComputer && hasUSB && strcmp(currentRoom->getTitle(), lab->getTitle()) == 0) {
      cout << "You have now successfully signed into your email." << endl;
      cout << "Unfortunately, you just now remembered that you did not have anything after school, and head home." << endl;
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
