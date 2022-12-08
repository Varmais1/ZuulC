#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>

class Item {
 public:
    Item();
    Item(char newTitle[150]);
    virtual char* getTitle();
 private:
    char title[150];
};
#endif
