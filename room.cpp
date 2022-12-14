#include <iostream>
#include "room.h"
#include <cstring>
#include <vector>
/* Name: Ishaan Varma
   Date:12/14/2022
   Purpose: Where the functions of the Room class are implemented
*/

using namespace std;
//default constructor
Room::Room() {
  strcpy(title, "    ");
}
//constructor
Room::Room(char newTitle[150]) {
  strcpy(title, newTitle);
}
//adds an exit to the exits map by inserting a pair that contains a const char* anda room*
void Room::setExit(const char* direction, Room* accessible) {
  exits.insert(pair<const char*,Room*>(direction,accessible));
}
//adds an item to the items vector
void Room::addItem(Item* item) {
  items.push_back(item);
}
//if the room has the item, return the item and erase it from the items vector, and notify if the item is not in this room if it is not
Item* Room::takeItem(char* itemName) {
  for(auto i = items.begin(); i != items.end(); i++) {
    if(strcmp(itemName, (*i)->getTitle()) == 0) {
      Item* output = *i;
      items.erase(i);
      return output;
    }
  }
  cout << "This item is not in this room, or it is not found in this campus, or it does not exist!" << endl;
  return nullptr;
}
//returns the vector of all of the items in the room.
vector<Item*> Room::getItems() {
  return items;
}
//returns the exits map
map<const char*,Room*> Room::getExits() {
  return exits;
}
//returns the name of the room
char* Room::getTitle() {
  return title;
}
//prints out all of the items in the room by looping through the items vector with an iterator and outputing the title.
void Room::printItems() {
  for(auto itr = items.begin(); itr!= items.end(); itr++) {
    cout << (*itr)->getTitle() << "\t";
  }

}
