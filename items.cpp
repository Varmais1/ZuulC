#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"

using namespace std;

Item::Item() {
  strcpy(title, "   ");
}

Item::Item(const char* newTitle) {
  strcpy(title, newTitle);
}

char* Item::getTitle() {
  return title;
}
