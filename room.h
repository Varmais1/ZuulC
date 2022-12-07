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
  virtual void setExit(const char* direction, Room* accessible);
  virtual void addItem(Item* item);
  virtual Item* takeItem(Item* item);
  virtual map<const char*,Room*> getExits();
  virtual vector<Item*> getItems();
  virtual char* getTitle();
 private:
  char title[40];
  map<const char*,Room*> exits;
  vector<Item*> items;
};
#endif
