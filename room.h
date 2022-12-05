#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"
#include <map>

using namespace std;

class Room {
 public:
  Room();
  Room(char newTitle[40]);
  virtual void setExit(char* direction, Room* accessible);
  virtual void addItem(Item* item);
  virtual Item* takeItem(Item* item);
  char[] getTitle();
  map<char*,Room*> getExits();
  vector<Item*> getItems();
  char title[40];
  map<char*,Room*> exits;
  vector<Item*> items;
};
#endif
