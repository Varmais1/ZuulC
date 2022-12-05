#include <iostream>
#include <cstring>
#include <vector>
#include "items.h"

using namespace std;

Item::Item() {
  strcpy(title, "   ");
}

Item::Item(char newTitle[40]) {
  strcpy(title, newTitle);
}
