#ifndef ITEMS_H
#define ITEMS_H
#include <iostream>
#include <cstring>

class Item {
 public:
    Item();
    Item(const char* newTitle);
    virtual char* getTitle();
 private:
    char title[150];
};
#endif
