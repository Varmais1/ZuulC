#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>

class Item {
 public:
  Item();
  Item(char newTitle[40]);
  char title[150];
};
#endif
