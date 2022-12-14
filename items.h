#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>
/* Name: Ishaan Varma
   Date: 12/14/2022
   Purpose of this function: Bluepring of the Item class
*/
class Item {
 public:
  //constructors
  Item();
  Item(const char* newTitle);
  //gets the title of the item
  virtual char* getTitle();
 private:
  //holds the title of the item
  char title[150];
};
#endif
