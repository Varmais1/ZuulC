#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
#include <map>
/* Name: Ishaan Varma
   Date: 12/14/2022
   Purpose: Blueprint of the Room class.
*/
using namespace std;

class Room {
 public:
  //constructors
  Room();
  Room(char newTitle[40]);
  //sets an exit
  virtual void setExit(const char* direction, Room* accessible);
  //adds an item to the room
  virtual void addItem(Item* item);
  //takes an item from the room
  virtual Item* takeItem(char* itemName);
  //gets the rooms exits
  virtual map<const char*,Room*> getExits();
  //gets the items vector of the room
  virtual vector<Item*> getItems();
  //gets the name of the room
  virtual char* getTitle();
  //prints out all of the titles of the items in the room
  virtual void printItems();
 private:
  //holds the name of the room
  char title[40];
  //holds the valid exits of the room
  map<const char*,Room*> exits;
  //holds the items in the room.
  vector<Item*> items;
};
#endif
