#include <iostream>
#include "room.h"
#include <cstring>

using namespace std;

Room::Room() {
  strcpy(title, "    ");
}

Room::Room(char newTitle[150]) {
  strcpy(title, newTitle);
}

void Room::setExit(char* direction, Room* accessible) {
  exits.insert(pair<char*,Room*>(direction,accessible));
}

void Room::addItem(Item* item) {
  items.push_back(item);
}

Item* Room::takeItem(Item* item) {
  for(auto i = items.begin(); i != items.end(); i++) {
    if(strcmp((*i)->title,item->title) == 0) {
      Item* output = *i;
      items.erase(i);
      return output;
    }
  }
  cout << "This item is not in this room, or it is not found in this campus, or it does not exist!" << endl;
  return nullptr;
}




  
