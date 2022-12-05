#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "items.h"
#include <map>


int main() {
  Room* currentRoom;
  Room* entrance = new Room("Entrance");
  Item* flask = new Item("flask");
  entrance->addItem(flask);
  return 0;
}
